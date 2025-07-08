/*
Si scriva il template di funzione Sottocampiona che riceva come parametri un array a di elementi di tipo generico T, la
sua dimensione n (un numero intero positivo) e un secondo numero intero m tale che 0 < m ≤ n / 2. Il template di
funzione restituisce come valore di ritorno un puntatore a un array di elementi di tipo generico T e opera in questo
modo: calcola 𝑘=⌈𝑛/𝑚⌉ (cioè il quoziente della divisione di n per m, approssimato al numero intero immediatamente
superiore),

alloca dinamicamente un array s di m elementi di tipo generico T, copia in s un elemento ogni k dell’array
a, partendo dal primo elemento di a.

Ad esempio, assumendo che T venga istanziato con il tipo concreto int e che
siano dati a = {3, 2, 8, 5, 4, 9, 6, 1, 2, 1} (n = 10) e m = 3, il template di funzione allocherà un array s di 3 elementi e lo
riempirà copiandovi un elemento ogni 𝑘=⌈10/3⌉=4 elementi di a (copierà quindi il primo, il quinto e il nono
elemento di a), cioè si avrà s = {3, 4, 2}. Se il valore di n o m non è valido, il template di funzione restituisce NULL.

Si supponga che il template di funzione venga istanziato con un tipo concreto dotato di operatore di assegnamento.


*/
#include <iostream>
using namespace std;

template <typename T>
T *Sottocambiona(T a[], int n, int m)
{

    int index = 0;

    if ((m <= 0) && (m > (n / 2)))
    {
        return nullptr;
    }

    int calc = (n + m - 1) / m;

    T *s = new T[m];

    for (int i = 0; i < n;)
    {
        s[index] = a[i];
        index++;
        i = i + calc;
    }

    return s;
}

/*Si scriva quindi un programma C++ che operi come segue:
dichiari un array v di 10 numeri interi e chieda all’utente di  inserirne i valori da tastiera,

chieda all’utente di inserire un numero intero t compreso tra 1 e 5 (in caso di inserimento
di un valore non valido, il programma chiederà di ripetere l’inserimento finché non pervenga un valore valido),

chiami il template di funzione Sottocampiona passando l’array v, la sua dimensione e la dimensione del nuovo array t come
parametri, stampi a video i valori contenuti nell’array puntato dal puntatore che il template di funzione restituisce
come valore di ritorno (tale array avrà dimensione t), deallochi tale array e termini. */

int main()
{

    int n = 10;
    int v[n];

    cout << "inserisci i valori" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int t = 0;
    do
    {
        cout << "inserisci un valore tra 1 e 5" << endl;
        cin >> t;

    } while ((t < 0) || (t > 5));

    int *s = Sottocambiona(v, n, t);

    for (int i = 0; i < t; i++)
    {
        cout << "elemento" << i << ":" << s[i] << endl;
        ;
    }

    delete[] s;
    return 0;
}