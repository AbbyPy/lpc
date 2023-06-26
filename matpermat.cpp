#include <stdio.h>
#define NMAX 100

void leggimat(int n, int m, double A[][NMAX]){
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++) scanf("%lf", &A[i][j]);
	}
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
    double A[NMAX][NMAX], B[NMAX][NMAX];
    int ra, cr1, cr2, cb;
    printf("quante sone le righe di A? ");
    scanf("%d", &ra);
    printf("quante sone le colonne di A? ");
    scanf("%d", &cr1);
    printf("quante sone le righe di B? ");
    scanf("%d", &cr2);
    printf("quante sone le colonne di B? ");
    scanf("%d", &cb);
    if(cr1!=cr2){
        printf("vattene affanculo");
        return 0;
    }
    leggimat(ra, cr1, A);
    leggimat(cr2, cb ,B);
    matpermat(A, B, ra, cr1, cb);
    return 0;
}