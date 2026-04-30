#include <stdio.h>

int strlen(char *str){ //retorna o tamanho de uma string
    cont = 0;
    for(int i = 0; str[i] != '\0'; i++){
        cont += 1;
    }
    return cont;
}

void strcpy(char *str1, char *str2){//copia o conteúdo de uma string para outra
    for(int i = 0; str1[i] != '\0'; i++){
        str2[i] = str1[i];
    }
    str2[i] = '\0';
}

int strcmp(char *str1, char *str2){//compara duas strings e retorna 1 se forem iguais
    if(strlen(str1) != strlen(str2)){
        return 0;
    }
    for(int i = 0; str1[i] != 0; i++){
        if(str1[i] != str2[i]){
            return 0;
        }
    }
    if(str1[0] - str2[0] > 0){
        return 1;
    }
    if(str1[0] - str2[0] < 0){
        return -1;
    }
}





int main(){
    char nome[10];
    scanf("%s",nome);
    printf("\n %s",nome);
    return 0;
}