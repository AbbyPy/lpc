#include<stdio.h>
#include<math.h>
#define NMAX 100


int main(){
    FILE *p;
    p= fopen("testo.txt","r");
    double A[NMAX][NMAX];
    int n;
    int m;
    fscanf(p, "%d", &n);
    fscanf(p, "%d", &m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            fscanf(p, "%lf",&A[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf( "%lf ",A[i][j]);
        }
        printf("\n");
    }
}