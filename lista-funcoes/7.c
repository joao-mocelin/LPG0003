/*Escreva uma função que calcula o somatório dos n termos que são múltiplos de k a partir
de x. Os parâmetros são determinados pelo usuário e a função é chamada pelo programa
principal, que em seguida mostra o resultado na tela. Exemplo: para n = 3, k = 4 e x = 18,
temos, 20 + 24 + 28 = 72. Protótipo da função:
int soma_especial(int n, int k, int x);*/
#include <stdio.h>

int soma_especial(int a, int b, int c){
    int soma = 0;
    int cont = 0;
    int i = c+1;
    while(cont < a){
        if(i % b == 0){
            soma += i;
            cont++;
        }
        i++;
    }
    return soma;
}

int main(){
    int n,k,x;
    printf("insira n k x: ");
    scanf("%d %d %d",&n,&k,&x);
    int soma = soma_especial(n,k,x);
    printf("\n %d",soma);
    return 0;
}