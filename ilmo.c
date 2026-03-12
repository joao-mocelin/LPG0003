/*
Leia o nome e o sexo de uma pessoa,
apresentando como saída uma das seguintes
mensagens: “Ilmo. Sr.”, para o sexo masculino,
ou a mensagem “Ilma. Sra.”, para o sexo
feminino, seguida do seu nome. 
*/
#include <stdio.h>

int main(){
    int gender = 0;
    char nome[10] = {0};
    printf("\nQual seu nome? ");
    scanf("\n %s", nome);
    printf("\nQual seu genero? /t (0)Masculino /t (1)Feminino ");
    scanf("%d", &gender);
    switch (gender)
    {
    case 0:
        printf("\n Ilmo. Sr. %s", nome);
        break;
    case 1:
        printf("\n Ilma. Sra. %s", nome);
        break;
    default:
        printf("\nErro!");
        break;
    }
    return 0;
}