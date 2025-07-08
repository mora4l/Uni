/*
Si scriva la funzione C++ righe_negative che riceva come parametri una matrice A di n righe e n colonne (n è
dichiarato come una costante intera all’inizio del programma) e un array di puntatori a numeri interi p
.
- L’array p è costituito anche esso dallo stesso numero costante n di elementi e la funzione lo inizializza in modo tale
che tutti gli elementi siano NULL.

La funzione scandirà la matrice A riga per riga ed inserirà nell’array b i puntatori
alle righe per le quali la somma degli elementi risulta essere un numero negativo.


- Si scriva quindi un programma C++ per verificare il corretto funzionamento della funzione: il programma chiederà
all’utente di immettere da tastiera gli elementi della matrice A, chiamerà la funzione righe_negative e stamperà a
video le righe la cui somma degli elementi è un numero negativo.
Esempio: se la matrice A (di dimensione 3 x 3) fosse la seguente:
A =
−1 −2 1
0 3 −1
−5 −6 −2
si otterrebbe l’array b = {puntatore alla prima riga, puntatore alla terza riga, NULL} e il programma stamperebbe a
video la prima e la terza riga della matrice A
*/

#include <iostream>
#define n 2
using namespace std;
void righe_negative(int A[n][n], int *p[n])
{

    *p = {NULL};
    int somma = 0;
    int *iu = &A[0][0];
    for (int i = 0; i < n; i++)
    {
        somma = 0;
        for (int j = 0; j < n; j++)
        {

            somma += *(iu + i * n + j);
        }

        if (somma < 0)
        {
            *(p + i) = new int(somma);
        }
        else
        {
            p[i] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {

        cout << *(iu + i) << endl;
    }
}
int main()
{
    int *array2[n];
    int matrix[n][n]{{0}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    righe_negative(matrix, array2);

    return 0;
}