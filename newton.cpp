#include<stdio.h>
#include<math.h>
#define NMAX 100
double funzione(double x){
    return exp(x)-2;
}
double derivata(double x){
    return exp(x);
}
int main(){
    double x;
    printf("inserisci punto di innesco\n");
    scanf("%lf",&x);
    int k=0;
    do{
        x= x-funzione(x)/derivata(x);
        k++;
    }while(k<100);
    printf("%lf",x);
}