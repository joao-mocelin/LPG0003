#include <stdio.h>

void converte(int tempo_s, int *s, int *m, int *h){
    *h = tempo_s / 3600;
    *m = (tempo_s % 3600) / 60;
    *s = (tempo_s % 3600) % 60;
}

int main(){
    int segundos;
    printf("\ninsira a quantidade de segundos: ");
    scanf("%d",&segundos);
    int minutos, horas;
    converte(segundos, &segundos, &minutos, &horas);
    printf("\n %02d:%02d:%02d",horas,minutos,segundos);
    return 0;
}