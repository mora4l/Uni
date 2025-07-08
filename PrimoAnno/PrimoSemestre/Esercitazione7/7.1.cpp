/*
Nota:
si definisce prodotto righe per colonne di una matrice ௜௞ di ordine per una
matrice ௞௝ di ordine , la matrice ௜௝ di ordine i cui elementi sono:
*/
#include <iostream>

using namespace std;
const int d = 3;

int assumi(int A[d][d], int B[d][d])
{

    cout << "Inserisci i valori delle matrici" << endl;

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cout << "inserisci il valore con posizione : " << i << "," << j << " Della matrice A" << endl;
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cout << "inserisci il valore con posizione : " << i << "," << j << " Della matrice B" << endl;
            cin >> B[i][j];
        }
    }

    return A[d][d], B[d][d];
}

int produciNegro(int A[d][d], int B[d][d], int C[d][d])
{

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            for (int k = 0; k < d; k++)
            {

                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C[d][d];
}

int stampaNegro(int A[d][d])
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cout << A[i][j] << endl;
        }
    }

    return A[d][d];
}
int main()
{

    int matriceA[d][d] = {0};
    int matriceB[d][d] = {0};
    int matriceAXB[d][d] = {0};

    assumi(matriceA, matriceB);
    produciNegro(matriceA, matriceB, matriceAXB);
    stampaNegro(matriceAXB);

    return 0;
}