#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *repetidor(char *s,int n){
    int len = strlen(s);
    char *repetido = malloc(sizeof(char) * (n * len + 1));
    repetido[0] = '\0';
    for (int i = 0; i < n; i++) {
        strcat(repetido, s);
    }
    return repetido;
}


int main(){
    char s[] = "Abc";
    int n = 4;
    char *string = repetidor(s,n);
    printf("\n%s",string);
    free(string);
    return 0;
}