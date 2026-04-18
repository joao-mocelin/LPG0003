/*Faça um programa que lê os três lados de um triângulo e determina o seu tipo, conforme
códigos a seguir. Os códigos devem ser retornados por uma função de tipo int, que recebe
os lados do triângulo como parâmetro. Protótipo da função:
int tipo_triangulo(float, x, float y, float z);
O retorno da função deve ser conforme os códigos a seguir:
0. Os lados não formam um triângulo (ou seja, a soma de dois deles é menor ou igual
ao outro lado);
1. Triângulo equilátero;
2. Triângulo isóceles;
3. Triângulo escaleno.*/
#include <stdio.h>

int triangulo(float a, float b, float c){
    if(a + b <= c || a + c <= b || b + c <= a){
        return 0;
    }
    if(a == b && b == c){
        return 1;
    }
    if(a != b && b != c){
        return 3;
    }
    return 2;
    
}

int main(){
    float a,b,c;
    printf("\n insira os lados do triangulo: \n");
    scanf("%f %f %f",&a,&b,&c);
    switch (triangulo(a,b,c))
    {
    case 0:
        printf("\n nao eh um triangulo");
        break;
    case 1:
        printf("\n eh um triangulo equilatero");
        break;
    case 2:
        printf("\n eh um triangulo isoceles");
        break;
    case 3:
        printf("\n eh um triangulo escaleno");
        break; 
    default:
        printf("ERRO!");
        break;
    }

    return 0;
}