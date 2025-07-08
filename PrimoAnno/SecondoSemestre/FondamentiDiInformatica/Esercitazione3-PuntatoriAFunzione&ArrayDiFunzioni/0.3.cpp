/*



*/
#include <iostream>
using namespace std;
struct Campi
{
    double prod = 0;
    double dist = 0;
};
/*
Si scriva la funzione C++ prodotto_scalare che riceva come parametri il puntatore px al primo elemento di un
array di numeri reali, il puntatore py al primo elemento di un array di numeri reali e la dimensione comune n
dei due array (un numero intero). Utilizzando l’aritmetica dei puntatori, la funzione dovrà scandire i due array e
calcolarne il prodotto scalare, restituito come valore di ritorno (un numero reale).
*/

double prodotto_scalare(double *px, double *py, int n)
{
    double scalarCampi = 0;

    for (int i = 0; i < n; i++)
    {
        scalarCampi += (*(px + i) + *(py + i));
    }

    return scalarCampi;
}

/*
• Per fare di più: calcolare anche la distanza tra gli array puntati da px e da py e restituire, come parametro di
uscita (anziché come valore di ritorno) una struttura che contenga due campi, il prodotto scalare e la distanza
calcolati dalla funzione (due numeri reali). Modificare poi il programma di prova in modo che stampi entrambi
i valori restituiti dalla funzione.
*/

void distanza(double *px, double *py, int n, Campi c)
{

    double scalarCampi2 = 0;

    for (int i = 0; i < n; i++)
    {
        scalarCampi2 += (*(px + i) + *(py + i));
    }
    c.prod = scalarCampi2;
    c.dist = px - py;

    cout << "dati struct=" << "prod :" << c.prod << endl
         << "dist=" << c.dist << endl;
}

/*
• Si scriva quindi un programma C++ per verificare il corretto funzionamento della funzione. Il programma
chiederà all’utente di immettere da tastiera i valori per i due array, chiamerà la funzione prodotto_scalare e
ne stamperà a video il valore di ritorno.
Esempio: se l’array puntato da px vale {1.0, 3.0, 2.5, 0.0, 1.2} e l’array puntato da py vale {2.0, 1.0, 2.0, 3.8, 10.0} (si
ha quindi n = 5), la funzione restituisce il valore del prodotto scalare dei due array, ovvero: 1.0 × 2.0 + 3.0 × 1.0 +
2.5 × 2 + 0.0 × 3.8 + 1.2 × 10.0 = 22.0.
*/
int main()
{
    int n = 5;
    double array1[n] = {0};
    double array2[n] = {0};

    cout << "inserisci valori array 1" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array1[i];
    }
    cout << "inserisci valori array 2" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array2[i];
    }

    double prod = prodotto_scalare(array1, array2, n);
    cout << "prodotto scalare=" << prod << endl;
    double secondoscalar = 0, d = 0;
    Campi c = {secondoscalar, d};
    distanza(array1,array2,n,c);
    return 0;
}