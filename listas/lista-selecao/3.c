/*
Tempo de Jogo
Leia a hora inicial e a hora final de um jogo. A seguir calcule a duração do jogo, sabendo que o
mesmo pode começar em um dia e terminar em outro, tendo uma duração máxima de 24 horas.
Entrada
Dois números in
teiros representando o início e o fim do jogo.
Saída
Mostre a duração do jogo conforme exemplo abaixo.
Exemplo de Entrada
Exemplo de Saída
16 2
O JOGO DUROU 10 HORA(S)
0 0
O JOGO DUROU 24 HORA(S)
2 16
O JOGO DUROU 14 HORA(S)
*/
#include <stdio.h>

int main(){
    int inicio, fim, duracao;
    printf("\nInsira o horario de inicio e de fim (ex 16 2)\n");
    scanf("%d %d",&inicio,&fim);
    if(inicio == fim){
        duracao = 24;
    }
    else if(inicio < fim){
        duracao = fim - inicio;
    }
    else{ // inicio > fim
        duracao = 24 - inicio + fim;
    }
    printf("\n O JOGO DUROU %d HORA(S)",duracao);
    return 0;
}*/