#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p, x;
    p = malloc(sizeof(int));
    printf("\n endereco de p = %p",p);
    *p = 5;
    printf("\n valor de p = %d",*p);
    x = *p;
    free(p);
    printf("\n %d",x);
    return 0;
}