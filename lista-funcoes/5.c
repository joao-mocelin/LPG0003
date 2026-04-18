/* Faça um programa que, dados k e n, mostre na tela os n primeiros números primos acima
de k. A verificação do número (se é ou não é primo) deve ser feita através de uma função.*/
#include <stdio.h>
#include <math.h>

int ehPrimo(int a){
    if(a <= 1){
        return 0;
    }
    for(int i = 2; i <= sqrt(a); i++){
        if(a % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int k,n;
    printf("insira o k e o n: \n");
    scanf("%d %d",&k,&n);
    int count = 1;
    int j = k+1;
    while(count <= n){
        if(ehPrimo(j) == 1){
            printf("\n %d",j);
            count += 1;
        }
        j += 1;
    }
    return 0;
}