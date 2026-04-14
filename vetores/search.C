#include <stdio.h>

int searchVector(int *v,int n, int key){        //retorna o primeiro índice do vetor onde está o número
    for(int i = 0; i < n; i++){
        if(key == v[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    int v[10] = {1,2,3,4,5,6,7,8,9,10};
    int key = searchVector(v,10,90);
    if(key == -1){
        printf("\n Nao encontrado");
        return 1;
    }
    printf("\n v[%d]",key);
    return 0;
}