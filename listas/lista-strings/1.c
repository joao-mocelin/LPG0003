/*
Dados uma string s e um caractere c faça um programa que verifique se s contém c. Dica: a
implementação dentro de uma função facilita a definição da solução.
*/
#include <stdio.h>

int contain(char *str, char key){
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == key){
            return 1;
        }
    }
    return 0;
}

int main(){
    char string[99];
    char key;
    printf("\nInsira a string:\n");
    scanf(" %98[^\n]",string);
    printf("\nInsira a chave de busca:\n");
    scanf(" %c",&key);  //DEIXA ESSE ESPAÇO AI MERMAO
    if(contain(string,key) == 1){
        printf("\nA string '%s' contem a chave '%c'",string,key);
    }
    else{
        printf("\nA string '%s' nao contem a chave '%c'",string, key);
    }
    return 0;
}