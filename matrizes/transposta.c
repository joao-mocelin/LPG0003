#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randMatriz(int l, int c, int matriz[l][c]){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            matriz[i][j] = rand() % 99 + 1;
        }
    }
}

void printMatriz(int l, int c, int matriz[l][c]){
    printf("\n");
    for(int i = 0; i < l; i++){
        printf("|");
        for(int j = 0; j < c; j++){
            printf("\t%d",matriz[i][j]);
        }
        printf("\t|\n");
    }
}

void transporMatriz(int l, int c, int m[l][c], int t[c][l]){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            t[i][j] = m[j][i];
        }
    }
}

int main(){
    int m[3][3];
    int mTransposta[3][3];
    randMatriz(3,3,m);
    randMatriz(3,3,mTransposta);
    printf("\n Matriz = ");
    printMatriz(3,3,m);
    transporMatriz(3,3,m,mTransposta);
    printf("\n Matriz transposta = ");
    printMatriz(3,3,mTransposta);
    return 0;
}