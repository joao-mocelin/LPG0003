#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p, n;
    printf("\n insira o tamnho do vetor:\n");
    scanf("%d",&n);
    p = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        printf("\nvetor posicao [%d] = \n",i);
        scanf("%d",p+i);
    }
    for (int i = 0; i < n; i++)
    {
        printf("\n vetor[%d] = %d",i,*(p+i));
    }
    free(p);
    return 0;
}