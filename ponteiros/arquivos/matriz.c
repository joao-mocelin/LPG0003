#include <stdio.h>
#include <stdlib.h>

int **aloca_matriz(int l, int c){
    int **p = malloc(sizeof(int*) * 1);
    for(int i = 0; i < l; i++){
        p[i] = malloc(sizeof(int) * c);
    }
    return p;
}

int main(){
    FILE *f = fopen("C:\\code\\lpg2026\\ponteiros\\arquivos\\matriz.txt", "rt");
    if(f == NULL){
        printf("\nErro!");
        return 1;
    }
    int lin, col;
    fscanf(f,"%d %d",&lin,&col);
    int **m = aloca_matriz(lin,col);
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            fscanf(f,"%d",&m[i][j]);
        }
    }
    fclose(f);
    printf("\n linhas: %d\n colunas: %d\n",lin,col);
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < lin; i++){
        free(m[i]);
    }
    free(m);
    return 0;
}