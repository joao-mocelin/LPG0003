#include <stdio.h>

int fib(long int n, long long int v[]){
    if(n<=2){
        v[n-1] = 1;
        return 1;
    }
    if(v[n-1] == 0){
        v[n-1] = fib(n-1,v) + fib(n-2,v);
    }
    return v[n-1];
    
    
}


int main(){
    long long int v[92] = {0};
    long int x = fib(82,v);
    printf("%lli",x);
    return 0;
}


