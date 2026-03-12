/*
    leia tres valores para os lados de um triangulo 
    o algoritmo deve verificar se o triangulo e equilatero, isosceles ou escaleno
*/

#include <stdio.h>
int main(){
    int a,b,c;
    printf("\nInsira os valores de cada lado do triangulo: ");
    scanf("%d %d %d",&a,&b,&c);
    if((a == b) && (b == c)){
        printf("\nO triangulo e equilatero");
    }
    else if ((a==b) || (a==c) || (b==c))
    {
        printf("\nO triangulo e isosceles");
    }
    else
    {
        printf("\nO triangulo e escaleno");
    }
    
    

    return 0;
}