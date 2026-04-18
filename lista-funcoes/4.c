/*Faça uma função que recebe 2 parâmetros, x e y, e calcule a soma dos números impares
entre eles (sem contar com eles mesmos). Repare que a função deve levar em conta de
que x pode ser maior do que y. Por exemplo, para x = 6 e y = -5, temos a seguinte soma
(em ordem crescente): -3 + (-1) + 1 + 3 + 5 = 5. Outro exemplo: para x = 3 e y = 10 temos 5
+ 7 + 9 = 21.*/
#include <stdio.h>

int maior(int a, int b){
    if (a > b){
        return a;
    }
    return b;
}

int menor(int a, int b){
    if (a < b){
        return a;
    }
    return b;
}

int somatorio(int a, int b){
    int i = menor(a,b);
    int soma = 0;
    for(i = i+1; i < maior(a,b); i++){
        if(i % 2 != 0){
            soma += i;
        }
    }
    return soma;
}

int main(){
    int x,y;
    printf("\n insira x e y: \n");
    scanf("%d %d",&x,&y);
    printf("\n %d",somatorio(x,y));
    return 0;
}