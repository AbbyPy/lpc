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
    int n; double v[NMAX];
    printf("inserisci le dimensioni del vettore\n");
    scanf("%d", &n);
    printf("inserisci componenti vettore\n");
    leggivett(n, v);
    int flag=1;
    double aux;
    for(int i=0; i<n-1 && flag==1; i++){
        flag=0;
        for(int j=0; j<n-1-i; j++){
            if(v[j]>v[j+1]){
                flag=1;
                aux=v[j+1];
                v[j+1]=v[j];
                v[j]=aux;
            }
        }
    }
    stampavett(n, v);
}