#include <stdio.h>

int main(){

    long long int a = 1, b = 1, c = 0;
    int n = 0;
    printf("\n quantos termos? \n");
    scanf("%d",&n);
    printf("\n 1° = 1\n 2° = 1");
    for (int i = 3; i <= n; i++)
    {
        c = a + b;
        printf("\n %d° = %lld",i,c);
        a = b;
        b = c;
    }
    



    return 0;
}