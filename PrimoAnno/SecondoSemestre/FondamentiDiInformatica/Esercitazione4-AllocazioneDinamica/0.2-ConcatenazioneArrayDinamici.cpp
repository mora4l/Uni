/*
i scriva la funzione C++ append che concateni due array di numeri. La funzione riceve come parametri i
puntatori a due array di numeri interi pa e pb e le loro dimensioni na e nb (due numeri interi) e restituisce come
valore di ritorno il puntatore a un array di numeri interi.

• La funzione allocherà dinamicamente un array di (na + nb) elementi e vi copierà gli elementi degli array puntati
da pa e pb. La funzione restituirà infine il puntatore all’array risultante. Sarà responsabilità del programma
chiamante deallocare la memoria allocata dalla funzione.

• Si scriva quindi un programma C++ per verificare il corretto funzionamento della funzione. Il programma
chiederà all’utente di immettere da tastiera le dimensioni nx e ny di due array di numeri interi, allocherà
dinamicamente gli array e chiederà all’utente di inserire i valori per entrambi gli array. Il programma, chiamerà la
funzione append e stamperà a video l’array concatenato risultante.


Esempio: se l’array puntato da pa è {1, 3, 5, 6, 8} (na = 5) e l’array puntato da pb è {2, 4, 10} (nb = 3), l’array
concatenato risultante sarà {1, 3, 5, 6, 8, 2, 4, 10}.
*/

#include <iostream>
using namespace std;
int *append(int *pa, int *pb, int na, int nb)
{

    int *c = new int[na + nb];

    for (int i = 0; i < na; i++)
    {

        c[i] = pa[i] + pb[i];
    }

    return c;
}

int main()
{
    int nx = 0;
    int ny = 0;

    cout << "inserisci dimensioni di array1" << endl;
    cin >> nx;
    cout << "inserisci dimensioni di array2" << endl;
    cin >> ny;

    int *a = new int[nx];
    int *b = new int[ny];

    cout << "inserisci valori array1 " << endl;
    for (int i = 0; i < nx; i++)
    {
        cin >> a[i];
    }
    cout << "inserisci valori array2" << endl;
    for (int i = 0; i < ny; i++)
    {
        cin >> b[i];
    }

    int *d = append(a, b, nx, ny);

    for (int i = 0; i < nx; i++)
    {
        cout << d[i];
    }

    delete[] a;
    delete[] b;
    delete[] d;
    return 0;
}