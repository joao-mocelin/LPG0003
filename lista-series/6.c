/*
Escreva um algoritmo que determine o valor aproximado do seno de x com base na
série abaixo. O número de termos da série bem como o valor de x são determinados
pelo usuário. Obs.: para a potenciação, não é permitido o uso de funções ou
operadores predefinidos.
*/
#include <stdio.h>

double fat(double x){
    if(x<=1){
        return 1;
    }
    return x*fat(x-1);
}

double pot(double x, int exp){
    if(exp == 0){
        return 1;
    }
    return x * pot(x,exp-1);
}

int main(){
    int n;
    double x;
    printf("\n insira o x (rad) para calcular sen(x) e o numero de termos da serie: \n");
    scanf("%lf %d",&x,&n);
    double sen_x = 0;
    double sinal = 1.0;
    for(int i = 1; i < n*2; i+=2){
        sen_x += sinal * (pot(x,i) / fat(i));
        sinal *= -1.0;
    }
    printf("\n sen(%lf) = %lf",x,sen_x);
    return 0;
}