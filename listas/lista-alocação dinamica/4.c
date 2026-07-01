/*Faça um programa que leia uma certa quantidade de inteiros que são armazenados num
vetor v. A quantidade deve ser definida pelo usuário, e o programa aloca espaço para v. O
programa deve armazenar os valores positivos em um vetor vp e o valores negativos no
vetor vn. Como as quantidades de valores positivos e negativos são desconhecidas, o
espaço para vp e vn deve ser alocado dinamicamente. Os vetores vp e vn não devem
conter zeros. Ao final, imprima os três vetores. Pode ser feito com malloc() ou com
realloc(). */

#include <stdio.h>
#include <stdlib.h>

void alocaVetores(int *v, int tam, int **vp, int **vn, int *vn_n, int *vp_n){
    *vn_n = 0;
    *vp_n = 0;
    for(int i = 0; i < tam; i++){
        if(v[i] < 0){
            *vn_n += 1;
            *vn = realloc(*vn,sizeof(int) * (*vn_n));
            (*vn)[*vn_n - 1] = v[i];
        }
        if(v[i] > 0){
            *vp_n += 1;
            *vp = realloc(*vp,sizeof(int) * (*vp_n));
            (*vp)[*vp_n - 1] = v[i];
        }
    }
}

int main(){
    int n;
    printf("quantos valores inteiros tera no vetor: \n");
    scanf("%d",&n);
    int *v = malloc(sizeof(int) * n);
    printf("Dando valores ao vetor:\n");
    for (int i = 0; i < n; i++)
    {
        printf("v[%d] = ",i);
        scanf("%d",&v[i]);
    }
    int *vp = 0;
    int *vn = 0;
    int vp_n, vn_n;
    alocaVetores(v,n,&vp,&vn,&vn_n,&vp_n);
    if(vp_n > 0){
        for(int i = 0; i < vp_n; i++){
        printf("\n vp[%d] = %d",i,vp[i]);
    }
    }
    printf("\n");
    if(vn_n > 0){
        for(int i = 0; i < vn_n; i++){
        printf("\n vn[%d] = %d",i,vn[i]);
        }
    }
    free(v);
    free(vp);
    free(vn);
    return 0;
}