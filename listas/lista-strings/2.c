/*
Modifique o código da questão anterior fazendo com que o programa determine quantas
vezes o caractere ocorre na string
*/
#include <stdio.h>

int contain(char *str, char key){
    int cont = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == key){
            cont++;
        }
    }
    return cont;
}

int main(){
    char string[99];
    char key;
    printf("\nInsira a string:\n");
    scanf(" %98[^\n]",string);
    printf("\nInsira a chave de busca:\n");
    scanf(" %c",&key);  //DEIXA ESSE ESPAÇO AI MERMAO
    int teste = contain(string,key);
    if(teste > 0){
        printf("\nA string '%s' contem a chave '%c' e aparece %d vezes",string, key, teste);
    }
    else{
        printf("\nA string '%s' nao contem a chave '%c'",string, key);
    }
    return 0;
}