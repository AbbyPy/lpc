#include <stdlib.h>
#include <stdio.h>
#define NMAX 100

void lu (double A[][NMAX], int n, double L[][NMAX]){
	double m;
	for (int k=0; k<n-1; k++){
		for (int i=k+1; i<n; i++){
		m= A[i][k]/A[k][k];
        L[i][k]=m;
		for(int j=k; j<n; j++){
			A[i][j]=A[i][j]-m*A[k][j];
		}
	}}
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

void matpermat(double A[][NMAX], double B[][NMAX], int ra, int cr, int cb){
    double C[NMAX][NMAX];
    for(int i=0; i<NMAX; i++){
        for(int j=0; j<NMAX; j++){
            C[i][j]=0;
        }
    }
    for(int i=0; i<ra; i++){
        for(int j=0; j<cb; j++){
            for(int k=0; k<cr; k++){
                C[i][j] += A[i][k]*B[k][j];

            }
        }
    }
    for (int i=0; i<ra; i++){
        for (int j=0; j<cb; j++){
            printf("%lf ", C[i][j]);
        }
        printf("\n");
    }

}

int main(){
    int n;
	double A[NMAX][NMAX], L[NMAX][NMAX];
	printf("inserisci rango della matrice/numero componenti del vettore b\n");
	scanf("%d", &n);
	printf("inserisci componenti matrice\n");
    for (int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            if(i==j){
                L[i][i]=1;
            }
            else{
                L[i][j]=0;
            }
        }
    }
	leggimat(n, n, A);
	lu(A, n, L);
	stampamat(n, n, L);
    stampamat(n,n, A);
	matpermat(L, A, n, n, n);
	return 0;
}