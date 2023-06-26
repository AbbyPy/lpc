#include <stdio.h>
#include <math.h>

double f(double x){
    double k = (-1./2*x) + x;
    return k;
}

void fixedpoint(double &inn){
    int k=0;
    do{
        inn = f(inn);
        k++;
    }while(k<20);
}

int main(){
    double inn;
    printf("inserire punto di innesco: ");
    scanf("%lf", &inn);
    fixedpoint(inn);
    printf("lo zero sta in (%lf,0)\n", inn);
}