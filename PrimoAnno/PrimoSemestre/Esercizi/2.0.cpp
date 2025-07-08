/*
Si scriva un programma C++ che dichiari due array a e b di 12 numeri interi, chieda all’utente di inserirne da tastiera i
valori dell’array a e operi come segue: assegni inizialmente il valore 1 al primo ed all’ultimo elemento dell’array b;
quindi partendo dal penultimo elemento dell’array a e fino al secondo elemento, assegni al corrispondente elemento
dell’array b il prodotto dell’elemento precedente e di quello seguente nell’array a. Il programma stamperà infine a
video l’array b e ripeterà tutte le operazioni finché l’utente lo desidera. Ad esempio, se a = {1, 3, 4, 2, 9, 5, 3, 2, 2, 6,
3, 3}, l’array b sarà b = {1, 4, 6, 36, 10, 27, 10, 6, 12, 6, 18, 1}.
*/

#include <iostream>
using namespace std;
#define R 12
int main()
{
    int vuoi = 1;
    int a[R];
    int b[R];
    while (vuoi == 1)
    {
        cout << "inserisci valori array" << endl;
        for (int i = 0; i < R; i++)
        {
            cin >> a[i];
        }

        b[0] = 1;
        b[11] = 1;

        for (int i = R - 2; i > 2; i--)
        {
            b[i] = a[i - 1] * a[i + 1];
        }

        for (int i = 0; i < R; i++)
        {
            cout << b[i] << " " << endl;
        }

        cout << "vuoi continuare? [0 no , 1 si ]" << endl;
        cin >> vuoi;
    }

    return 0;
}