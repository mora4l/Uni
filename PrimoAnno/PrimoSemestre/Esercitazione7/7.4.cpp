/*
Si scriva una funzione in linguaggio C++ che
riceva come parametro una matrice di numeri reali M di 4 righe e 5 colonne,
due numeri reali a e b,
e un’ulteriore matrice di numeri interi P di due righe e lo stesso numero di colonne di M.

La funzione calcola i valori degli elementi della matrice P nel modo seguente:
gli elementi della prima riga di P contano quanti elementi di ciascuna colonna di M appartengono all’intervallo [a, b]
mentre gli elementi della seconda riga di P contano quanti elementi di ciascuna colonna di M non appartengono all’intervallo [a, b].

La funzione non restituisce alcun valore di ritorno.

Si scriva quindi un programma per verificare il corretto funzionamento della funzione.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#define R 4
#define C 5
using namespace std;

void calcolo(float M[R][C], int P[2][C], float a, float b)
{
    for (int j = 0; j < C; j++)
    {
        for (int i = 0; i < R; i++)
        {

            if ((M[i][j] >= a) && (M[i][j] <= b))
            {
                P[0][j]++;
            }
            else
            {
                P[1][j]++;
            }
        }
    }

    cout << "A= " << a << endl
         << "B= " << b << endl;
    cout << "questa è la matrice M: " << endl
         << endl;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << M[i][j] << "  ";
        }
        cout << "\n";
    }

    cout << endl
         << endl
         << "Questa è la matrice P : " << endl
         << endl;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << P[i][j] << "  ";
        }
        cout << "\n";
    }
}

int main()
{

    float M[R][C] = {0}, a = 0.0, b = 1.0;
    srand((unsigned)time(NULL));

    int P[2][C];

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            M[i][j] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
            P[i][j] = 0;
        }
    }
    /*         for(int i =0;i<R;i++){
            for(int j=0;j<C;j++){
                cout<< M[i][j];
            }
                cout<< "\n";
        } */
    calcolo(M, P, a, b);

    return 0;
}