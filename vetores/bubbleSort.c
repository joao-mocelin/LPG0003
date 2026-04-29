//Bubble sort
//Compara elementos adjacentes e troca-os 
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

void bubbleSort(int *v, int tam){
    int aux, swap = 0;
    for(int i = 0; i < tam; i++){
        for(int j = i + 1; j < tam; j++){
            if(v[i] > v[j]){
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            swap = 1;
        }
        }
        if(swap == 0){
            break;
        }
    }
} 

int main(){
    srand(time(NULL));
    int v[10];
    vRand(v,10);
    printf("\n Vetor nao ordenado: \n");
    vPrint(v,10);
    bubbleSort(v,10);
    printf("\n Vetor ordenado: \n");
    vPrint(v,10);
    return 0;
}