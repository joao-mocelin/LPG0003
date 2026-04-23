/*
5
) Médias Ponderadas
Leia 1 valor inteiro N, que representa o número de casos de teste que vem a seguir. Cada caso de
teste consiste de 3 valores reais, cada um deles com uma casa decimal. Apresente a média
ponderada pa ra cada um destes conjuntos de 3 valores, sendo que o primeiro valor tem peso 2, o
segundo valor tem peso 3 e o terceiro valor tem peso 5.
Entrada
A
entrada contém um valor inteiro N na primeira linha. Cada N linha a seguir contém um caso de
tes te com três valores reais
Saída
Para cada caso de teste, imprima a média ponderada dos 3 valores, conforme exemplo abaixo.
Exemplo de Entrada
Exemplo de Saída
3
6.5 4.3 6.2
5.1 4.2 8.1
8.0 9.0 10.0
5.7
6.3
9.3
*/
#include <stdio.h>

int main(){
    int n, i;
    printf("\nInsira a quantidade de casos:\n");
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        float a, b, c, media;
        printf("\nInsira os 3 valores reais:\n");
        scanf("%f %f %f",&a,&b,&c);
        media = a*0.2 + b*0.3 + c*0.5;
        printf("\t media =  %.1f\n",media);
    }
    return 0;
}