/*
Faça um programa que leia uma cadeia de caracteres e converta todos os caracteres que
forem letras minúsculas para letras maiúsculas. Dica: é preciso fazer uma subtração no
código do caractere. Verifique na tabela ASCII e veja qual valor deve ser usado.
*/
#include <stdio.h>

void converte(char *str){
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] >= 97 && str[i] <= 122){
            str[i] = str[i] - 32;
        }
    }
}

int main(){
    char string[99];
    printf("\nInsira a string:\n");
    scanf(" %99[^\n]",string);
    converte(string);
    printf("\nString nova = '%s'",string);
    return 0;
}