/*
Faça um algoritmo que mostre na tela os k termos da série harmônica e, ao final,
mostre o somatório dos termos. O número de termos da série é definido pelo
usuário.
*/
#include <stdio.h>



int main(){
    int k = 1; //quantidade de termos
    printf("\n insira a quantidade de termos da serie harmonica: ");
    scanf("%d",&k);
    float somatorio = 0;
    for (int i = 1; i <= k; i++)
    {
        float termo = 1.0/i;
        printf("\n%d termo = %f",i,termo);
        somatorio += termo;
    }
    printf("\n SOMATORIO SERIE HARMONICA = %f",somatorio);


    return 0;
}