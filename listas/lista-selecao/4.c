/*
Pares, Ímpares, Positivos e Negativos
Leia
N valores Inteiros. A seguir mostre quantos valores digitados foram pares, quantos valores
digitados foram ímpares, quantos valores digitados foram positivos e quan tos valores digitados
foram negativos.
Entrada
A
entrada contém o valor N, seguido de N valores inteiros quaisquer.
Saída
Imprima a mensagem conforme o exemplo fornecido, uma mensagem por linha, não esquecendo o
final de linha após cada uma.
Exemplo de Entrada
Exempl
o de Saída
5
-
5
0
3
4
12
3 valor(es) par(es)
2 valor(es) impar(es)
1 valor(es) positivo(s)
3 valor(es) negativo(s)
*/
#include <stdio.h>

int main(){
    int n, i, x, positivos = 0, negativos = 0, pares = 0, impares = 0;
    printf("\nInsira quantos valores voce quer digitar: \n");
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        printf("\nDigite um numero: \n");
        scanf("%d",&x);
        if(x < 0){
            negativos += 1;
            if((-x) % 2 == 0){
                pares += 1;
            }
            else{
                impares +=1;
            }
        }
        else if(x > 0){
            positivos += 1;
            if(x % 2 == 0){
                pares += 1;
            }
            else{
                impares += 1;
            }
        }
        else{ // x = 0
            pares += 1;
        }
    }
    printf("\n %d valor(es) par(es)\n %d valor(es) impar(es)\n %d valor(es) positivo(s)\n %d valor(es) negativo(s)",pares,impares,positivos,negativos);
    return 0;
}