#include <stdio.h>

int main(){
    int x;
    int j = 0;
    printf("\nInsira o numero para descobrir seus divisores: ");
    scanf("%d",&x);
    printf("\nDivisores de %d", x);
    for(int i = 1; i <= x; i++)
    {
        if(x%i == 0){
            printf("\n\t%d",i);
            j++;
        }
    }
    if(j == 2){
        printf("\n%d é primo!",x);
    }
    return 0;
}