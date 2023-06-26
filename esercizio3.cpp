#include<stdio.h>
#include<math.h>
#define NMAX 100

double MA(int n, double z[]){
    double somma=0;
    for(int i=0;i<n;i++){
        somma=somma+z[i]/n;
    }
    return (somma);
}
double MG(int n, double z[]){
    double prodotto=1;
    double result;
    for(int i=0;i<n;i++){
        prodotto=prodotto*z[i];
    }
    result=pow(prodotto,1./n);
    return(result);
}

double MH(int n, double z[]){
    double somma =0;
    double result;
    for(int i=0;i<n;i++){
        somma=somma+1/z[i];
        }
    result=n/somma;
    return(result);
}

double MQ(int n, double z[]){
    double somma =0;
    double result;
    for(int i=0;i<n;i++){
        somma=somma+pow(z[i],2)/n;
    }
    result=sqrt(somma);
    return(result);
}



int main(){
    int m;
    double Ma,Mg,Mq,Mh;
    double v[NMAX];
    
    do{ 
        printf("inserisci m merda umana ");
        scanf("%d",&m);
    }while(m<=0 ||m>20);

    int n=2*m;

    double x[NMAX];
    double y[NMAX];
    double z[NMAX];
    for(int i=0;i<m;i++){
        do{
            printf("vedi de inseri x[%d] ", i);
            scanf("%lf",&x[i]);
        }while(x[i]<=0);
    }
    for(int j=0;j<m;j++){
        do{
            printf("inserisci sta cazzo de y[%d] ",j);
            scanf("%lf",&y[j]);
        }while(y[j]<=0);
    }
    for(int i=0;i<m;i++){
            z[2*i]=x[i];
            z[2*i+1]=y[i];
    }
     printf("il vettore z e':\n");
     for(int i=0;i<n;i++){
        printf("z[%d]=%lf\n",i,z[i]);
    }

    Ma=MA(n,z);
    Mg=MG(n,z);
    Mh=MH(n,z);
    Mq=MQ(n,z);

    v[0]=Ma;
    v[1]=Mg;
    v[2]=Mh;
    v[3]=Mq;
    printf("il tuo bel vettore e':\n");
    for(int i=0;i<4;i++){
        printf("v[%d]=%lf\n",i,v[i]);
    }
    double temp;

    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            if(v[j]>v[i]){
             temp=v[i];
             v[i]=v[j];
             v[j]=temp;
            }
         
        }
    }
    printf("il vettore ordinato e':\n");
    for(int i=0;i<4;i++){
        printf("v[%d]=%lf\n",i,v[i]);
    }


}
