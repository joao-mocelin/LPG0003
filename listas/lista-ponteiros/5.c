#include <stdio.h>

void max_min(int *vet, int tam, int *pMin, int *pMax){
    *pMin = vet[0];
    *pMax = vet[0];
    for(int i = 1; i < tam; i++){
        if(vet[i] > *pMax){
            *pMax = vet[i];
        }
        if(vet[i] < *pMin){
            *pMin = vet[i];
        }
    }
}

int main(){
    int n;
    printf("insira o tamanho do vetor:\n");
    scanf("%d",&n);
    int v[n];
    for(int i = 0; i < n; i++){
        printf("\nv[%d]: ",i);
        scanf("%d", &v[i]);
    }
    int max,min;
    max_min(v,n,&min,&max);
    printf("Valor maximo: %d\nValor minimo: %d",max,min);
    return 0;
}