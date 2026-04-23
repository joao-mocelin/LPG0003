/*
    Leia 3 valores de ponto flutuante A, B e C e ordene
os em ordem decres cente, de modo que o lado
A representa o maior dos 3 lados. A seguir, determine o tipo de triângulo que estes três lados
formam, com base nos seguintes casos, sempre escrevendo uma mensagem adequada:
 se A ≥ B+C, apresente a mensagem: NAO FORMA TRIANGULO
 s e A 2 = B 2 + C 2 , apresente a mensagem: TRIANGULO RETANGULO
 se A 2 > B 2 + C 2 , apresente a mensagem: TRIANGULO OBTUSANGULO
 se A 2 < B 2 + C 2 , apresente a mensagem: TRIANGULO ACUTANGULO
 se os três lados forem iguais, apresente a mensagem: TRIANGULO EQUILATERO
 se apenas dois dos lados forem iguais, apresente a mensagem: TRIANGULO ISOSCELES
Entrada
A entrada contem três valores de ponto flutuante de dupla precisão A (0 < A) , B (0 < B) e C (0 <
C).
Saída
Imprima todas as classificações do triângulo especificado
na entrada.
Exemplos de Entrada
Exemplos de Saída
7.0 5.0 7.0
TRIANGULO ACUTANGULO
TRIANGULO ISOSCELES
6.0 6.0 10.0
TRIANGULO OBTUSANGULO
TRIANGULO ISOSCELES
6.0 6.0 6.0
TRIANGULO ACUTANGULO
TRIANGULO EQUILATERO
5.0 7.0 2.0
NAO FORMA TRIANGULO
6.0 8.
0 10.0 TRIANGULO RETANGULO
*/
#include <stdio.h>



int main(){
    float a,b,c, temp;
    printf("\nInsira os tres lados do triangulo:\n");
    scanf("%f %f %f",&a,&b,&c);

    if(a <= 0 || b <= 0 || c <= 0){ 
        printf("ERRO!!!");
        return 1;
    }

    if(b >= a && b >= c){
        temp = a;
        a = b;
        b = temp;
    }
    else if(c >= b && c >= a){
        temp = a;
        a = c;
        c = temp;
    }

    if(a >= b+c){
        printf("\nNAO FORMA TRIANGULO");
        return 0;
    }
    if((a*a) == (b*b) + (c*c)){
        printf("\nTRIANGULO RETANGULO");
    }
    if((a*a) > (b*b) + (c*c)){
        printf("\nTRIANGULO OBTUSANGULO");
    }
    if((a*a) < (b*b) + (c*c)){
        printf("\nTRIANGULO ACUTANGULO");
    }
    if(a == b && a == c){
        printf("\nTRIANGULO EQUILATERO");
    }
    else if (a == b || b == c || a == c){
        printf("\nTRIANGULO ISOSCELES");
    }
    return 0;
}