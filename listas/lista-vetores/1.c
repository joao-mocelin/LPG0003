/*Escreva uma função que recebe dois vetores de mesma capacidade n e compara se os
mesmos são iguais, ou seja, se contêm os mesmos valores e na mesma ordem. A função
deve ser booleana, ou seja, se forem iguais retorna 1, caso contrário retorna 0. Protótipo
da função:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compararVetor(int *v0, int *v1, int n){
    for(int i = 0; i < n; i++){
        if(v0[i] != v1[i]){
            return 0;
        }
    }
    return 1;
}

void randVetor(int *v, int n){
    for(int i = 0; i < n; i++){
        v[i] = rand() % 99 + 1;
    }
}

void printVetor(int *v, int n){
    for(int i = 0; i < n; i++){
        printf("\n%d",v[i]);
    }
}

void vetorTeste(int *v, int n){
    for(int i = 0; i < n; i++){
        v[i] = i + 1;
    }
}

int main(){
    srand(time(NULL));
    int v[10], v2[10];
    vetorTeste(v,10);
    randVetor(v2,10);
    if(compararVetor(v,v2,10) == 0){
        printf("\nVetores diferentes");
        printf("\nVetor 1:");
        printVetor(v,10);
        printf("\nVetor 2:");
        printVetor(v2,10);
    }
    else{
        printf("\nVetores iguais: ");
        printVetor(v,10);
    }
    return 0;
}