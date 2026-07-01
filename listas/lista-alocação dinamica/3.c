#include <stdio.h>
#include <stdlib.h>

float mediav(float *v, int n){
    float soma = 0.0;
    for(int i = 0; i < n; i++){
        soma += v[i];
    }
    return soma/n;
}

int main(){
    float *v, *maiores;
    int n, n_maiores;
    printf("insira a quantidade de valores:\n");
    scanf("%d",&n);
    v = malloc(sizeof(float) * n);
    for(int i = 0; i < n; i++){
        printf("\nv[%d] = ",i);
        scanf("%f",&v[i]);
    }
    float media = mediav(v,n);
    printf("\nMedia = %.2f",media);
    n_maiores = 0;
    for(int i = 0; i < n; i++){
        if(v[i] >= media){
            n_maiores++;
        }
    }
    maiores = malloc(sizeof(float) * n_maiores);
    int j = 0;
    for(int i = 0; i < n; i++){
        if(v[i] >= media){
            maiores[j] = v[i];
            j++;
        }
    }
    for(int i = 0; i < n_maiores; i++){
        printf("\nmaiores[%d] = %.2f",i,maiores[i]);
    }
    free(v);
    free(maiores);
    return 0;
}