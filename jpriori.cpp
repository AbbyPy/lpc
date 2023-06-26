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

double lambda1(double A[][NMAX], int n){
    double lambda = 0, sum;
    
    for( int i = 0; i < n; i++){
        sum = 0;
        for(int j = 0; j < n; j++){
            if(i != j){
                sum += fabs(A[i][j]/A[i][i]);
            }
        }
        if (sum > lambda){
            lambda = sum;
        }
    }
    return lambda;
}

double priori(double xcheck[], double xnew[], int n, double toll, double lambda, double delta){
    double k = log(toll*(1-lambda)/(delta))/log(lambda);
    return k;
}

 void jacobi(double A[][NMAX], double x[], double xnew[], double b[], int n, double toll, double lambda){
    double temp, xcheck[NMAX], delta = 0, q;
    int k = 0, contatore;
    for (int i=0; i<n; i++){
        x[i]=0;
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
        xcheck[i] = x[i];
        x[i] = xnew[i];
    }
    if(k == 0){
        for(int i = 0; i < n; i++){
            q = xcheck[i] - xnew[i];
            if(fabs(q) > delta){
                delta = fabs(q);
            }
        }
        contatore = priori(xcheck, xnew, n, toll, lambda, delta);
    }
    k++;
    stampavett(n, xnew);
    }while(k < contatore);

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
	double b[NMAX], x[NMAX], xnew[NMAX], toll;
	double A[NMAX][NMAX];
	printf("inserisci rango della matrice/numero componenti del vettore b\n");
	scanf("%d", &n);
	printf("inserisci componenti matrice\n");
	leggimat(n, n, A);
	printf("inserisci componenti vettore\n");
	leggivett(n, b);
    printf("inserisci tolleranza: ");
    scanf("%lf", &toll);
    double lambda = lambda1(A, n);
	jacobi(A, x, xnew, b, n, toll, lambda);
	stampavett(n, xnew);
	return 0;
}