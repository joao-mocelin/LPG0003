/*
Faça um programa que leia um inteiro n e determine a soma S da seguinte forma: 1 + 2 + 3
+ 4 + ... + n. Escreva duas versões de funções: iterativa e recursiva.
*/
#include <stdio.h>

int soma(int n){
    int soma = 0;
    for(int i = 1; i <= n; i++){
        soma += i;
    }
    return soma;
}

int soma_rec(int n){
    if(n == 1){
        return 1;
    }
    return n + soma_rec(n-1);
}

int main(){
    int n;
    printf("insira o n: ");
    scanf("%d",&n);
    printf("\n%d",soma(n));
    printf("\n%d",soma_rec(n));
    return 0;
}