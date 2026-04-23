/*
Série de Nilakantha:
*/
#include <stdio.h>

int main(){
    float pi = 3.0;
    float sinal = 4.0; //sinal da soma
    int k = 1;
    int a = 2, b = 3, c = 4;
    printf("\n insira a quantidade de termos para calcular pi : ");
    scanf("%d",&k);
    for(int i = 1; i <= k ; i++){
        pi += sinal/(a*b*c);
        sinal *= -1;
        a += 2;
        b += 2;
        c += 2;
    }
    printf("\n pi = %f",pi);
    return 0;
}