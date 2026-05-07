#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
#define N 5

void printList(char list[N][MAX]){
    for (int i = 0; i < N; i++){
        printf("[%d] : '%s' \n", i, list[i]);
    }
}

void sortList(char list[N][MAX]){
    for (int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(strcasecmp(list[i],list[j]) > 0){ //strcasecmp isn't case sensitive.
                char aux[MAX];
                strcpy(aux, list[i]);
                strcpy(list[i], list[j]);
                strcpy(list[j],aux);
            }
        }
    }
}

int main(){
    char nome[N][MAX] = {"aMANDA", "MARIA", "ROGER", "JOSE", "RAMON" };
    sortList(nome);
    printList(nome);
    return 0;
}