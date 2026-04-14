#include <stdio.h>

int main(){
    int v[10] = {9,2,3,4,6,1,7,8,10,5};
    int aux;
    
    for(int i = 0; i < 10 - 1; i++){
        int swap = 0;
        for(int j = 0; j < 10 - i - 1; j++){
            if(v[j] > v[j+1]){
                aux = v[j+1];
                v[j+1] = v[j];
                v[j] = aux;
                swap = 1;
            }
        }
        if(swap == 0){
            break;
        }
    }
    for(int i = 0; i < 10; i++){
        printf("\n %d",v[i]);
    }
    return 0;
}