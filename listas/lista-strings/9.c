/*
Escreva uma função remove todos os espaços no início e no final de uma string (processo
é chamado de trimming). Protótipo:
void trim( char srt[] );
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

void trim(char *str){
    int i = 0, j = 0;
    for(i = 0; str[i] == ' '; i++){
        for(j = i ; str[j] != '\0'; j++){
            str[j] = str[j+1];
        }
        i--;
    }
    for(int k = strlen(str) - 1; k > 0 && str[k] == ' '; k--){
        str[k] = '\0';
    }

}

int main(){
    char string[99];
    printf("\nInsira a string: ");
    scanf(" %98[^\n]",string);
    trim(string);
    printf("\n%s",string);
    printf(".");
    return 0;
}