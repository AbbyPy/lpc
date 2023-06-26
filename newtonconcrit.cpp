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
    double toll;
    printf("inserisci punto di innesco\n");
    scanf("%lf",&x);
    printf("inserisci la tolleranza\n");
    scanf("%lf", &toll);
    int k=0;
    do{
        x= x-funzione(x)/derivata(x);
        k++;
    }while(fabs(funzione(x))>toll);
    printf("%lf ",x);
}

// in alternativa mettere come condizione del do-while [funzione(x+toll/2)*funzione(x-toll/2)]>=0