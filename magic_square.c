#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// v vettore lungo n; returna true se v puo essere riga o colonna di un quadrato magico
bool check(int * v, int n){
        int * marker;
        int i;

        marker = malloc(n*sizeof(int));
        memset(marker, 0, n);
        for (i =0; i<n; i++)
                marker[v[i]] ++;
        for (i =0; i<n; i++)
                if (marker[i] > 1) return false;
        return true;
}

void print(int *vec, int dim){
        for (int i=0; i<dim; i++)
                printf("%d ", vec[i]);
}

bool magic(int * mat, int n){
        int *w;
        int k,j;
        w = malloc(n*sizeof(int));

        // scorre le righe con l'indice 0 <= k <= n-1
        for (k=0; k<n; k++){
                for (j=0; j<n; j++){
                        w[j] = mat[k*n + j];
                }

                if (!(check(w, n))) return false;
        }


        // scorre le colonne con l'indice k
        for (k =0; k<n; k++){
                for (j=0; j<n; j++){
                        w[j] = mat[k + j*n];
                }
                if (!(check(w,n))) return false;
        }
        return true;
}

int main(){

        int *mat;
        int n;

        scanf("%d ", &n);
        mat = malloc((n*n-1)*sizeof(int));
        for (int i=0; i<n*n-1; i++){
                scanf("%d ", &mat[i]);
        }
        scanf("%d", &mat[n*n-1]);

        if (magic(mat, n)) printf("SI");
        else printf("NO");
        return 0;
}
