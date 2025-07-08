/*
Implementino le seguenti funzioni:
*/

#include <iostream>
#include <math.h>
using namespace std;
/*
▫ minimum che riceva come parametri un array a di numeri reali e la sua dimensione n (un numero intero) e restituisca come valore di ritorno
il valore del minimo elemento dell’array (un numero reale).
*/
double minimum(double a[], int n)
{
    double min = (*a);

    for (int i = 1; i < n; i++)
    {

        if (*(a + i) < min)
        {
            min = *(a + i);
        }
    }

    return min;
}
/*
▫ maximum che riceva come parametri un array a di numeri reali e la sua dimensione n (un numero intero) e restituisca come valore di ritorno
il valore del massimo elemento dell’array (un numero reale).
*/
double maximum(double a[], int n)
{
    double max = (*a);

    for (int i = 1; i < n; i++)
    {
        if (*(a + i) > max)
        {
            max = *(a + i);
        }
    }

    return max;
}
/*
▫ sum che riceva come parametri un array a di numeri reali e la sua dimensione n (un numero intero) e restituisca come valore di ritorno la
somma degli elementi dell’array (un numero reale).
*/
double sum(double a[], int n)
{
    double sommaHalal = 0;
    for (int i = 0; i < n; i++)
    {
        sommaHalal += *(a + i);
    }
    return sommaHalal;
}

/*
▫ sum_square che riceva come parametri un array a di numeri reali e la sua dimensione n (un numero intero) e restituisca come valore di
ritorno la somma dei quadrati degli elementi dell’array (un numero reale).
*/
double sum_square(double a[], int n)
{
    double piazzaEmbriaci = 0;

    for (int i = 0; i < n; i++)
    {

        piazzaEmbriaci += pow(*(a + i), 2);
    }

    return piazzaEmbriaci;
}

/*
▫ mean che riceva come parametri un array a di numeri reali e la sua dimensione n (un numero intero) e restituisca come valore di ritorno la
media degli elementi dell’array (un numero reale).
*/
double mean(double a[], int n)
{
    double media = 0, som = 0;

    for (int i = 0; i < n; i++)
    {
        som += *(a + i);
    }
    media = som / n;
    return media;
}
/*
• Si scriva quindi un programma C++ che operi come segue:
▫ dichiari un array v di 10 numeri reali.

▫ dichiari un array pf di cinque puntatori a funzione che ricevano come parametri un array di numeri reali e un numero intero e restituiscano
come valore di ritorno un numero reale e inizializzi gli elementi dell’array pf con gli indirizzi delle cinque funzioni precedentemente
implementate (minimum, maximum, sum, sum_square, mean).

▫ chieda all’utente di inserire da tastiera i valori degli elementi dell’array v.

▫ chieda all’utente di scegliere quale operazione desidera applicare agli elementi dell’array v, tra le cinque precedentemente implementate e i
cui puntatori sono disponibili in pf.

▫ Utilizzando il puntatore contenuto nell’array pf, chiami la funzione corrispondente all’operazione desiderata e stampi a video il risultato.
*/
int main()
{

    double v[10] = {0};

    double (*pf[5])(double[], int) = {minimum, maximum, sum, sum_square, mean};

    cout << "inserisci valori array v" << endl;
    for (int i = 0; i < 10; i++)
    {

        cin >> v[i];
    }
    int scelta = 0;
    cout << "quale operazione desideri applicare agli elementi dell'array v? min=0,max=1,sum=2,sum_square=3,mean=4" << endl;
    cin >> scelta;
    // shticazzi del controllo valore

    double ris = (*pf[scelta])(v, 10);

    cout << "risultato=" << ris << endl;
    return 0;
}