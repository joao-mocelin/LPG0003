/*
Série de Gregory-Leibniz:
*/
#include <stdio.h>

int main(){
    float pi = 0;
    float sinal = 4.0; //sinal da soma
    int k = 1;
    printf("\n insira a quantidade de termos para calcular pi : ");
    scanf("%d",&k);
    for(int i = 1; i < k*2 ; i+=2){
        pi += sinal/i;
        sinal *= -1;
    }
    printf("\n pi = %f",pi);
    return 0;
}