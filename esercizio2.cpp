#include<stdio.h>
#include<math.h>
#include<time.h>
#define NMAX 100
void matpervet(int n, double A[][NMAX], double v[], double c[]){
    double somma;
    for(int i=0;i<n;i++){
        somma=0;
        for(int j=0;j<n;j++){
            somma=somma+A[i][j]*v[j];
        }
       c[i]=somma; 
    }
    return;
}
void matricerandom(int n,double A[][NMAX]){
    srand(time(NULL));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A[i][j]=rand()%10;
        
        }
    }
    return;
}
void randomvet(int n,double v[]){
    for(int i=0;i<n;i++){
        v[i]=rand()%10;
        printf("%lf\n",v[i]);
    }
}


void function(int d, double A[][NMAX],double z[],double g,double c[]){
    
    matpervet(d,A,z,c);
    for(int i=0;i<d;i++){
        c[i]=g*c[i];
    }
    for(int i=0;i<d;i++){
        c[i]=c[i]+(1-g)*z[i];
    }
    return;

}

int main(){
    int d;
    double A[NMAX][NMAX],z[NMAX],result[NMAX],gamma;
    printf("inserisci la dimensione della matrice:\n");
    scanf("%d",&d);
    printf("scegli il valore di gamma:\n");
    scanf("%lf",&gamma);
    matricerandom(d,A);
    printf("la matrice e':\n");
    for(int i=0;i<d;i++){
        for(int j=0;j<d;j++){
            printf("%lf ",A[i][j]);
        }
        printf("\n");
    }
    printf("il vettore e':\n");
    randomvet(d,z);
    function(d,A,z,gamma,result);
    printf("\nil risultato e':\n");
    for(int i=0;i<d;i++){
        printf("v[%d]=%lf\n",i,result[i]);
    }

 return 0;
}