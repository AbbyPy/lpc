/*
Riduzione a Scala - metodo di Gauss
per matrici quadrate non singolari
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIM 100

int read_matrix(double A[DIM][DIM]){
    int n;
    printf("inserisci dimensione della matrice (quadrata)");
    scanf("%d", &n);

    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%lf", &A[i][j]);
        }
    }
    return n;
}

void print_matrix(double A[DIM][DIM], int n){
    for (int i=0; i<n; i++){
        printf("\n");
        for (int j=0; j<n; j++){
            printf("%lf \t", A[i][j]);
        }
    }
    printf("\n");
}

void gauss(double A[DIM][DIM], int n){
    int k = 0;
    int i, r;
    double molt;

    for (k; k<n; k++){
        for (i=k+1; i<n; i++){
            molt = A[i][k] / A[k][k];
            for(r=k; r<n; r++){
                A[i][r] = A[i][r]- molt*A[k][r];
            }
        }
    }
}

int main(){
    int n;
    double A[DIM][DIM];
    n = read_matrix(A);
    print_matrix(A, n);

    gauss(A, n);
    print_matrix(A,n);
    return 0;

}
