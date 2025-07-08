/*
Si modifichi la funzione C++ bubbleSort, che implementa l’algoritmo di ordinamento BubbleSort, facendo in modo che possa
gestire ordinamenti in senso crescente e decrescente.


• Per implementare l’ordinamento nei due sensi avete le seguenti funzioni C++:
*/

#include <iostream>
using namespace std;

/*
A tale scopo, la funzione bubbleSort riceverà come parametri un array di numeri interi v, la sua dimensione n e un puntatore pf a una funzione che riceva come parametri due numeri interi e
restituisca come valore di ritorno un numero intero.

La funzione puntata da pf restituisce 1 se l’ordine degli interi è corretto
rispetto all’ordinamento prescelto e 0 altrimenti. Quindi la funzione bubbleSort chiamerà la funzione puntata da pf,
passandole come parametri gli elementi v[j] e v[j + 1] dell’array v e li scambierà se la chiamata alla funzione puntata da pf
restituirà 0.
*/

int bubbleSort(int v[], int n, int (*pf)(int, int))
{

    int ritornointero;
    for (int i = 0; i < n - 1; i++)
    { // Nel ciclo di ordinamento, il ciclo esterno dovrebbe iterare su n-1 passate , perché ogni passata sistemerà almeno un elemento alla sua posizione finale.
        for (int j = 0; j < n - 1 - i; j++)
        { // Nel ciclo interno for di bubbleSort, il ciclo dovrebbe andare fino a n-1-i (dove i è l'indice del ciclo esterno), poiché con ogni passata l'elemento più grande (o più piccolo) "scivola" verso la fine dell'array.

            ritornointero = (*pf)(v[j], v[j + 1]);
            if (ritornointero == 0)
            {
                // bubblesort
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }

    return ritornointero;
}

/*
- La funzione maggiore che riceva come parametri due numeri interi a e b e restituisca 1 se a è maggiore di b e zero
altrimenti.
*/

int maggiore(int a, int b)
{
    int retMag = 0;
    if (a > b)
    {
        retMag = 1;
    }
    else
    {
        retMag = 0;
    }
    return retMag;
}
/*
- La funzione minore che riceva come parametri due numeri interi a e b e restituisca 1 se a è minore di b e zero altrimenti.

*/

int minore(int a, int b)
{
    int retMin = 0;
    if (a > b)
    {
        retMin = 1;
    }
    else
    {
        retMin = 0;
    }
    return retMin;
}
/*
• Si scriva, infine, un programma C++ che dichiari un array w di 10 numeri interi, chieda all’utente di inserirne i valori da
tastiera, chieda all’utente di scegliere se desidera ordinare gli elementi di w in senso crescente o decrescente, chiami la
funzione bubbleSort passando a pf la funzione maggiore nel caso di ordinamento decrescente e la funzione minore nel caso
di ordinamento crescente e stampi a video il valore degli elementi dell’array ordinato.
*/
int main()
{
    int n = 10;
    int w[10];
    cout << "inserisci valori" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> w[i];
    }

    int ordine = 0;
    cout << "vuoi ordinare gli elementi in senso crescente [0] o decrescente [1]?" << endl;
    cin >> ordine;
    if (ordine == 0)
    {
        bubbleSort(w, n, minore);
    }
    if (ordine == 1)
    {
        bubbleSort(w, n, maggiore);
    }

    cout << "array ordinato:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << w[i] << endl;
    }

    return 0;
}