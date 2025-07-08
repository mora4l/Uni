/*
Una matrice M è formata da n x m numeri interi, ognuno dei quali può valere soltanto 0,1 o 3.
La riga i-esima della matrice rappresenta i punti acquisiti dalla i-esima squadra di calcio nelle partite disputate nelle diverse giornate di un campionato.

Il campionato comprende, quindi, n squadre e m giornate.

In particolare, M[i][k] denota il numero di punti conquistati dalla squadra i nella k-esima giornata.

Si scriva in linguaggio C++ la funzione capolista che riceva come parametro la matrice M e un numero intero 0 <= k < m
e restituisca come valore di ritorno l’indice della squadra prima classificata alla k-esima giornata o -1 nel caso in cui sia k >= n (un numero intero).

Per semplicità si assuma che i valori contenuti nella matrice siano validi.
Si scriva quindi un programma per verificare il corretto funzionamento della funzione.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;
const int dim = 4;
const int dym = 5;

int capolista(int a[dim][dym], int &e)
{

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dym; j++)
        {
            if (a[i][j] > a[i][j - 1])
            {
                e = i;
            }
        }
    }
    return a[dim][dym], e;
}

int random(int a[dim][dym])
{

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dym; j++)
        {
            a[i][j] = rand() % 4;
            while (a[i][j] == 2)
            {
                a[i][j] = rand() % 2;
                
            }
        }
    }

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dym; j++)
        {

            cout << a[i][j];
        }
        cout << "\n";
    }
    return a[dim][dym];
}

int main()
{

    int M[dim][dym] = {0}, k = 0;
    srand(time(NULL));
    cout << "Cerchi la capolista di che giornata ? (inserire il numero compreso tra " << "0" << "e " << dym << endl;
    cin >> k;
    if (k < 0 || k > dym)
    {
        exit(1);
    }

    random(M);
    capolista(M, k);

    cout << "capolista è " << k;
    return 0;
}