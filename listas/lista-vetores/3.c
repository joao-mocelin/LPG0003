/*
Faça uma função que recebe um vetor e sua capacidade como parâmetros e retorna o
somatório dos números primos contidos no vetor. Recomenda-se utilizar a função de
verificação (se um número é primo ou não) já implemetada. Protótipo:
int soma_primos(int v[], int n);
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int isPrime(int n){
    if(n <= 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}

int SomaPrimos(int *v, int n){
    int soma = 0;
    for(int i = 0; i < n; i++){
        if(isPrime(v[i]) == 1){
            soma += v[i];
        }
    }
    return soma;
}

void randV(int *v, int n){
    for (int i = 0; i < n; i++)
    {
        v[i] = rand() % 99 + 1;
    }
    
}

void printV(int *v, int n){
    for (int i = 0; i < n; i++)
    {
        printf("\n[%d]%d",i,v[i]);
    }
    
}

int main(){
    srand(time(NULL));
    int v[10];
    randV(v,10);
    int somatorio = SomaPrimos(v,10);
    printf("\nVetor = ");
    printV(v,10);
    printf("\n Soma dos primos = %d",somatorio);
    return 0;
}