#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* aloca_str(char *mensagem){
    printf("\n%s",mensagem);
    char temp[1024];
    scanf(" %[^\n]",temp);
    char *p = malloc(sizeof(strlen(temp)));
    strcpy(p,temp);
    return p;
}

int main() {
    //lista de strings
    char** lista = NULL;
    int cont = 0;
    char *str = aloca_str("digite algo: ");
    while(strcmp(str,"sair") != 0){
        cont++;
        lista = realloc(lista,sizeof(char*) * cont);
        lista[cont-1] = str;
        str = aloca_str("digite algo: ");
    }
    for(int i = 0; i < cont; i++){
        printf("\n lista[%d] = '%s'",i,lista[i]);
    }
    for(int i = 0; i < cont; i++){
        free(lista[i]);
    }
    free(lista);
    free(str);
    return 0;
}
