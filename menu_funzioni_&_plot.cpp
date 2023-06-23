#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define DIM 10000

double f(double x, int param){
    switch(param){
        case 1: return sin(x);
        case 2: return 1/(1+pow(x,2));
        case 3: return fabs(sin(x));
        case 4: return pow(x, 3);
        case 5: return exp(-x/2)*sin(5*x);
    }
    return 0;
}

void print_vector(int n, double v[DIM]){
	for (int i=0; i<n; i++){
		printf("\t%lf\n", v[i]);
	}
	return;
}

void gen_xaxis(double a, double b, int N, double xaxis[DIM]){
    double dx = fabs(a-b)/N;
    for (int i=0; i<N; i++){
        xaxis[i] = a +i*dx;
    }
}

void gen_yaxis(int N, double xaxis[DIM], double yaxis[DIM], int choice){
    for (int i=0; i<N; i++){
        yaxis[i] = f(xaxis[i], choice);
    }

}

void gen_datafile(int N, double xaxis[DIM], double yaxis[DIM]){
    FILE *fp;
    fp = fopen("tabella.txt", "w");
    for (int j=0; j<N; j++){
        fprintf(fp, "%lf \t %lf \n", xaxis[j], yaxis[j]);
    }
    fclose(fp);
}

void gen_cmdfile(){
    FILE *fp;
    fp = fopen("cmd.txt", "w");
    fprintf(fp, "plot \"tabella.txt\" with lines linecolor 7 \npause(-1)");    
    fclose(fp);
}


int main(){
    int N;
    double a, b;
    double assex[DIM], assey[DIM];
    int choice;
    printf("inserisci N, a, b");
    scanf("%d", &N);
    scanf("%lf", &a);
    scanf("%lf", &b);
    printf("menu \n 1) sin(x)\n 2) 1/(1+x^2)\n 3) |sin(x)|\n 4)x^3\n 5) e^-x/2 sin(5x)\n >> ");
    scanf("%d", &choice);

    gen_xaxis(a, b, N, assex);

    gen_yaxis(N, assex, assey, choice);

    gen_datafile(N, assex, assey);

    gen_cmdfile();

    system("gnuplot cmd.txt");
    return 0;
}