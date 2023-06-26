#include <stdio.h>
#include <math.h>
#define NMAX 100

void stampavett (int n , double a[NMAX]){
    for(int i=0; i<n; i++){
     printf("%lf ", a[i]);
     }
	 printf("\n");
    return ;
}

 void jacobi(double A[][NMAX], double x[], double xnew[], double b[], int n){
    double temp;
    int k = 0;
    for (int i=0; i<n; i++){
        x[i]=0;
    }
    for (int i=0; i<n; i++){
        xnew[i] = x[i];
    }


    do{

        for (int i = 0; i<n; i++){
        temp = b[i]/A[i][i];
            for(int j=0; j<n; j++){
            if(j!=i){
                temp += -A[i][j]/A[i][i]*x[j];
            }
        }
        xnew[i] = temp;
    }
    
    for (int i = 0; i < n; i++){
        x[i] = xnew[i];
    }
    k++;
    stampavett(n, xnew);
    }while (k<100);

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



int main(){
	int n;
	double b[NMAX], x[NMAX], xnew[NMAX];
	double A[NMAX][NMAX];
	printf("inserisci rango della matrice/numero componenti del vettore b\n");
	scanf("%d", &n);
	printf("inserisci componenti matrice\n");
	leggimat(n, n, A);
	printf("inserisci componenti vettore\n");
	leggivett(n, b);
	jacobi(A, x, xnew, b, n);
	stampavett(n, xnew);
	return 0;
}