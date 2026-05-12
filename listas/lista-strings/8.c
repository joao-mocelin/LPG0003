/*
Escreva um programa que leia uma cadeia de caracteres no formato "DD/MM/AAAA" e
copie o dia, mês e ano para 3 variáveis inteiras. Antes disso, o programa deve verificar se o
formato está correto, ou seja, se as barras estão no lugar certo, e se D, M e A são dígitos.
*/
#include <stdio.h>

int strlen(char *str){
    int cont = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        cont++;
    }
    return cont;
}   

int isDate(char *str){
    if(strlen(str) != 10){
        return 0;
    }
    for(int i = 0; str[i] != '\0'; i++){
        if((str[i] < '0' || str[i] > '9') && str[i] != '/'){
            return 0;
        }
    }
    if(str[2] != '/' || str[5] != '/'){
        return 0;
    }
    return 1;
}

int converte(char *str, int inicio, int fim) {
    int resultado = 0;
    for (int i = inicio; i < fim; i++) {
        resultado = resultado * 10 + (str[i] - '0');
    }
    return resultado;
}

int main(){
    int dia, mes, ano;
    char str[11];
    scanf(" %11[^\n]", str);
    if(isDate(str) == 1){
        dia = converte(str,0,2);
        mes = converte(str,3,5);
        ano = converte(str,6,10);
    }
    printf("\n %02d/%02d/%04d",dia,mes,ano);
    return 0;
}