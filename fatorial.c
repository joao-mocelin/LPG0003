#include <stdio.h>

int main(){
    int acumulador = 1;
    int fatorial = 0;
    scanf("%d",&fatorial);
    if(fatorial == 0)
    {
        printf("\n fatorial = 1");
    }
    if (fatorial < 0)
    {
        printf("ERRO!");
        return 1;
    }
    
    while (fatorial > 1)
    {
        acumulador = fatorial * acumulador;
        fatorial--;
    }
    printf("\n\t%d",acumulador);
    return 0;
}