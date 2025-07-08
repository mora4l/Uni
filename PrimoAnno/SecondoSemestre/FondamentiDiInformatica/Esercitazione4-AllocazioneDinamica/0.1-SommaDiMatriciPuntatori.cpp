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
▫ Una volta calcolata la somma, la matrice risultante C deve essere stampata a video.
• Piu difficile: scrivi la funzione con solo un ciclo for (senza cicli annidati)
*/

#include <iostream>
using namespace std;
#define N 3

int (*matrix(int (*a)[N], int (*b)[N], int (*c)[N]))[N]
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            *(*(c + i) + j) = *(*(a + i) + j) + *(*(b + i) + j);
        }
    }

    return c;
}
int(*matrix2(int (*a)[N],int(*b)[N],int(*c)[N]))[N]{

    for(int i =0 ; i<N*N;i++){
            *(*(c + i)) = *(*(a + i)) + *(*(b + i));
    }
    return c; 
}
int main()
{

    int A[N][N];
    int B[N][N];
    int C[N][N];

    cout << "inserisci i valori di A " << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << endl
         << "ora di B" << endl;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> B[i][j];
        }
    }

    int(*ma)[N] = matrix2(A, B, C);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {

            cout << *(*(ma + i) + j);
        }
        cout << endl;
    }
    return 0;
}