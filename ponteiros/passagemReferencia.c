#include <stdio.h>

void incremento(int *v){
    (*v)++;
}

void fat(int x, int *p){
    while (x > 0)
    {
        (*p) *= x;
        x--;
    }
}

int main(){
    int n = 1;
    printf("\n %d",n);
    incremento(&n);
    printf("\n %d",n);
    return 0;
}