#include <stdlib.h>
#include <stdio.h>
#define DIM 100


// legge un vettore con n entrate
void read_vector(int n, double v[DIM]){
	for (int i=0; i<n; i++){
		scanf("%lf", &v[i]);
	}
	return;
}


// stampa un vettore con n entrate
void print_vector(int n, double v[DIM]){
	for (int i=0; i<n; i++){
		printf("\t%lf\n", v[i]);
	}
	return;
}


// legge da tastiera matrice m righe x n colonne
void read_matrix(int m, int n, double A[][DIM]){
	for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
			scanf("%lf", &A[i][j]);
	return;
}

// stampa a video una matrice m righe x n colonne
void print_matrix(int m, int n, double A[][DIM]){
	for (int i=0; i<m; i++){
		printf("\n\t");
		for (int j=0; j<n; j++){
			printf("%lf\t", A[i][j]);
		}
	}
	return;
}


/*
 * legge da file una matrice, il numero di righe m e di colonne n deve
 * essere passato per indirizzo.
 * ecco un file di esempio filematrice.txt
 *			2  <-- # di righe
 *			3  <-- # di colonne
 *			1.1 2.2 3.3
 *			3.1 5.0 9.9	
 */
void read_matrix_file(int &m, int &n, double A[][DIM]){
	char path[DIM];
	FILE *fp;

	printf("inserisci indirizzo del file matrice: ");
	scanf("%s", path);

	fp = fopen(path, "r");
	fscanf(fp, "%d", &m);
	fscanf(fp, "%d", &n);

	for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
			fscanf(fp, "%lf", &A[i][j]);
	fclose(fp);
	return;
}


// moltiplica matrice mxn con vettore n-dim
// (il risultato e un vettore m-dim)
void matrix_dot_vector(int m, int n, double A[][DIM], double v[DIM], double r[DIM]){	
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			r[i]+=A[i][j]*v[j];
		
	return;
}

// moltiplica una matrice mxn con una nxp e restituisce una matrice mxp
void matrix_dot_matrix(int m, int n, int p, double A[][DIM], double B[][DIM], double C[][DIM]){
	for (int i=0; i<m; i++)
		for (int j=0; j<p; j++)
			for (int r=0; r<n; r++)
				C[i][j] += A[i][r]*B[r][j];
	return;
}


/*
  risolve il sistema A·x=b dove,
        -n è l'ordine della matrice
        -A è una matrice triangolare superiore nxn di rango massimo
        -b è il vettore dei termini noti
        -xi è il vettore in cui viene inserita la soluzione del sistema
*/
void upper_solver(int n, double A[][DIM], double b[DIM], double xi[DIM]){
    double r;
    for (int i= n-1; i>=0; i--){
        r = 0;
        for (int j= i+1; j<n; j++){
            r += A[i][j]*xi[j];
        }
        xi[i] = (b[i]- r)/A[i][i];        
    }
    return;
}


int main(){
	int n;
	int m;
	int p;
	double A[DIM][DIM], B[DIM][DIM], C[DIM][DIM];


	read_matrix_file(m, n, A);
	read_matrix_file(n,p,B);
	matrix_dot_matrix(m,n,p, A, B, C);
	print_matrix(m, p, C);
	
	return 0;
}
