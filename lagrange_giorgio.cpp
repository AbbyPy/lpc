#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DIM 10000


void print_vector(int n, double v[DIM]){
	for (int i=0; i<n; i++){
		printf("\t%lf\n", v[i]);
	}
	return;
}

double f(double x, int choice){
    switch(choice){
        case 1: return sin(x);
        case 2: return 1/(1+pow(x,2));
        case 3: return fabs(sin(x));
        case 4: return pow(x, 3);
        case 5: return exp(-x/2)*sin(5*x);
    }
    return 0;
}

void gen_assi(double a, double b, int k, double assex[DIM]){
    for (int p=0; p<k+1; p++){
        assex[p] = a + p* fabs(b-a)/(k+1);
    }
}



double lagrange(double x, int n, double assex[DIM], int choice){
    double poly = 0;
    double li;
    for (int i=0; i<=n; i++){
        li = 1;
        for (int j=0; j<= n; j++){
            if (j != i){
                li *= (x - assex[j]) / (assex[i] - assex[j]);
            }
        }
        poly += f(assex[i], choice)*li;
    }
    return poly;
}

void datafile(int m, double assebis[DIM], int n, double assex[DIM], int choice){
    double y1, y2, x, err, errmax;
    errmax = 0;
    FILE *fp;
    FILE *fpp;
    fp = fopen("dati.dat", "w");
    for (int k=0; k<= m; k++){
        x = assebis[k];
        y1 = lagrange(x, n, assex, choice);
        y2 = f(x, choice);
        err = fabs(y1 - y2);
        if (err >= errmax) {errmax = err;}
        fprintf(fp, "%lf \t %lf \t %lf \n", x, y1, y2);
    }
    fclose(fp);
    printf("l'errore massimo e' %lf", errmax);
}

void gen_cmdfile(){
    FILE *fp;
    fp = fopen("cmd.txt", "w");
    fprintf(fp, "plot \"dati.dat\" using 1:2 title \"Lagrange\" with lines, \"\" using 1:3 title \"Funzione data\" with lines\npause(-1)");    
    fclose(fp);
}

int main(){
    int m,n, choice;
    double a, b;
    printf("menu \n 1) sin(x)\n 2) 1/(1+x^2)\n 3) |sin(x)|\n 4)x^3\n 5) e^-x/2 sin(5x)\n >> ");
    scanf("%d", &choice);
    printf("inserire n = # di nodi su cui costruire il polinomio di lagrange > ");
    scanf("%d", &n);
    printf("inserire (n<) m = # di nodi con cui graficare il polinomio");
    scanf("%d", &m);
    printf("inserire estremi a, b > ");
    scanf("%lf", &a);
    scanf("%lf", &b);

    double assex[DIM];
    gen_assi(a, b, n, assex);
 

    double assebis[DIM];
    gen_assi(a, b, m, assebis);


    datafile(m, assebis, n, assex, choice);
    gen_cmdfile();
    system("gnuplot cmd.txt");


    return 0;

}
