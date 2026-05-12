/*Escreva uma função que, a partir de uma string str, copia para o parâmetro sub a substring
a partir do índice inicial ini e que contém a quantidade de caracteres n. Alguns casos
particulares devem ser considerados, conforme os exemplos a seguir. Protótipo:
void substring( char str[], int ini, int n, char sub[] );
*/
#include <stdio.h>

int strlen(char *str){
    int cont = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        cont++;
    }
    return cont;
}

void substring(char *str, int ini, int n, char *sub){
    int tam = strlen(str);
    if(tam == 0){
        sub[0] = '\0';
        return;
    }
    if (ini < 0 || ini >= tam || n <= 0) {
        sub[0] = '\0';
        return;
    }
    
    int i = 0;
    for(i = ini; i < ini + n; i++){
        sub[i - ini] = str[i];
    }
    sub[i - ini] = '\0';
}

int main(){
    char string[99] = "Alguma Coisa 123";
    char sub[99];
    int ini = 13;
    int n = 10;
    substring(string,ini,n,sub);
    printf("%s",sub);
    return 0;
}