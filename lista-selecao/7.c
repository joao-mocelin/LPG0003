/*
7
) Soma de Ímpares Consecutivos II
Leia um valor inteiro
N que é a quantidade de casos de teste que vem a seguir. Ca da caso de teste
consiste de dois inteiros X e Y . Você deve apresentar a soma de todos os ímpares existentes entre X
e Y
Entrada
A primeira linha de entrada é um inteiro
N que é a quantidade de casos de teste que vem a seguir.
Cada caso de teste co nsiste em uma linha contendo dois inteiros X e Y
Saída
Imprima a soma de todos valores ímpares
entre X e Y
Exemplo de Entrada
Exemplo de Saída
7
4 5
13 10
6 4
3 3
3 5
3 4
3 8
0
11
5
0
0
0
12
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

void soma(){
    int x, y, soma = 0;
    scanf("%d %d",&x,&y);
    int i = menor(x,y);
    int j = maior(x,y);
    for(i += 1; i < j; i++){
        if(i % 2 != 0){
            soma += i;
        }
    }
    printf("\n SOMATORIO = %d\n",soma);
}

int main(){
    int n;
    printf("\ninsira a quantidade de casos: \n");
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        printf("\n%d caso.\n",i);
        soma();
    }
    return 0;
}