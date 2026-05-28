#include <stdio.h>
#include <math.h>

void bhaskara(int a, int b, int c, double *x1, double *x2){
    int delta = (b * b) - (4 * a * c);
    if (delta < 0) {
        *x1 = 0;
        *x2 = 0;
        return;
    }
    *x1 = (-b + sqrt(delta)) / (2 * a);
    *x2 = (-b - sqrt(delta)) / (2 * a);
}

int main(){
    int a,b,c;
    double x1,x2;
    printf("\ninsira a b c (1 -6 12):\n");
    scanf("%d %d %d",&a,&b,&c);
    bhaskara(a,b,c,&x1,&x2);
    printf("\nx1 = %lf",x1);
    printf("\nx2 = %lf",x2);
    return 0;
}
