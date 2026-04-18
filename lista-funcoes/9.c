/*Faça um programa que leia um inteiro n e utilize uma função (faça as versões iterativa e
recursiva) para determinar a soma S da série harmônica definida a seguir:
s = 1 + 1/2 + ... + 1/n 
*/
#include <stdio.h>

float harmonica(int n){
    float soma = 0;
    for(int i = 1; i <= n; i++){
        soma += 1.0/i;
    }
    return soma;
}

float harmonica_rec(int n){
    if(n == 1){
        return 1;
    }
    return 1.0/n + harmonica_rec(n-1);
}

int main(){
    int n;
    printf("insira o n: ");
    scanf("%d",&n);
    printf("\n%f",harmonica(n));
    printf("\n%f",harmonica_rec(n));
    return 0;
}