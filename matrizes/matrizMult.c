#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplica(int l1 , int c1, int m1[l1][c1],int c2, int m2[c1][c2], int m3[l1][c2]){
    for(int i = 0; i < l1; i++){
        for(int j = 0; j < c2; j++){
            int soma = 0;
            for(int k = 0; k < c1; k++){
                soma += m1[i][k] * m2[k][j];
            }
            m3[i][j] = soma;
        }
    }
}

void randMatriz(int l, int c, int matriz[l][c]){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            matriz[i][j] = rand() % 9 + 1;
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
    int m1[3][3], m2[3][3], m3[3][3];
    randMatriz(3,3,m1);
    randMatriz(3,3,m2);
    printf("\nMatriz 1 = ");
    printMatriz(3,3,m1);
    printf("\nMatriz 2 = ");
    printMatriz(3,3,m2);
    multiplica(3,3,m1,3,m2,m3);
    printf("\nMatriz Resultante");
    printMatriz(3,3,m3);
}