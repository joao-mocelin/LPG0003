/*
Faça um programa que verifica se uma string contém somente dígitos decimais (0 a 9).
*/
#include <stdio.h>

int isNumber(char *str){
    for (int i = 2; str[i] != '\0'; i++)
    {
        if(str[i] < '0' || str[i] > '9'){
            return 0;
        }
    }
    return 1;    
}

int main(){
    char string[99];
    printf("\nInsira a string:\n");
    scanf(" %99[^\n]",string);
    if(isNumber(string) == 1){
        printf("\nA string %s so tem digitos",string);
    }
    else{
        printf("\nA string %s nao tem somente digitos",string);
    }
    return 0;
}