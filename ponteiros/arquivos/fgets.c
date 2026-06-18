#include <stdio.h>
#include <stdlib.h>



int main(){

    FILE *f = fopen("C:\\code\\lpg2026\\ponteiros\\arquivos\\strings.txt", "rt");
    if(f == NULL){
        printf("\nERRO!");
        return 1;
    }

    char temp[1024];
    int cont = 1;
    while (fgets(temp,1024,f) != NULL) //o fgets lê o \n ao final da linha
    {
        printf("[%d] %s",cont,temp); //devido ao fgets nao usamos \n aqui
        cont++;
    }
    

    return 0;
}