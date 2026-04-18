/*Faça um programa que mostre na tela os n primeiros termos da sequência de Fibonacci.
Por exemplo, dado n = 8, temos: 1, 1, 2, 3, 5, 8, 13 e 21. A determinação do n-ésimo termo
da sequência deve ser feita por uma função iterativa que tem o seguinte protótipo:
int fibo(int n);
*/
#include <stdio.h>

void fibo(int k){
    int a = 1, b = 1, c = 1;
    for(int i = 0 ; i < k; i++){
        printf("\n %d",a);
        c = a+b;
        a = b;
        b = c;
    }
}

int main(){
    int k;
    printf("insira o k: \n");
    scanf("%d",&k);
    fibo(k);
    return 0;
}