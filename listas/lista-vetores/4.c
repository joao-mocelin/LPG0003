/*Escreva uma função que recebe um vetor v, sua capacidade n e uma chave de busca. A
função também recebe um vetor que vai armazenar os índices em que a chave se encontra
em v. A função deve fazer a busca de maneira sequencial e armazenar os índices em que a
chave se encontra e preencher o resto do vetor com -1. Os vetores v e indices devem ter a
mesma capacidade. Protótipo da função:
void busca_todos(int v[], int n, int chave, int indices[]);*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void busca_todos(int *v, int n, int key, int *indices){
    int i = 0, j = 0;
    for(i = 0; i < n; i++){
        if(key == v[i]){
            indices[j] = i;
            j++;
        }
    }
    while(j < n){
        indices[j] = -1;
        j++;
    }
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
    int v[10], indices[10];
    int key = rand() % 99 + 1;
    randV(v,10);
    printf("\n Vetor = ");
    printV(v,10);
    printf("\n Key = %d",key);
    busca_todos(v,10,key,indices);
    printf("\n Indices = ");
    printV(indices,10);
    return 0;
}