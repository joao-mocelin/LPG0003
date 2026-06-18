#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void salva_arquivo(char **v, int n, char *nome_arquivo){
    FILE *f = fopen(nome_arquivo, "wt"); //wt = write text; rt = read text ...
    for(int i = 0; i < n; i++){
        fprintf(f,"%s\n", v[i]); //print vetor de string na tela 
    }
    fclose(f);
}

char* aloca_str(char *mensagem){ //recebe uma mensagem que o usuario define, irrelevante para a lógica da funçao
    printf("\n%s",mensagem);
    char temp[1024]; //aloca um espaço temporario de 1024 caracteres para receber a palavra que será salva na lista
    scanf(" %[^\n]",temp); //escaneia a palavra que o usuario digitar até o \n (enter), e coloca na variavel temp
    char *p = malloc((strlen(temp) + 1) * sizeof(char)); //aloca um ponteiro de tamanho correspondente ao tamanho da palavra
    strcpy(p,temp); //copia da temp para o ponteiro que criamos
    return p; //retorna o endereço do ponteiro
}

void desalocar(char **v, int n){
    for(int i = 0; i < n; i++){
        free(v[i]);
    }
    free(v);
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
    salva_arquivo(lista,cont,"C:\\code\\lpg2026\\ponteiros\\arquivos\\strings.txt");
    desalocar(lista,cont);
    free(str);
    return 0;
}
