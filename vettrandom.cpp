#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NMAX 100

int main (){
int n;
double v[NMAX];
int V[NMAX];
srand(time(NULL));
printf("Inserisci la dimensione del vettore\n");
scanf("%d", &n);
for(int i=0; i<n ; i++){
V[i]=rand()%10; // numeri pseudo random interi compresi tra 0 e 9
v[i]=rand()/(double)RAND_MAX; // numero pseudo random reali tra 0 e 1
}
printf("Numeri random interi tra 0 e 10\n");
for(int i=0; i<n; i++)
printf("%d ", V[i]);
printf("Numeri random reali tra 0 e 1\n");
for(int i=0; i<n; i++)
printf("%lf ", v[i]);
return(0);
}

