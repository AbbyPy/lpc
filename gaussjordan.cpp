#include <stdlib.h>
#include <stdio.h>
#define NMAX 100

void gaussjordan (double A[][NMAX], double Ainv[][NMAX], int n){
	double m;
	for(int i = 0; i < n; i++){ /*inizializzo la matrice inversa all'identità*/
		for(int j = 0; j < n; j++){
			if (i == j) {
				Ainv[i][i] = 1;
			}else{
				Ainv[i][j] = 0;
			}
		}
	}
	
	for (int k=0; k<n-1; k++){ /*utilizzo l'equivalente del MEG su entrambe le matrici*/
		for (int i=k+1; i<n; i++){
		m= A[i][k]/A[k][k];
		for(int j=0; j<n; j++){
			A[i][j]=A[i][j]-m*A[k][j];
			Ainv[i][j]=Ainv[i][j]-m*Ainv[k][j];
		}
	}}
	
	for (int k=n-1; k > 0; k--){ /*utilizzo l'equivalente del MEG al contrario*/
		for (int i = k-1; i >= 0; i--){
			m = A[i][k]/A[k][k];
			for(int j=0; j<n; j++){
				A[i][j]-=m*A[k][j];
				Ainv[i][j]-=m*Ainv[k][j];
			}
		}
	}
	
	for(int i = 0; i < n; i++){ /*rendo gli elementi sulla diagonale 1*/
		m = 1/A[i][i];
		for (int j = 0; j < n; j++) {
			A[i][j] *= m;
			Ainv[i][j] *= m;
		}
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
 
int main(){
	int n;
	double A[NMAX][NMAX], Ainv[NMAX][NMAX];
	printf("inserisci rango della matrice\n");
	scanf("%d", &n);
	printf("inserisci componenti matrice\n");
	leggimat(n, n, A);
	gaussjordan(A, Ainv, n);
	printf("la matrice inversa e': ");
	stampamat(n, n, Ainv);
	printf("\n");
	return 0;
}
