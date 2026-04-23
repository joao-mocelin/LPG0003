/*
6
) Soma de Imp ares Consecutivos I
Leia 2 valores inteiros
X e Y . A seguir, calcule e mostre a soma dos números impares entre
Entrada
D
ois valores inteiros.
Saída
O programa deve imprimir um valor inteiro. Este valor é a soma dos valore
s ímpares que estão entre
os valores fornecidos na entrada que deverá caber em um inteiro.
Exemplo de Entrada
Exemplo de Saída
6
5
5
*/
#include <stdio.h>

int menor(int x, int y){
    if(x < y)
        return x;
    return y;
}

int maior(int x, int y){
    if(x > y)
        return x;
    return y;
}


int main(){
    int x, y, soma = 0;
    scanf("%d %d",&x,&y);
    int i = menor(x,y);
    int j = maior(x,y);
    for(i += 1; i < j; i++){
        if(i % 2 != 0){
            soma += i;
        }
    }
    printf("\n SOMATORIO = %d",soma);
    return 0;
}