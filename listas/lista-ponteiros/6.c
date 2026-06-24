#include <stdio.h>

void max_vetor(float *vet, int tam, int *pIndice, float *pMax){
    *pMax = vet[0];
    *pIndice = 0;
    for(int i = 1; i < tam; i++){
        if(vet[i] > *pMax){
            *pMax = vet[i];
            *pIndice = i;
        }
    }
}

int main(){
    int n;
    printf("insira o tamanho do vetor:\n");
    scanf("%d",&n);
    float v[n];
    for(int i = 0; i < n; i++){
        printf("\nv[%d]: ",i);
        scanf("%f", &v[i]);
    }
    int index;
    float max;
    max_vetor(v,n,&index,&max);
    printf("Valor maximo: %.2f\nposicao : v[%d]",max,index);
    return 0;
}