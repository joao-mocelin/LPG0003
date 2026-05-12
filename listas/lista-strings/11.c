/*Crie uma função que recebe uma string s e um caractere c, e apague todas as ocorrências
de c em s. Exemplo:
Entrada: s = "ManhattanConnection" e c= 'n'
Saída: s = "MahattaCoectio"*/
#include <stdio.h>

void removechar(char *str, char c){
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == c){
            for(int j = i ; str[j] != '\0'; j++){
            str[j] = str[j+1];
        }
        i--;
        }
    }
}

int main(){
    char string[99];
    char c;
    printf("\nInsira a string:\n");
    scanf(" %98[^\n]",string);
    printf("\nInsira o caracter a ser removido:\n");
    scanf(" %c",&c);
    removechar(string,c);
    printf("\n%s",string);
    return 0;
}