#include <stdio.h>
#define NMAX 100

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
    return;
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

int main(){
    int n, m;
    double A[NMAX][NMAX], v[NMAX], sol[NMAX];
    printf("inserisci numero di righe di A\n");
    scanf("%d", &n);
    printf("inserisci numero di colonne di A e dimesione di v\n");
    scanf("%d", &m);
    printf("inserisci componenti matrice\n");
    leggimat(n, m, A);
    printf("inserisci componenti vettore\n");
    leggivett(m, v);
    matpervett(n, m, A, v, sol);
    stampavett(m, sol);
    return 0;
}