#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 99

int search(char *s, char key){
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == key){
            return 1;
        }
    }
    return 0;
}

int isNumber(char *s){
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] < '0' || s[i] > '9'){
            return 0;
        }
    }
    return 1;
}

int converte(char *s){
    double somatorio = 0.0;
    for(int i = 0; s[i] != '\0'; i++){
        somatorio += (s[i]-48) * pow(10,strlen(s) - i - 1);
    }
    return (int)somatorio;
}

int main(){
    char string[N];
    // char c = 'c';
    scanf("%98[^\n]",string);
    // if(search(string,c) == 1){
    //     printf("\na string '%s' contem a chave '%c'",string,c);
    // }
    if(isNumber(string) == 1){
        int somatorio = converte(string);
        printf("\nString = '%s' ou = %d",string,somatorio);
    }
    else{
        printf("num eh numero nao");
    }
    return 0;
}