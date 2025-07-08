/*
Scrivi un programma che calcola la somma di due matrici 3x3 utilizzando puntatori. La somma di due
matrici A e B di dimensione 3x3 deve essere memorizzata in una matrice C, e infine il risultato deve
essere stampato a video.
▫ Le matrici A, B, e C devono essere dichiarate come matrici bidimensionali di dimensione 3x3 in main()
▫ Creare una funzione che accetta tre matrici (due per l'input e una per il risultato) come puntatori e somma
gli elementi corrispondenti di A e B, memorizzando il risultato in C.
▫ Utilizzare i puntatori per accedere agli elementi delle matrici e calcolare la somma senza utilizzare
l'indicizzazione degli array.
▫ Il programma in main() deve chiedere all'utente di inserire i valori delle matrici A e B.
▫ Una volta calcolata la somma, la matrice risultante C deve essere stampata a video
*/

#include <iostream>
using namespace std;
#define N 3

void accetta(int (*a)[N], int (*b)[N], int (*c)[N])
{

    for (int i = 0; i < N; i++)
    {

        for (int j = 0; j < N; j++)
        {
            *(*(c + i)+j) = *((*(a + i)+j)) + *(*(b + i)+j);
        }
    }

    cout << "matrice c=" << endl;
    for (int i = 0; i < N; i++)
    {

        for (int j = 0; j < N; j++)
        {
            cout << *(*(c + i)+j);
        }
        cout << endl;
    }
}
int main()
{

    int A[N][N] = {{0}};
    int B[N][N] = {{0}};
    int C[N][N] = {{0}};
    cout << "inserisci valori di A" << endl;
    for (int i = 0; i < N; i++)
    {

        for (int j = 0; j < N; j++)
        {
            cin >> *(*(A + i)+j);
        }
    }

    cout << "inserisci valori di B" << endl;
    for (int i = 0; i < N; i++)
    {

        for (int j = 0; j < N; j++)
        {
            cin >> *(*(B + i)+j);
        }
    }
    return 0;
}
