#include <stdio.h>

int main(){
    int v[10] = {1,2,3,4,5,6,7,8,9,10};
    int aux, temp;
    for (int i = 0; i < 10; i++)
    {
        aux = i;
        for(int j = i+1;j<10;j++){
            if(v[j] > v[aux]){
                aux = j;
            }
        }
        temp = v[i];
        v[i] = v[aux];
        v[aux] = temp;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("\n %d",v[i]);
    }
    
    return 0;
}