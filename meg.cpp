#include <stdlib.h>
#include <stdio.h>
#define NMAX 100

void meg (double A[][NMAX], double b[], int n){
	double m;
	for (int k=0; k<n-1; k++){
		for (int i=k+1; i<n; i++){
		m= A[i][k]/A[k][k];
		for(int j=0; j<n; j++){
			A[i][j]=A[i][j]-m*A[k][j];
		}
		b[i]=b[i]-b[k]*m;
	}}
	return;
}

void leggivett(int n, double v[NMAX]){
    for(int i=0; i<n; i++) scanf("%lf", &v[i]);
    return;
}

void leggimat(int n, int m, double A[][NMAX]){
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++) scanf("%lf", &A[i][j]);
	}
	return;
}

void stampamat(int n, int m, double a[][NMAX]){
		printf("\n");
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++)  printf("%lf ", a[i][j]);
    	printf("\n");
    }
	printf("\n");
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
	int n;
	double b[NMAX];
	double A[NMAX][NMAX];
	printf("inserisci rango della matrice/numero componenti del vettore b\n");
	scanf("%d", &n);
	printf("inserisci componenti matrice\n");
	leggimat(n, n, A);
	printf("inserisci componenti vettore\n");
	leggivett(n, b);
	stampamat(n, n, A);
	stampavett(n, b);
	meg(A, b, n);
	stampamat(n, n, A);
	stampavett(n, b);
	return 0;
}
