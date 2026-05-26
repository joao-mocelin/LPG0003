#include <stdio.h>


int main(){
    int *p = NULL; //ponteiro p (unsinged long int 64 bits) * indica que é um ponteiro;
    // & retorna o endereço da variavel na memória; * retorna o valor que de fato está presente em determinado endereço (operador de indireção)
    printf("\n%p",&p);
    // p = &x -> p passa a apontar para x
    // *p = 0 -> o valor para qual p aponta se torna 0, ou seja, x = 0
    // p = 0 -> endereço = null, ou seja, p não aponta mais para x
    int a = 0;
    p = &a;
    printf("\n%d",*p);
    *p = 2;
    printf("\n%d",*p);
    scanf("%d",p); // scanf um valor para a

    return 0;
}