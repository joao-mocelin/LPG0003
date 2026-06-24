#include <stdio.h>

void troca_valor(float *x, float *y){
    float aux = *y;
    *y = *x;
    *x = aux;
}

int main(){
    float x,y;
    printf("insira o primeiro float:\n");
    scanf("%f",&x);
    printf("insira o segundo float:\n");
    scanf("%f",&y);
    troca_valor(&x,&y);
    printf("1 = %.2f , 2 = %.2f",x,y);
    return 0;
}