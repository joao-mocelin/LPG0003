/*Faça uma função que recebe três valores inteiros e retorna o maior valor. É preciso
considerar que podem haver dois (ou mesmo os três) parâmetros iguais como sendo o
maior valor. Por exemplo, os parâmetros poderiam ser 5, 8 e 8. Neste caso, a função deve
retornar 8.*/
#include <stdio.h>

int maior(int a, int b, int c){
    if(a >= b){
        if(a >= c){
            return a;
        }
        else{
            return c;
        }
    }
    if(b >= c){
        return b;
    }
    return c;
}

int main(){
    int a,b,c;
    printf("\n insira os 3 valores: \n");
    scanf("%d %d %d",&a,&b,&c);
    printf("\n %d",maior(a,b,c));
    return 0;
}