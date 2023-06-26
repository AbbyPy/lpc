#include <stdio.h>
#include <math.h>
#define NMAX 100

double F (double x){
    return exp(x);
}

double Lagrange (double x, double nodi[], int n){
double li;
double polint=0;
for(int i=0; i<=n; i++){
li=1;
for(int k=0; k<=n; k++){
if(i != k)
li=li*(x-(nodi[k]))/((nodi[i])-(nodi[k]));
}
polint=polint+F(nodi[i])*li ;
}
return (polint);
}


int main(){
    int n;
    double a, b, z, h, x[NMAX];
    printf("inserisci n\n");
    scanf("%d", &n);
    printf("inserisci gli estremi dell' intervallo\n");
    scanf("%lf %lf", &a, &b);
    printf("inserisci z\n");
    scanf("%lf", &z);
    h=(b-a)/n;
    for(int i=0; i<=n; i++) x[i]=a+i*h;
    double k;
    k=Lagrange(z, x, n);
    printf("%lf\n", k);
}