#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * busca(int *v, int n, int key){
    int *indices = malloc(sizeof(int));
    int cont = 0;
    for(int i = 0; i < n; i++){
        if(*(v+i) == key){
            *(indices + cont) = i;
            cont++;
            realloc(indices,sizeof(int) * (cont + 1) );
        }
    }
    *(v + cont) = -1;
    return indices;
}

int geravalores(int *v,int n){
    for (int i = 0; i < n; i++)
    {
        v[i] = rand() % 9;
    }
    
}

int main(){
    srand(time(NULL));
    int v[25];
    geravalores(v,25);
    for(int i = 0; i < 25; i++){
        printf("\nvetor[%d] = %d",i,v[i]);
    }
    int *indices = busca(v,25,1);
    for(int i = 0; *(v+i) != -1; i++){
        printf("\nindices[%d] = %d",i,indices[i]);
    }
    free(indices);
    return 0;
}