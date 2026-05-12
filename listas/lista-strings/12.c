/*
escreva uma função que implementa o comportamento da função strcmp(), ou seja, dadas
duas strings str1 e str2, a função deve comparar os conteúdos considerando a ordem
alfabética. Protótipo:
int compara( char str1[], char str2[] );*/
#include <stdio.h>

int strlen(char *str){
    int cont = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        cont++;
    }
    return cont;
}   

int compare(char *str1, char *str2){

    if(strlen(str1) == strlen(str2)){
        int bool = 1;
        for(int i = 0; str1[i] != '\0'; i++){
            if(str1[i] != str2[i]){
                bool = 0;
                break;
            }
        }
        if(bool == 1){
            return 0;
        }
    }
    for(int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++){
        if(str1[i] != str2[i]){
            if(str1[i] > str2[i]){
                return 1;
            }
            else{
                return -1;
            }
        }
    }
    return 0;
}

int main(){
    char string1[99] = "Abc";
    char string2[99] = "Abd";
    printf("%d",compare(string1,string2));
    return 0;
}