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

int main(){
    struct Evento *v = NULL;
    int n = 0, opcao = -1;
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
                Sleep(1500);
                system("cls");
            }
        }
        else{ //caso n = 0
            fclose(arquivo);
            printf("Agenda vazia (0 eventos encontrados).\n");
            Sleep(1500);
            system("cls");
        }
	}
    
    //carga de arquivo e leitura de dados ok.
    //prosseguir para menu seletor e funcionalidades.

    return 0;
}