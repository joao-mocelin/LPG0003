#include <stdio.h>

void calcula_circulo(float raio, float *pPerimetro, float *pArea){
    *pPerimetro = 2.0 * 3.14 * raio;
    *pArea = 3.14 * (raio * raio);
}

int main(){
    float raio, perimetro, area;
    printf("insira o raio:\n");
    scanf("%f",&raio);
    calcula_circulo(raio,&perimetro,&area);
    printf("Raio = %.2f\nPerimetro = %.2f\nArea = %.4f",raio,perimetro,area);
    return 0;
}