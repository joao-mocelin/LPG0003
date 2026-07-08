#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

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

int eh_bissexto( int ano ){
	return ( ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0 ;
}

int valida_data( struct Data x ){
	if( x.ano < 2000 || x.ano > 2100 ){ // Arbitr�rio... pode ser mudado ou omitido.
		printf("Erro: ano deve estar entre 2000 e 2100!\n");
		return 0;
	}
	
	if( x.mes < 1 || x.mes > 12 ){
		printf("Erro: mes deve estar entre 1 e 12!\n");
		return 0;
	}
		
	int max, meses[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if( x.mes == 2 && eh_bissexto( x.ano ) )
		max = 29;
	else
		max = meses[ x.mes-1 ];
		
	if( x.dia < 1 || x.dia > max ){
		printf("Erro: dia deve estar entre 1 e %d!\n", max);
		return 0;
	}
		
	return 1;
	
}

int valida_horario(struct Horario x){
    if(x.hora < 0 || x.hora > 23){
        printf("\nInsira um horario de 0 e 23 hrs.");
        return 0;
    }
    if(x.minuto < 0 || x.minuto > 59){
        printf("\nInsira um horario de 0 e 59 min.");
        return 0;
    }
    return 1;
}

int compara_data(struct Data x, struct Data y){
    if(x.ano < y.ano){
        return 1; //x vem antes de y
    }
    if(x.ano > y.ano){
        return 0; //y vem antes de x
    }
    if(x.ano == y.ano){
        if(x.mes < y.mes){
            return 1; //x vem antes de y
        }
        if(x.mes > y.mes){
            return 0; //y vem antes de x
        }
        if(x.mes == y.mes){
            if(x.dia < y.dia){
                return 1; //x vem antes de y 
            }
            if(x.dia > y.dia){
                return 0; //y vem antes de x
            }
            if(x.dia == y.dia){
                return 2;// são no mesmo dia
            }
        }
    }
    return 1;
}

int horario_to_minutes(struct Horario x){
    int minuto = x.hora * 60 + x.minuto;
    return minuto;
}

int compara_horario(struct Horario x, struct Horario y){
    int min_x = horario_to_minutes(x);
    int min_y = horario_to_minutes(y);

    if (min_x < min_y) {
        return 1; // x vem antes de y
    }
    return 0; // y vem antes de x (ou são iguais)
}

int sobrepoe_horario(struct Evento *v, int n, struct Data nova_data, struct Horario novo_ini, struct Horario novo_fim) {
    int nov_ini_min = horario_to_minutes(novo_ini);
    int nov_fim_min = horario_to_minutes(novo_fim);

    for (int i = 0; i < n; i++) {
        if (v[i].data_evento.dia == nova_data.dia &&
            v[i].data_evento.mes == nova_data.mes &&
            v[i].data_evento.ano == nova_data.ano) {

            int ex_ini_min = horario_to_minutes(v[i].horario_inicio);
            int ex_fim_min = horario_to_minutes(v[i].horario_fim);

            if (nov_ini_min < ex_fim_min && nov_fim_min > ex_ini_min) {
                printf("\nERRO: O horario coincide com o evento: \"%s\" (%02d:%02d ate %02d:%02d).\n",
                       v[i].descricao, v[i].horario_inicio.hora, v[i].horario_inicio.minuto,
                       v[i].horario_fim.hora, v[i].horario_fim.minuto);
                return 1; // Encontrou sobreposição
            }
        }
    }
    return 0;
}

struct Evento *ordena_data(struct Evento *v, int n){
    if (n <= 1) return v; // n precisa ser ordenado
    int swap;
    struct Evento aux;
    for(int i = 0; i < n - 1; i++){
        swap = 0;
        for(int j = 0; j < n - i - 1; j++){
            if(compara_data(v[j].data_evento,v[j+1].data_evento) == 0){
            aux = v[j];
            v[j] = v[j+1];
            v[j+1] = aux;
            swap = 1;
            }
            else if(compara_data(v[j].data_evento,v[j+1].data_evento) == 2){
                if(compara_horario(v[j].horario_inicio,v[j+1].horario_inicio) == 0){
                    aux = v[j];
                    v[j] = v[j+1];
                    v[j+1] = aux;
                    swap = 1;
                }
            }
        }
        if(swap == 0){
            break;
        }
    }
    return v;
}

struct Evento* cadastro(struct Evento *v, int *nv){
    struct Data data_temp;
    struct Horario ini_temp, fim_temp;
    int valido;

    do{
        printf("\nDigite dia mes e ano do novo evento (DD MM AAAA):\n");
        scanf("%d %d %d", &data_temp.dia, &data_temp.mes, &data_temp.ano);
    } while (valida_data(data_temp) != 1);

    do{
        printf("\nDigite horario de inicio do evento (HH MM):\n");
        scanf("%d %d", &ini_temp.hora, &ini_temp.minuto);
        valido = valida_horario(ini_temp);
    } while(valido != 1);

    do{
        printf("\nDigite horario de termino do evento (HH MM):\n");
        scanf("%d %d", &fim_temp.hora, &fim_temp.minuto);
        
        if (valida_horario(fim_temp) == 0) {
            valido = 0;
            continue;
        }
        
        if (horario_to_minutes(fim_temp) <= horario_to_minutes(ini_temp)){
            printf("\nErro: O horario de termino nao pode ser menor ou igual ao de inicio!\n");
            valido = 0;
            continue;
        }
        valido = 1;
    } while (valido != 1);

    if (sobrepoe_horario(v, *nv, data_temp, ini_temp, fim_temp) == 1) {
        printf("\nCadastro cancelado devido ao conflito de horarios.\n");
        return v;
    }

    struct Evento *temp = realloc(v, sizeof(struct Evento) * (*nv + 1));
    if(temp == NULL){
        printf("\nNao foi possivel realocar o vetor de eventos.\nRetornando o vetor original. . .");
        return v;
    }
    v = temp;

    v[*nv].data_evento = data_temp;
    v[*nv].horario_inicio = ini_temp;
    v[*nv].horario_fim = fim_temp;

    printf("\nDigite a descricao do evento (max 50 caracteres):\n");
    scanf(" %50[^\n]", v[*nv].descricao);
    while (getchar() != '\n'); // Consome o lixo do buffer caso tenha mais de 50 caracteres
    
    printf("\nDigite o local do evento (max 50 caracteres):\n");
    scanf(" %50[^\n]", v[*nv].local);
    while (getchar() != '\n');

    (*nv)++;

    v = ordena_data(v, *nv); 
    
    printf("\nEvento cadastrado com sucesso e agenda ordenada.");
    return v;
}

void pesquisa_data(struct Data data, struct Evento *v, int n){
    int existe = 0;
    for(int i = 0; i < n; i++){
        if(compara_data(data,v[i].data_evento) == 2){
            printf("\nData: %02d %02d %04d", v[i].data_evento.dia, v[i].data_evento.mes, v[i].data_evento.ano);
            printf("\nHorario de Inicio: %02d:%02d", v[i].horario_inicio.hora, v[i].horario_inicio.minuto);
            printf("\nHorario de Termino: %02d:%02d", v[i].horario_fim.hora, v[i].horario_fim.minuto);
            printf("\nDescricao: %s", v[i].descricao);
            printf("\nLocal: %s\n", v[i].local);
            existe = 1;
        }
    }
    if(existe == 0){
        printf("\nNao ha eventos nesta data.");
    }
}

struct Evento *remover_evento(struct Evento *v, int *nv){
    int evento;
    if(*nv == 0){
        printf("\nNao ha eventos para serem removidos.");
        return v;
    }
    for(int i = 0; i < *nv; i++){
        printf("\n[%d] Data: %02d %02d %04d",i , v[i].data_evento.dia, v[i].data_evento.mes, v[i].data_evento.ano);
        printf("\nHorario de Inicio: %02d:%02d", v[i].horario_inicio.hora, v[i].horario_inicio.minuto);
        printf("\nHorario de Termino: %02d:%02d", v[i].horario_fim.hora, v[i].horario_fim.minuto);
        printf("\nDescricao: %s", v[i].descricao);
        printf("\nLocal: %s\n", v[i].local);
    }
    printf("\n Escolha um evento para ser removido:\n");
    scanf("%d",&evento);
    if(evento < 0 || evento >= *nv){
        printf("\nEscolha invalida.");
        return v;
    }
    for(int i = evento; i < (*nv) - 1; i++){
        v[i] = v[i+1];
    }
    (*nv)--;
    if(*nv == 0){
        free(v);
        printf("\nUltimo evento removido. A agenda agora esta vazia.\n");
        return NULL;
    }
    struct Evento *temp = realloc(v, sizeof(struct Evento) * (*nv));
    if(temp == NULL){
        printf("\nFalha ao reduzir tamanho da agenda.");
        return v;
    }
    v = temp;
    printf("\nEvento removido com sucesso.\n");
    return v;
}

void pesquisa_descricao(struct Evento *v, int n, char *descricao){
    char *ponteiro;
    int existe = 0;
    for(int i = 0; i < n; i++){
        ponteiro = strstr(v[i].descricao, descricao);
        if(ponteiro != NULL){
            printf("\nData: %02d %02d %04d", v[i].data_evento.dia, v[i].data_evento.mes, v[i].data_evento.ano);
            printf("\nHorario de Inicio: %02d:%02d", v[i].horario_inicio.hora, v[i].horario_inicio.minuto);
            printf("\nHorario de Termino: %02d:%02d", v[i].horario_fim.hora, v[i].horario_fim.minuto);
            printf("\nDescricao: %s", v[i].descricao);
            printf("\nLocal: %s\n", v[i].local);
            existe = 1;
        }
    }
    if(existe == 0){
        printf("\nNao ha eventos com esta descricao.");
    }
}

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