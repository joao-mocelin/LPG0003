#include <stdio.h>

void inc_dec(int *a,int *b){
    (*a)++;
    (*b)--;
}

int main()
{
    printf("insira a e b:\n");
    int x,y;
    scanf("%d %d",&x,&y);
    inc_dec(&x,&y);
    printf("%d %d",x,y);
    return 0;
}