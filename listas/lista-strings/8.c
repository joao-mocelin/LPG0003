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

int isNumber(char *s){
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] < '0' || s[i] > '9'){
            return 0;
        }
    }
    return 1;
}

