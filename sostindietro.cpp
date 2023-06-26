#include <stdlib.h>
#include <stdio.h>
#include<math.h>
#define NMAX 100

void meg (double A[][NMAX], double b[], int n){
	double m;
	for (int k=0; k<n-1; k++){
		for (int i=k+1; i<n; i++){
		m= A[i][k]/A[k][k];
		for(int j=k; j<n; j++){
			A[i][j]=A[i][j]-m*A[k][j];
		}
		b[i]=b[i]-b[k]*m;
	}}
	return;
}

void sostindietro(int n, double A[][NMAX], double b[], double x[]){
	double variabile;
	x[n-1]=b[n-1]/A[n-1][n-1];
	for(int i=n-2; i>=0; i--){
		variabile=0;
		for(int j=n-2; j>=0; j--){
			variabile= variabile + A[i][j+1]*x[j+1];
		}
		x[i]=(b[i]-variabile)/A[i][i];
	}
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

void matpervett(int n, int m, double A[][NMAX], double v[], double sol[]){
    for(int i=0; i<n; i++){
        sol[i]=0;
        for(int j=0; j<m; j++){
            sol[i]+=v[j]*A[i][j];
        }
    }
    return ;
}

double residuo(int n, double b[], double A[][NMAX], double x[]){
	double r[NMAX];
	matpervett(n,n,A,x,r);
	for(int i=0;i<n;i++){
		r[i]=b[i]-r[i];
	}
	double max=fabs(r[0]);
	
	for(int i=1;i<n;i++){
		if(fabs(r[i])>max){
			max=fabs(r[i]);	
		}
	}
    return(max);
}
 
int main(){
	int n;
	double r;
	double b[NMAX], x[NMAX];
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
	sostindietro(n, A, b, x);
	printf("il vettore soluzione e'\n");
	stampavett(n, x);
    r=residuo(n,b,A,x);
	printf("il residuo e':%lf",r);
	return 0;
}
