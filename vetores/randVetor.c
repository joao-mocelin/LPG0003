#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraValores(int *v, int n){        //generates values for each vector's index
    for(int i = 0; i < n; i++){
        v[i] = rand() % 10;
    }
}

void printVetor(int *v, int n){         //prints the vector on screen
    for(int i = 0; i < n; i++){
        printf("\n %d",v[i]);
    }
}

int main(){
    srand(time(NULL));              //RandInt with time based seed, don't repeat random numbers between executions.
    int v[10];
    geraValores(v,10);
    printVetor(v,10);
    return 0;
}