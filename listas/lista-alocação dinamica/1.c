#include <stdio.h>
#include <stdlib.h>

float *clone(float *v, int n){
    float *destino = malloc(sizeof(float) * n);
    for (int i = 0; i < n; i++)
    {
        destino[i] = v[i];
    }
    return destino;
}

int main(){
    float v[10] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
    int n = 10;
    float *newV = clone(v,n);
    for(int i = 0; i < n; i++){
        printf("\n%f",newV[i]);
    }
    free(newV);
    return 0;
}