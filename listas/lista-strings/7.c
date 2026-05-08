/*
Escreva um programa que converta uma string que contém somente dígitos em um valor
inteiro (variável int).
*/
#include <stdio.h>
#include <math.h>

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

int converte(char *s){
    double somatorio = 0.0;
    for(int i = 0; s[i] != '\0'; i++){
        somatorio += (s[i]-48) * pow(10,strlen(s) - i - 1);
    }
    return (int)somatorio;
}

int main(){
    char string[99];
    scanf("%98[^\n]",string);
    if(isNumber(string) == 1){
        int somatorio = converte(string);
        printf("\nString = '%s' ou = %d",string,somatorio);
    }
    else{
        printf("num eh numero nao");
    }
    return 0;
}