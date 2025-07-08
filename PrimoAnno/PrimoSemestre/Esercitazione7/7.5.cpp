/*
Si scriva in linguaggio C++ la funzione differenza_medie_triangoli che
riceva come parametro un matrice quadrata M di numeri interi di dimensione 5 (la matrice è cioè composta di 5 righe e 5 colonne)

e calcoli e restituisca come valore di ritorno
un numero reale che rappresenta il valore assoluto della differenza tra la media degli elementi appartenenti al triangolo superiore della matrice (diagonale compresa)
e la media degli elementi appartenenti al triangolo inferiore della matrice (diagonale compresa)
*/

#include <iostream>
#define SIZE 5
using namespace std;
int differenza_medie_triangoli(int matrix[SIZE][SIZE])
{
    float mediaSup = 0, mediaInf = 0, diff = 0, sommaSup = 0, sommaInf = 0, tmp1 = 0, tmp2;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {

            if (i < j)
            {
                sommaSup += matrix[i][j];
                tmp1++;
            }
            else if (i == j)
            {
                sommaSup += matrix[i][j];
                tmp1++;
                sommaInf += matrix[i][j];
                tmp2++;
            }
            else
            {
                sommaInf += matrix[i][j];
                tmp2++;
            }

            mediaSup = sommaSup / tmp1;
            mediaInf = sommaInf / tmp2;
        }
    }

    cout<< " La matrice M è : "<<endl;
        for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {

            cout<<matrix[i][j];
        }
        cout<<"\n";
    }

cout<<endl<<" la media della triangolare superiore è "<<mediaSup<<endl;
cout<<" la media della triangolare inferiore è "<< mediaInf<<endl;
cout<<" Il valore assoluto è "<< abs(mediaSup-mediaInf)<<endl;


    return diff;
}
int main()
{

    int M[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {

            M[i][j] = rand() % 10;
        }
    }

    differenza_medie_triangoli(M);
    return 0;
}