#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int mat[20][20];
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            mat[i][j] = rand() % 100;
        }
    }

    for(int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++)
        {
            printf("%4d",mat[i][j]);
        }
        printf("\n");        
    }
    return 0;
}