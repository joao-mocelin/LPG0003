/*Implemente a versão recursiva da função que faz a busca sequencial em um vetor.
Protótipo da função:
int busca_seq_rec(int v[], int n, int chave);*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int busca_seq_rec(int *v, int n, int key){
    if(n < 0){
        return -1;
    }
    if(v[n-1] == key){
        return n - 1;
    }
    return busca_seq_rec(v, n-1, key);
}


void randV(int *v, int n){
    for(int i = 0; i < n; i++){
        v[i] = rand() % 9 + 1;
    }
}

void printV(int *v, int n){
    for(int i = 0; i < n; i++){
        printf("\n %d",v[i]);
    }
}

int main(){
    srand(time(NULL));
    int v[10];
    int key = rand() % 9 + 1;
    randV(v,10);
    printf("\n key = %d\n", key);
    printV(v,10);
    int indice = busca_seq_rec(v,10,key);
    if(indice == -1){
        printf("\n chave nao encontrada no vetor");
    }
    else{
        printf("\n chave encontrada no indice v[%d]",indice);
    }
    return 0;
}