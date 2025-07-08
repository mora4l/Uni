/*
Si scriva una funzione in linguaggio C++ che ricevuta come parametro una matrice
quadrata di numeri reali, calcoli e restituisca come valore di ritorno la sua traccia,
ovvero la somma di tutti gli elementi della diagonale principale (un numero reale).
Si scriva quindi un programma C++ per verificare il corretto funzionamento della
funzione. E’ responsabilità del programma chiamante passare alla funzione una
matrice delle dimensioni corrette.
*/

#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int d = 4;
const int dd = 4;

double diagonal(double matrix[d][dd], double &rslt)
{

    for (int i = 0; i < d && dd; i++)
    {
        for (int j = 0; j < d && dd; j++)
        {
            if (i == j)
            {
                rslt += matrix[i][j];
            }
        }
    }

    return rslt;
}

int main()
{

    srand(time(NULL));
    double A[d][d] = {0};
    double traccia = 0;
    if (A[d] == A[dd])
    {

        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < dd; j++)
            {
                A[i][j] = rand() % 10;
            }
        }
    }
    else
    {
        exit(1);
    }

    diagonal(A, traccia);

    cout << "La traccia della matrice generata è : " << traccia << endl;

    return 0;
}