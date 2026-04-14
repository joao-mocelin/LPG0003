#include <stdio.h>

int binarySearch(int *v, int n, int key){
    int ini = 0, fim = n - 1, meio;
    do{
        meio = (ini + fim) / 2;
        if(v[meio] == key){
            return meio;
        }
        if(v[meio] > key){
            fim = meio - 1;
        }
        else{
            ini = meio + 1;
        }
    }while(ini <= fim);
    return -1;
}

int main(){
    int v[10] = {1,2,3,4,5,6,7,8,9,10};
    int chave = binarySearch(v,10,9);
    printf("\n v[%d]",chave);
    return 0;
}