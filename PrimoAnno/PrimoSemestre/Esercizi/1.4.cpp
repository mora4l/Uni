/*
Si scriva un programma C++ che dichiari una matrice M di numeri reali di 4 righe e 3 colonne e due matrici X e Y di
numeri reali, ciascuna di 2 righe e 3 colonne. Dopo avere chiesto all’utente di inserire da tastiera gli elementi della
matrice M, il programma copierà nella matrice X le righe pari di M e nella matrice Y le righe dispari di M. Infine, il
programma calcolerà e stamperà a video la somma degli elementi contenuti in ciascuna delle matrici X e Y.
*/

#include <iostream>
#define R 4
#define C 3
using namespace std;

int main()
{

    double M[R][C];

    double X[2][C];
    double Y[2][C];

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {

            cout << "inserisci gli elementi della matrice M: " << endl;
            cin >> M[i][j];
        }
    }

    double sommax=0,sommay=0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if(i%2){
                X[i][j]=M[i][j];
            }else{
                Y[i][j]=M[i][j];

            }

        sommax+=X[i][j];
        sommay+=Y[i][j];
        }
    }

    cout<<sommax<<" è la somma di x,"<<sommay<<" è la somma di y"<<endl;


    return 0;
}