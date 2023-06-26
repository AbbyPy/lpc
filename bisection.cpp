#include <stdio.h>
#include <math.h>

double f(double x){
    double k = exp(x) -2;
    return k;
}

void bisezione(double a, double b){
    double c= (a+b)/2;
    for(int i=0;i<100;i++){
        if(f(c)*f(a)<0){
            b=c;
        }else if(f(c)*f(b)<0){
            a=c;
        }else{ printf("%lf é lo zero\n",c);
               return;}
        c= (a+b)/2;
    }
    printf("%lf",c);
}
int main(){
    double a, b;
    printf("inserisci a e b \n");
    scanf("%lf",&a);
    scanf("%lf",&b);
    bisezione(a,b);
    return 0;
}