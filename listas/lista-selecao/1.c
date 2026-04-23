/*
Leia 2 valores com uma casa decimal (x e y), que devem representar as coordenadas de um ponto
em um plano. A seguir, determine qual o quadrante ao qual pertence o ponto, ou se está so bre um
dos eixos cartesianos ou na origem (x = y = 0).
Se o ponto estiver na origem, escreva a mensagem “Origem”.
Se o ponto estiver sobre um dos eixos escreva “Eixo X” ou “Eixo Y”, conforme for a situação.
Entrada
A entrada conté
m as coordenadas de um p onto.
Saída
A saída deve apresentar o quadrante em que o ponto se encontra.
Exemplo de Entrada
Exemplo de Saída
4.5
2.2 Q4
0.1 0.1
Q1
0.0 0.0
Origem
*/

#include <stdio.h>

int main(){
    float x = 0.0, y = 0.0 ;
    printf("\n Insira x e y\n");
    scanf("%f %f",&x,&y);
    if(x == 0 && y == 0){
        printf("\n(%.1f,%.1f)",x,y);
        printf("\nEsta na origem");
        return 0;
    }
    if(x == 0){
        printf("\n(%.1f,%.1f)",x,y);
        printf("\nEsta sobre o eixo Y");
        return 0;
    }
    if(y == 0){
        printf("\n(%.1f,%.1f)",x,y);
        printf("\nEsta sobre o eixo X");
        return 0;
    }
    
    if(x < 0){
        if(y < 0){
            printf("\n(%.1f,%.1f)",x,y);
            printf("\nEsta no Q3");
            return 0;
        }
        printf("\n(%.1f,%.1f)",x,y);
        printf("\nEsta no Q2");
        return 0;
    }
    if(y > 0){
        printf("\n(%.1f,%.1f)",x,y);
        printf("\nEsta no Q1");
        return 0;
    }
    printf("\n(%.1f,%.1f)",x,y);
    printf("\nEsta no Q4");
    return 0;
}
