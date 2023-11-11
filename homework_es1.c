/*
  Scrivere un programma che riceva in input una sequenza di interi positivi terminata immettendo un numero gi`a dato
in input; questo ultimo dato non deve essere considerato ma solo fungere da terminatore della sequenza.
Se a0, . . . , an `e la sequenza inserita, sia b0, . . . , bn la sequenza ordinata degli input, in modo tale che la funzione
definita da π(bi) = ai (0 ≤ i ≤ n) sia una permutazione di {b0, . . . , bn}.
Il programma deve scrivere la permutazione π in notazione ciclica. L’output del programma deve essere la sequenza
de cicli di π scritti fra parentesi tonde, ordinati lessicograficamente, omettendo i cicli di lunghezza 1; ad esempio,
all’input
2 3 29 8 12 32 30 3
deve corrispondere l’output
(8 29 12)(30 32)
  */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


typedef struct elem{
        int dato;
        struct elem * next;
} nodo;


bool in_lista(nodo * cursore, int k){
        while (cursore != NULL){
                if (cursore->dato == k){
                        return true;
                }
                cursore = cursore->next;
        }
        return false;
}


// converte la lista in un array della corretta lunghezza
void * lista2ar(int n, nodo * cursore){
        int * array;
        int i = n-1;
        array = malloc(n*sizeof(int));

        while (cursore != NULL){
                array[i] = cursore->dato ;
                i--;
                cursore = cursore->next;
        }

        return array;
}


// stampa a video un array n-dim
void print_ar(int n, int *ar){
        printf("(");
        for (int i=0; i<n-1; i++)
                printf("%d ", *(ar+i));
        printf("%d)", *(ar+n-1));
}


// copia in vettore v in w
void cp_ar(int n, int * v, int * w){
        for (int i =0; i<n; i++)
                w[i] = v[i];
}


// passiamo k elemento di un array v, n-dim:
// riturna l'indice dell'emento k in questo array v
int indice(int k, int n, int * v){
        for (int j =0; j<n; j++){
                if (*(v+j) == k){
                        return j;
                }
        }
}


// ritorna il minimo di v, vettore d-dim
// se il parametro index è passato true ritorna l'indice del minimo
int minimum(int d, int * v, bool index){
        int temp, temp_index;
        temp = *v;
        temp_index = 0;

        for (int j=0; j<d; j++){
                if (*(v+j) <= temp){
                        temp = *(v+j);
                        temp_index = j;
                }
        }
        if (index){
                return temp_index;
        }
        return temp;
}


// ritorna True se il vettore ar è ordinato, False altrimenti
bool is_sorted(int n, int * ar){

        for (int i=0; i<n-1; i++){
                if (*(ar+i) > minimum(n-i-1, ar+i+1, false)){return false;}
        }
        return true;
}


// ordina il vettore ar lungo n
int * slow_sort(int n, int *ar){
        int aux;
        while (!is_sorted(n, ar)){
                for (int k=0; k<n-1; k++){
                        if (*(ar+k) >= *(ar+k+1)){
                                aux = *(ar+k+1);
                                *(ar+k+1) = *(ar+k);
                                *(ar+k) = aux;
                        }
                }
        }
        return ar;
}


// legge un ciclo lungo c rappresentato da un vettore e lo scrive in ordine
// lessicografico i.e. lo sposta in modo che il primo numero sia il minimo
// es. (5 4 3 1 2) -> (1 2 5 4 3)
void shift_cycle(int c, int * ciclo){
        int * aux;
        int mou;
        int counter = 0;
        aux = malloc(c*sizeof(int));

        mou = minimum(c, ciclo, true); // mou contiene il l'indice di minimo del ciclo

        for (int j=mou; j<c; j++){
                aux[counter] = ciclo[j];
                counter++;
        }

        for (int j=0; j<mou; j++){
                aux[counter] = ciclo[j];
                counter++;
        }
        cp_ar(c, aux, ciclo);
}


// genera i cicli
void function(int n, int * sigma, int * sorted){
        bool * trovato;
        int * ciclo;
        int j;
        int c;
        int p;

        trovato = malloc(n*sizeof(bool));
        ciclo = malloc(n*sizeof(int));

        memset(trovato, false, n);

        for (int j=0; j<n; j++){
                bool finito = true;
                for(int t=0; t<n; t++){
                        finito = trovato[t] && finito;
                }

                if (finito){break;}

                memset(ciclo, -1, n);
                c = 0;
                if (trovato[*(sigma+j)] == false){
                        p= j;
                        while (trovato[*(sigma+p)] == false){
                                *(ciclo+c) = *(sigma+p);
                                trovato[*(sigma+p)] = true;
                                c++;
                                p = *(sigma+p);
                        }
                }
                for (int h=0; h<c; h++){
                        ciclo[h] = sorted[sigma[ciclo[h]]];
                        //printf("%d", ciclo[h]);
                        }
                if (c>1){
                        //printf("\n");
                        //print_ar(c, ciclo);
                        shift_cycle(c, ciclo); // ora funge
                        print_ar(c, ciclo);
                        //print_cycle(c, ciclo);
                }
        }
}


int main(){
        int n=0;
        int t;
        int *ar;
        int *sorted;
        int * sigma;

        // inizializza lista
        nodo * testa = NULL;
        nodo * nuovo;

        while (true){
                scanf("%d", &t);

                if (!in_lista(testa, t)){
                        n++;
                        nuovo = malloc(sizeof(nodo));
                        nuovo->dato = t;
                        nuovo-> next = testa;
                        testa = nuovo;
                }
                else{
                        break;
                }
        }

        ar = lista2ar(n, testa);

        // ordiniamo l'arr
        sorted = malloc(n*sizeof(int));
        cp_ar(n, ar, sorted);
        slow_sort(n, sorted);


        sigma = malloc(n*sizeof(int));
        for (int q=0; q<n; q++){
                sigma[q] = indice(ar[q], n, sorted);
        }

        // supp spdg di aver gia cstruito l'array raooresentte la permutazione

        function(n, sigma, sorted);
        return 0;
}
