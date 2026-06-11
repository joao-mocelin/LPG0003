#include <stdio.h>
#include <stdlib.h>

int main(){
    //Como criar uma matriz dinamica?
    int linhas = 3, colunas = 3;
    int** p2; //ponteiro que aponta para endereços de ponteiros
    p2 = malloc(sizeof(int*) * linhas); //numero de linhas da matriz
    for(int i = 0; i < linhas ; i++){ //alocando as colunas
        p2[i] = malloc(sizeof(int) * colunas);
    }
    for(int i = 0; i < linhas; i++){
        free(p2[i]);
    }
    free(p2);
    return 0;
}
