#include "eventos.h"

int main(){
    struct Evento *v = NULL;
    int n = 0, option = -1;
    FILE *arquivo;
    arquivo = fopen("eventos.txt","rt");
    if(arquivo == NULL){
        printf("\nAgenda nao encontrada.");
        Sleep(500);
        system("CLS");
    }
    else{
        if (fscanf(arquivo, "%d\n", &n) != 1) { // quantidade de eventos, se o fscanf nao conseguir ler exatamente 1 dado "%d" ele informa que está corrompido o arquivo
            printf("\nErro: Arquivo corrompido (falha ao ler a quantidade de eventos).\n");
            n = 0;
            fclose(arquivo);
            Sleep(500);
            system("CLS");
        }
        else if(n > 0){
            v = malloc( sizeof( struct Evento) * n );
            int arquivo_valido = 1; //se o arquivo estiver corretamente escrito, mantém em 1, caso esteja corrompido em algum campo, muda para 0.
            for(int i = 0 ; i < n ; i++ ){
                if(fscanf(arquivo, "%d %d %d\n", &v[i].data_evento.dia, &v[i].data_evento.mes, &v[i].data_evento.ano) != 3){
                    arquivo_valido = 0;
                    break;
                }
                if(fscanf(arquivo, "%d %d\n", &v[i].horario_inicio.hora, &v[i].horario_inicio.minuto)!= 2){
                    arquivo_valido = 0;
                    break;
                }
                if(fscanf(arquivo, "%d %d\n", &v[i].horario_fim.hora, &v[i].horario_fim.minuto)!= 2){
                    arquivo_valido = 0;
                    break;
                }
                if(fscanf(arquivo, " %[^\n]\n", v[i].descricao) != 1){
                    arquivo_valido = 0;
                    break;
                }
                if(fscanf(arquivo, " %[^\n]\n", v[i].local)!= 1){
                    arquivo_valido = 0;
                    break;
                }
            }
            fclose(arquivo);
            if(arquivo_valido == 0){
                printf("\nErro: O arquivo esta corrompido.");
                printf("\nInicializando agenda vazia por seguranca.");
                free(v);
                v = NULL;
                n = 0;
                Sleep(300);
                printf("\n.");
                Sleep(300);
                printf("\n. .");
                Sleep(300);
                printf("\n. . .");
                Sleep(300);
                system("cls");
            }
            else{
                if(n == 1){
                    printf("%d evento encontrado e carregado.\n",n);
                }
                else{
                    printf("%d eventos encontrados e carregados.\n", n);
                }
                Sleep(500);
                system("cls");
            }
        }
        else{ //caso n = 0
            fclose(arquivo);
            printf("Agenda vazia (0 eventos encontrados).\n");
            Sleep(500);
            system("cls");
        }
	}
    
    //carga de arquivo e leitura de dados ok.
    //prosseguir para menu seletor e funcionalidades.

    while(option != 6){
        printf("\n------------------------------");
        printf("\n\t Agenda de Eventos\n");
        printf("\n(1) - Cadastrar novo evento.");
        printf("\n(2) - Mostrar Eventos.");
        printf("\n(3) - Pesquisar por data.");
        printf("\n(4) - Pesquisar por descricao.");
        printf("\n(5) - Remover Evento.");
        printf("\n(6) - Sair.\n");
        printf("-> ");
        scanf("%d",&option);
        while (getchar() != '\n'); // Consome o lixo do buffer caso nao seja numeral
        if(!(option > 0 && option < 7)){
            printf("\nValor invalido! Favor selecionar uma opcao valida.");
            Sleep(1000);
            system("cls");
            continue;
        }

        switch (option) {
            case 1: //OK
                printf("\n[Cadastrar novo evento]\n");
                v = cadastro(v,&n);
                printf("\n");
                system("pause");
                break;

            case 2: //OK
                printf("\n[Mostrar Eventos]\n");
                mostra_eventos(v,n);
                printf("\n");
                system("PAUSE");
                break;

            case 3:{
                if(n == 0){
                    printf("\nNao ha eventos cadastrados.\n");
                    system("pause");
                    break;
                }
                printf("\n[Pesquisar por data]\n");
                struct Data data_busca; // Agora o compilador aceita!
                
                do {
                    printf("Digite a data que deseja pesquisar (DD MM AAAA): ");
                    scanf("%d %d %d", &data_busca.dia, &data_busca.mes, &data_busca.ano);
                } while (valida_data(data_busca) != 1);

                pesquisa_data(data_busca, v, n);
                
                printf("\n");
                system("pause");
                break;
            }

            case 4:{
                if(n == 0){
                    printf("\nNao ha eventos cadastrados.\n");
                    system("pause");
                    break;
                }
                printf("\n[Pesquisar por descricao]\n");
                char termo_busca[51];
                printf("Digite o termo ou palavra-chave que deseja buscar: ");
                scanf(" %50[^\n]", termo_busca); 
                pesquisa_descricao(v, n, termo_busca);
                printf("\n");
                system("pause");
                break;
            }

            case 5:
                system("cls");
                printf("\n[Remover Evento]\n");
                v = remover_evento(v,&n);
                printf("\n");
                system("pause");
                break;

            case 6: //OK.
                arquivo = fopen("eventos.txt","wt");
                salva_arquivo(v,arquivo,n);
                fclose(arquivo);
                printf("\nSaindo do programa... Ate logo!\n");
                break;
        }

        Sleep(500); 
        system("cls");
    }

    free(v);
    return 0;
}