#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define NMAX 100

void matrandom(int n, double A[][NMAX]){
    srand(time(NULL));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) A[i][j]=10*(rand()/(double)RAND_MAX);
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

void function(int n, double A[][NMAX], int c, int &m1, int &m2,int &M1, int &M2, double &a){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(A[i][j]<A[m1][m2]){
                m1=i;
                m2=j;
            } 
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(A[i][j]>A[M1][M2]){
                M1=i;
                M2=j;
            } 
        }
    }
    double temp=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(fabs(c-A[i][j])>=temp){
                a=A[i][j];
                temp=fabs(c-A[i][j]);
            }
        }
    }
}

int main(){
    int n; double c, a, A[NMAX][NMAX];
    int m1=0, m2=0, M1=0, M2=0;
    printf("inserisci n\n");
    scanf("%d", &n);
    printf("inserisci c\n");
    scanf("%lf", &c);
    matrandom(n, A);
    stampamat(n, n, A);
    function(n, A, c, m1, m2, M1, M2, a);
    printf("Il minimo e' A[%d][%d]= %lf \nil massimo e' A[%d][%d]= %lf\n", m1, m2, A[m1][m2], M1, M2, A[M1][M2]);
    printf("a e' %lf\n", a);
    return 0;
}