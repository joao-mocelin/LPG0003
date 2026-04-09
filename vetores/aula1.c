#include <stdio.h>

int main(){
    float v[10];
    float maior = 0.0;
    float somamedia = 0.0;
    for(int i = 1; i<=10;i++){
        printf("\n insira o %d valor do vetor: ",i);
        scanf("%f",&v[i-1]);
        if(v[i-1] >= maior){
            maior = v[i-1];
        }
        somamedia += v[i-1];
    }
    float media = somamedia / 10.0;
    printf("\n Media = %.2f",media);
    for (int i = 0; i < 10; i++)
    {
        if(v[i] > media){
            printf("\n %.2f",v[i]);
        }
    }
    
    return 0;
}