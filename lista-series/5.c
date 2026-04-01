/*Implemente a série de Taylor para calcular a função exponencial e^x;
O algoritmo deve solicitar como entrada o valor de x e quantidade de termos da
série.*/
#include <stdio.h>
#include <math.h>
int fat(int x){
    if(x <= 1){
        return 1;
    }
    return x * fat(x-1);
}

int main(){
    int x;
    int n;
    printf("\n insira o valor de x e a quantidade de termos da serie: ");
    scanf("%d %d",&x,&n);
    float e_x = 0;
    for(int i = 0; i < n; i++){
        e_x += pow(x,i) / fat(i);
    }
    printf("\n e^%d com %d termos da serie eh = %f",x,n,e_x);
    return 0;
}