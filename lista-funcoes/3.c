/*Escreva um programa que informa se um caractere digitado pelo usuário representa um
dígito de 0 a 9. A verificação deve ser feita por uma função booleana (int) que recebe um
char como parâmetro. Caso o caractere seja um dígito, converta-o para um valor inteiro e
o armazene em uma variável int. Em seguida, mostre o valor inteiro na tela.*/
#include <stdio.h>

int ehDigito(char a){
    if(a >= 48 && a <= 57){
        return 1;
    }
    return 0;
}

int main(){
    char c;
    int digito;
    printf("\n insira o caracter:\n");
    scanf("%c",&c);
    if(ehDigito(c) == 1){
        digito = c;
    }
    printf("\n %c",digito);
    return 0;
}