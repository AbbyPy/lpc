#include <stdlib.h>
#include <stdio.h>
#define NMAX 100

void stampamat(int n, int m, double a[][NMAX]){
		printf("\n");
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++)  printf("%lf ", a[i][j]);
    	printf("\n");
    }
	printf("\n");
    return;
}


void pivoting (double A[][NMAX], double b[], int k, int n){
	int imax=k;
	double temp;
	for(int i=k+1; i<n; i++){
		if(A[i][k]>A[imax][k])
		imax=i;
	}
	for(int i = 0; i<n; i++){
		temp = A[k][i];
		A[k][i]=A[imax][i];
		A[imax][i]=temp;

	}
	temp = b[k];
	b[k]=b[imax];
	b[imax]=temp;
	stampamat(n, n, A); 
}

void meg (double A[][NMAX], double b[], int n){
	double m;
	for (int k=0; k<n-1; k++){
		pivoting(A, b, k, n);
		for (int i=k+1; i<n; i++){
		m= A[i][k]/A[k][k];
		   for(int j=k; j<n; j++){
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
	meg(A, b, n);
	stampamat(n, n, A);
	stampavett(n, b);
	return 0;
}
