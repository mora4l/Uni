//Identificare e correggere gli errori nella seguente serie di istruzioni:
#include <iostream>

using namespace std;

const int r = 10;
const int c = 20;

int elabora(int M[r][c]);

int main() {
int P[r][c] = {0};
for (int i = 0; i <= r; i++)
for (int j = 0; j <= c; j++)
cin >> P[i][j];
cout << elabora(P) << endl;
return 0;
}

/*
Si scriva che cosa stamperà in uscita il seguente programma C++, spiegando
brevemente il funzionamento delle funzioni test1 e test2:

La funzione test1 è una funzione senza valore di ritorno che assume in ingresso un array MxN e un array con il prodotto dei valori negli indici M*N. 
Il programma prosegue ciclando su ogni coordinata della matrice e ad ogni iterazione lavora sull'array a ,prendendo come indice :
il valore r ( dichiarato precedentemente con valore 3) moltiplicato alla somma degli indici i e j che stanno iterando nel ciclo for; 
questo indice di a sarà il resto della divisione tra il valore della cella i,j dell'array M e 2.
Il codice quindi stamperà dei valori in una matrice , calcolati in base a dei valori di un' altra matrice

La funzione test2 invece prende gli stessi parametri in ingresso per valore e itera solamente per una variabile sola k, con k che arriva fino all'ultima casella della matrice M (Mxn),
a questi punto se il valore iterato della matrice a è =1, la matrice il cui indice r è il resto tra il numero dell'iterazione nel ciclo e r e l'indice c è la divisione tra il numero dell'iterazione del ciclo e r , incrementerà di uno il suo valore.

Il seguente programma quindi stamperà in uscita un array con dei valori calcolati in base ad indici di iterazione e valori all'interno di matrici ausiliari.
*/
#include <iostream>

using namespace std;

const int r = 3, c = 2;

void test1(int M[r][c], int a[r*c]) {
for (int i = 0; i < r; i++)
for (int j = 0; j < c; j++)
a[r * j + i] = (M[i][j] % 2);
}

void test2(int M[r][c], int a[r*c]) {
for (int k = 0; k < r * c; k++)
if (a[k] == 1)
M[k % r][k / r]++;
}


//stampa a video M e a
void stampa(int M[r][c], int a[r*c]);

int main() {
int S[r][c] = {1, 6, 5, 4, 2, 3};
int v[r*c] = {0};
test1(S, v);
stampa(S, v);
test2(S, v);
stampa(S, v);
return 0;
}