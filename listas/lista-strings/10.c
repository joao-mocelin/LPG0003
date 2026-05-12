/*Escreva uma função que inverte a ordem dos caracteres de uma string.
*/
#include <stdio.h>

int strlen(char *str){
    int cont = 0;
    for(int i = 0; str[i] != '\0'; i++){
        cont++;
    }
    return cont;
}

void inverte(char *str){
    int n = strlen(str) - 1;
    char aux;
    for(int i = 0; i < n; i++){
        aux = str[i];
        str[i] = str[n];
        str[n] = aux;
        n--;
    }
}

int main(){
    char string[99];
    printf("\nInsira a string:\n");
    scanf(" %98[^\n]",string);
    inverte(string);
    printf("\n%s",string);
    return 0;
}