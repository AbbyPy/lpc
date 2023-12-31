#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// nella funzione f inserire la funzione di cui si cerca la radice
// ad esempio: exp(x)-2
double f(double x){
	return (exp(x) -2);
}

//metodo di bisezione con criterio di arresto a priori sul numero di iterazioni
// nell'intervallo [a0, b0] con tolleranza toll
double bisez(double a0, double b0, double toll){
	int k=0;
	double a, b, c, stop;
	
	a = a0;
	b = b0;
	stop = (log((b0-a0)/toll))/log(2);
	while (k <= stop){
		c = 0.5*(a + b);
		if (fabs(f(c)) == 0) break;
		if (f(a)*f(c)<0) b = c;
		if (f(c)*f(b)<0) a = c;
		k++;
	}
	printf("n. iter: %d \t errore: %lf \t tolleranza: %lf\n", k, f(c), toll);
	return c;
}

int main(){
	double alpha, err;
	printf("cerco gli zeri di f(x) = e^x - 2 in [0, 20]\n");
	alpha = bisez(0, 20, 0.000001);
	err = fabs(f(alpha));
	printf("la radice e' %lf con un errore di %lf", alpha, err);
	return 0;
}
