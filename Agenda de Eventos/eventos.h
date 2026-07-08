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

//funções auxiliares
//funções basicas data
int eh_bissexto( int ano );
int compara_data(struct Data x, struct Data y);
int valida_data( struct Data x );
//funções basicas horario
int compara_horario(struct Horario x, struct Horario y);
int horario_to_minutes(struct Horario x);
int valida_horario(struct Horario x);
int sobrepoe_horario(struct Evento *v, int n, struct Data nova_data, struct Horario novo_ini, struct Horario novo_fim);

//funções principais da agenda
struct Evento *remover_evento(struct Evento *v, int *nv);
struct Evento* cadastro(struct Evento *v, int *nv);
void pesquisa_data(struct Data data, struct Evento *v, int n);
void pesquisa_descricao(struct Evento *v, int n, char *descricao);
void mostra_eventos(struct Evento *v,int nv);

//funções de manipulação de arquivo
struct Evento *ordena_data(struct Evento *v, int n);
void salva_arquivo(struct Evento *v, FILE *file, int nv);