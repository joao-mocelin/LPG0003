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

void somaMatriz(int l, int c, int matrizA[l][c], int matrizB[l][c], int matrizC[l][c]){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
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

int main(){
    srand(time(NULL));
    int matrizA[3][3], matrizB[3][3], matrizC[3][3];
    randMatriz(3,3,matrizA);
    printf("\nMatriz A = ");
    printMatriz(3,3,matrizA);
    randMatriz(3,3,matrizB);
    printf("\nMatriz B = ");
    printMatriz(3,3,matrizB);
    somaMatriz(3,3,matrizA,matrizB,matrizC);
    printf("\nMatriz C = ");
    printMatriz(3,3,matrizC);
    return 0;
}