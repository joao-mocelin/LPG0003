/*
Escreva uma função que implementa o comportamento da função strcat(), ou seja, dadas
duas strings str1 e str2, a função deve concatenar as duas strings e o conteúdo deve ficar
em str1. Não utilize funções predefinidas. Protótipo:
void concatena( char str1[], char str2[] );
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

void concatena(char *str1, char *str2){
    int strlen1 = strlen(str1);
    int strlen2 = strlen(str2);
    for(int i = strlen1; i <= strlen1 + strlen2; i++ ){
        str1[i] = str2[i - strlen1];
    }
}

int main(){
    char string[99];
    printf("\nInsira a string:\n");
    scanf(" %98[^\n]",string);
    char string2[99];
    printf("\nInsira a string:\n");
    scanf(" %98[^\n]",string2); //NAO TIRA ESSE ESPÇAO CARA BUFFER SO DA B.O
    concatena(string,string2);
    printf("\n%s",string);
    return 0;
}