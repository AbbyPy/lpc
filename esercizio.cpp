#include<stdio.h>
#include<math.h>
#define NMAX 100
void mattpervett(int n,double A[][NMAX],double x[],double y[]){
    for(int i=0;i<n;i++){
        y[i]=0;
        for(int j=0;j<n;j++){
            y[i]= y[i]+ A[i][j]*x[j];
        }
    }

    
    
}
void succession(int n,double A[][NMAX],double x[],double y[]){
    double k[n];
    mattpervett(n, A, x, k);
    for(int i=0;i<n;i++){
        y[i]= x[i]-k[i];
    }

}
void funzione(int n, double A[][NMAX],double x[],double z){
double h[NMAX];
mattpervett(n, A, x, h);
for(int i=0;i<n;i++){
    z= z+ x[i]+h[i];
    printf("%lf",z);
}


}






int main(){
    int n;
    double z=0;
    double y[NMAX];
    do{ printf("inserisci n\n");
        scanf("%d",&n);
    }while(n>20 || n<0);
    double A[NMAX][NMAX];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j<=i){ 
                printf("inserisci le componenti della matrice A\n");
                scanf("%lf",&A[i][j]);
            }else A[i][j]=0;
        }

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>i){
                A[i][j]= A[i][j]+A[j][i];
            }
        }
    } 
    double x[NMAX];
    for (int i=0;i<n;i++){
            printf("inserisci le componenti di x\n");
            scanf("%lf",&x[i]);
    }int k=0;
    do{
        succession(n, A, x, y);
        k++;
        for(int i=0;i<n;i++){
            printf("%lf ", y[i]);
        }
        printf("\n");
        for(int j=0;j<n;j++){
            x[j]=y[j];
        }

    }while(k<2);
}