#include <stdio.h>

float quadrado(float x){
    return x*x;
}

int is_letter(int x){
    return x >= 'a' && x <= 'z';
}
int main(){
    char a;
    scanf("%c",&a);
    if(is_letter(a) == 1){
        printf("\n %c '%d' eh uma letra",a,a);
    }
    else{
        printf("\n %c nao eh uma letra",a);
    }
    return 0;
}