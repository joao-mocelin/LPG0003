/*
Implemente o programa para determinar o valor da constante e:
O programa deve solicitar como entrada a quantidade n de termos da série
*/
#include <stdio.h>

int fat(int x){
    if(x <= 1){
        return 1;
    }
    return x * fat(x-1);
}

int main(){
    float e;
    int n;
    printf("\n insira os n termos da serie: ");
    scanf("%d",&n);
    for(int i = 0; i <= n; i++){
        e += 1.0/fat(i);
    }
    printf("\n e = %f",e);
}
//o código funciona até n = 33.