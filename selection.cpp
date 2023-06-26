#include <stdlib.h>
#include <stdio.h>
#define NMAX 100

void leggivett(int n, double v[NMAX]){
    for(int i=0; i<n; i++) scanf("%lf", &v[i]);
    return;
}

void stampavett (int n , double a[NMAX]){
    for(int i=0; i<n; i++){
     printf("%lf ", a[i]);
     }
         printf("\n");
    return ;
}

int main(){
    int n; double v[NMAX], aux;
    printf("inserisci le dimensioni del vettore\n");
    scanf("%d", &n);
    printf("inserisci componenti vettore\n");
    leggivett(n, v);
    for(int i=0; i<n; i++){
        int imin=i;
        for(int j=i+1; j<n; j++){
            if(v[j]<v[imin]) imin=j;}
            aux=v[i];
            v[i]=v[imin];
            v[imin]=aux;
        }
        stampavett(n, v);
    }
