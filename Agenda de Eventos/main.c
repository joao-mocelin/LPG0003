#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct Data
{
    int dia;
    int mes;
    int ano;
};

struct Horario
{
    int hora;
    int minuto;
};

struct Evento
{
    struct Data data_evento;
    struct Horario horario_inicio;
    struct Horario horario_fim;
    char descricao[51];
    char local[51];
};

void mostra_eventos(struct Evento *v,int nv){
    if(nv == 0){
        printf("\nNao ha eventos cadastrados.\n");
        return;
    }
    for(int i = 0; i < nv; i++){
        printf("\nData: %02d %02d %04d", v[i].data_evento.dia, v[i].data_evento.mes, v[i].data_evento.ano);
        printf("\nHorario de Inicio: %02d:%02d", v[i].horario_inicio.hora, v[i].horario_inicio.minuto);
        printf("\nHorario de Termino: %02d:%02d", v[i].horario_fim.hora, v[i].horario_fim.minuto);
        printf("\nDescricao: %s", v[i].descricao);
        printf("\nLocal: %s\n", v[i].local);
    }
    return;
}

void salva_arquivo(struct Evento *v, FILE *file, int nv){
    fprintf(file, "%d\n",nv);
    for(int i = 0; i < nv; i++){
        fprintf(file,"%d %d %d\n",v[i].data_evento.dia,v[i].data_evento.mes,v[i].data_evento.ano);
        fprintf(file,"%d %d\n",v[i].horario_inicio.hora,v[i].horario_inicio.minuto);
        fprintf(file,"%d %d\n",v[i].horario_fim.hora,v[i].horario_fim.minuto);
        fprintf(file,"%s\n",v[i].descricao);
        fprintf(file,"%s\n",v[i].local);
    }
    printf("\nDados salvos com sucesso em 'eventos.txt'!\n");
}

struct Evento* cadastro(struct Evento *v,int *nv){
    struct Evento *temp = realloc(v,sizeof(struct Evento) * (*nv + 1));
    if(temp == NULL){
        printf("\nNao foi possivel realocar o vetor de eventos.\nRetornando o vetor original. . .");
        return v;
    }
    v = temp;
    printf("\nDigite dia mes e ano do novo evento (DD MM AAAA):\n");
    scanf("%d %d %d",&v[*nv].data_evento.dia,&v[*nv].data_evento.mes,&v[*nv].data_evento.ano);
    printf("\nDigite horario de inicio do evento (HH MM):\n");
    scanf("%d %d",&v[*nv].horario_inicio.hora,&v[*nv].horario_inicio.minuto);
    printf("\nDigite horario de termino do evento (HH MM):\n");
    scanf("%d %d",&v[*nv].horario_fim.hora,&v[*nv].horario_fim.minuto);
    printf("\nDigite a descricao do evento (max 50 caracteres):\n");
    scanf(" %50[^\n]",v[*nv].descricao);
    printf("\nDigite o local do evento (max 50 caracteres):\n");
    scanf(" %50[^\n]",v[*nv].local);
    (*nv)++;
    printf("\nEvento cadastrado com sucesso.");
    return v;
}

int main(){
    struct Evento *v = NULL;
    int n = 0, option = -1;
    FILE *arquivo;
    arquivo = fopen("eventos.txt","rt");
    if(arquivo == NULL){
        printf("\nAgenda nao encontrada.");
        Sleep(1500);
        system("CLS");
    }
    else{
        if (fscanf(arquivo, "%d\n", &n) != 1) { // quantidade de eventos, se o fscanf nao conseguir ler exatamente 1 dado "%d" ele informa que está corrompido o arquivo
            printf("\nErro: Arquivo corrompido (falha ao ler a quantidade de eventos).\n");
            n = 0;
            fclose(arquivo);
            Sleep(2000);
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
                Sleep(200);
                printf("\n.");
                Sleep(600);
                printf("\n. .");
                Sleep(600);
                printf("\n. . .");
                Sleep(400);
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
        printf("\n(1) - Cadastrar novo eventos.");
        printf("\n(2) - Mostrar Eventos.");
        printf("\n(3) - Pesquisar por data.");
        printf("\n(4) - Pesquisar por descricao.");
        printf("\n(5) - Remover Evento.");
        printf("\n(6) - Sair.\n");
        printf("-> ");
        scanf("%d",&option);
        if(!(option > 0 && option < 7)){
            printf("\nValor invalido! Favor selecionar uma opcao valida.");
            Sleep(2000);
            system("cls");
            continue;
        }

        switch (option) {
            case 1: //OK, implementar validação de data, horario.
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

            case 3:
                printf("\n[Pesquisar por data]\n");
                // Código de busca por data
                break;

            case 4:
                printf("\n[Pesquisar por descricao]\n");
                // Código de busca por descrição
                break;

            case 5:
                printf("\n[Remover Evento]\n");
                // Código para deletar um evento
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