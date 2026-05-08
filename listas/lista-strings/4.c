/*
 Escreva um programa que leia uma string e determina se a mesma é palíndrome, ou seja,
se forma a mesma sequência de caracteres quando lida de trás para frente. Ex.: ARARA.
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

int palindrome(char *str){
    int len = strlen(str);
    for(int i = 0; i <= len/2; i++){
        if(str[i] != str[len - i - 1]){
            return 0;
        }
    }
    return 1;
}

int main(){
    char string[99];
    printf("\nInsira a string\n");
    scanf(" %99[^\n]",string);
    if(palindrome(string) == 1){
        printf("\nA palavra %s eh palindromo.",string);
    }
    else{
        printf("\nA palavra %s nao eh palindromo.",string);
    }
    return 0;
}