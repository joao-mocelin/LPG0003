/*Faça um programa que leia um inteiro n e utilize uma função (faça as versões iterativa e
recursiva) para calcular o somatório que determina o valor da constante e:
∑ = 1/0! + 1/1! +...+ 1/n!*/
#include <stdio.h>

int fat(int n){
    if(n <= 1){
        return 1;
    }
    return n * fat(n-1);
}

double soma_e(int n){
    double soma = 0;
    for(int i = 0; i <= n; i++){
        soma += 1.0/fat(i);
    }
    return soma;
}

double soma_eRec(int n){
    if(n == 0){
        return 1.0;
    }
    return 1.0/fat(n) + soma_eRec(n-1);
}

int main(){
    int n;
    printf("insira o valor de n: ");
    scanf("%d",&n);
    printf("\n%lf",soma_e(n));
    printf("\n%lf",soma_eRec(n));
    return 0;
}