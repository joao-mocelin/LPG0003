/*
Faça um algoritmo que mostre na tela os k termos da série definida a seguir e, ao
final, mostre o somatório dos termos (o resultado converge para o logaritmo
natural de 2). O número de termos da série é definido pelo usuário.
*/
#include <stdio.h>
#include <math.h>


int main(){
    int k = 1;
    printf("\n insira quantos termos :");
    scanf("%d",&k);
    float somatorio = 0.0;
    for (int i = 1; i <= k; i++)
    {
        float termo = (pow(-1,i+1)/(i));
        printf("\n%d termo = %f",i,termo);
        somatorio += termo;
    }
    printf("\n Somatorio = %f",somatorio);
    return 0;
}