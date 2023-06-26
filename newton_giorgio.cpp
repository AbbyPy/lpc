#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double f(double x){
	double y;
	y = (x-1)*(x-100);
	return y;
}

double df(double x){
	double y;
	y = x-100+x-1;
	return y;
}

double phi(double x){
	double y;
	y = x-(f(x)/df(x));
	return y;
}

// criterio di arresto: |f(x_k)| < tolly
double newton_tolly(double x0, double tolly){
	double xk, ek;
	xk = x0;
	do{
		xk = phi(xk);
		ek = fabs(f(xk));
		printf("%lf \t errore: %lf\n", xk, ek);
	} while (ek >= tolly);
	return xk;
}

// criterio di arresto: |x_(k-1) - x_k| < tollx
double newton_tollx(double x0, double tollx){
	double xj, xk, ek;
	xj = x0;
	xk = x0;
	do{
		xk = phi(xk);
		ek = fabs(xk - xj);
		printf("%lf \t errore: %lf\n", xk, ek);
		xj=xk;
	} while (ek >= tollx);
	return xk;
}


// criterio di arresto: |x_k - radice| < toll
// viz. radice appartiene a un intorno di x_k di raggio toll/2
double newton_toll(double x0, double toll){
	double xk, ek;
	bool stop;
	xk = x0;
	do{
		xk = phi(xk);
		printf("%lf\n", xk);
		stop = (f(xk -0.5*toll)*f(xk +0.5*toll) >= 0);
	} while (stop);
	return xk;
}


int main(){
	double r;
	r = newton_toll(1000000, 0.00001);
	printf("%lf", r);
	return 0;
}
