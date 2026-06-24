#include <stdio.h>

void calcula_hora(int totalminutos, int *ph, int *pm){
    *pm = totalminutos % 60;
    *ph = totalminutos / 60;
}

int main(){
    int minutos;
    int hatual,matual;
    printf("quantos minutos passaram desde 00:00\n");
    scanf("%d",&minutos);
    if(minutos >= 1440){
        printf("ja eh outro dia");
        return 1;
    }
    calcula_hora(minutos,&hatual,&matual);
    printf("Agora sao %02d:%02d",hatual,matual);
    return 0;
}