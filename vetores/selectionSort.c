#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void vRand(int *v, int tam){
    for(int i = 0; i < tam; i++){
        v[i] = rand() % 9 + 1;
    }
}

void vPrint(int *v, int tam){
    for(int i = 0; i < tam; i++){
        printf("\n [%d] = %d",i,v[i]);
    }
}


void selectionSort(int *v, int tam){
    int aux, index;
    for(int i = 0; i < tam; i++){
        index = i;
        for(int j = i+1; j < tam; j++){
            if(v[j] < v[index]){
                index = j;
            }
        }
        aux = v[i];
        v[i] = v[index];
        v[index] = aux;
    }
}

int main(){
    srand(time(NULL));
    int v[10];
    vRand(v,10);
    printf("\n Vetor nao ordenado: \n");
    vPrint(v,10);
    selectionSort(v,10);
    printf("\n Vetor ordenado: \n");
    vPrint(v,10);
    return 0;
}