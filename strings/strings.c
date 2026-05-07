#include <stdio.h>
#include <string.h>

int len(char *str){ //retorna o tamanho de uma string
    int cont = 0;
    for(int i = 0; str[i] != '\0'; i++){
        cont += 1;
    }
    return cont;
}

void cpy(char *str1, char *str2){//copia o conteúdo de uma string para outra
    int i = 0;
    for(i = 0; str1[i] != '\0'; i++){
        str2[i] = str1[i];
    }
    str2[i] = '\0';
}

int cmp(char *str1, char *str2){//compara duas strings e retorna 1 se forem iguais
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

void cat(char *str1, char *str2){//concatena duas strings
    int i;
    for(i = strlen(str1); i < strlen(str2); i++){
        str1[i] = str2[i-strlen(str2)];
    }
    str1[i] = '\0';
}



int main(){
    char nome[99], nome2[99];
    fgets(nome,99,stdin);
    fgets(nome2,99,stdin);
    strcat(nome,nome2);
    printf("\n%s",nome);
    return 0;
}