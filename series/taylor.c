#include <stdio.h>

int main(){
    float expoente = 0;
    int n = 50;
    printf("\n insira o expoente : \n");
    scanf("%f", &expoente);
    double somatorio = 0.0;
    for (int i = 0; i <= n; i++)
    {
        double termo = 1.0;
        for (int j = 1; j <= i; j++)
        {
            termo = termo * expoente/j;
        }
        somatorio = somatorio + termo;
    }
    printf("\n e^%.3f = %.15lf",expoente,somatorio);
    
    return 0;
}