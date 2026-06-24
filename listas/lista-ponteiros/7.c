#include <stdio.h>

void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ){
    *pMin = mat[0][0];
    *pI = 0;
    *pJ = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            if(mat[i][j] < *pMin){
                *pMin = mat[i][j];
                *pI = i;
                *pJ = j;
            }
        }
    }
}

int main(){
    float mat[3][4];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("\nMatriz[%d][%d] = ",i,j);
            scanf("%f",&mat[i][j]);
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%.2f\t",mat[i][j]);
        }
        printf("\n");
    }
    float min;
    int index,Jindex;
    min_matriz(mat,&min,&index,&Jindex);
    printf("Valor min: mat[%d][%d] = %.2f",index,Jindex,min);
    return 0;
}