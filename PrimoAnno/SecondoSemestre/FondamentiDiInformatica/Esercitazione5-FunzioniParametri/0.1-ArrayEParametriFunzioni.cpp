/*
Si scriva il template di funzione C++ contaDistinti che riceva come parametri un array a di elementi di
tipo T e la sua dimensione n (un numero intero), calcoli e restituisca come valore di ritorno il numero di
elementi distinti contenuti nell’array a (un numero intero).



• Nota: per conoscere la dimensione effettiva della stringa inserita dall’utente, si può usare la funzione
strlen disponibile nella libreria cstring.
• Esempio: dato l’array a = {1, 3, 5, 6, 5, 2, 1, 5, 3, 6} (n = 10), la funzione restituirà 5. L’array a contiene cioè
5 valori distinti (per la precisione si tratta dei valori: 1, 2, 3, 5, 6).
*/
/*
Da fare a casa: estendere il template di funzione contaDistinti in modo che riceva come parametro un ulteriore
array f di numeri reali, della stessa dimensione dell’array a. La funzione assegnerà a ciascun elemento di f la
frequenza del corrispondente elemento di a. La frequenza di un elemento di un array è definita come il numero
di volte in cui l’elemento compare nell’array diviso per la dimensione dell’array. Nel caso dell’esempio di prima,
l’array f sarà dunque il seguente:
f = {0.2, 0.2, 0.3, 0.2, 0.3, 0.1, 0.2, 0.3, 0.2, 0.2}.
L’elemento 1 compare cioè 2 volte su 10, l’elemento 3 compare 2 volte su 10, l’elemento 5 compare 3 volte su
10 e così via.
*/
#include <iostream>
using namespace std;
#define I 10
template <typename T, typename S>

int contaDistinti(T a[], S b[])
{
    int el = 0;

    for (int i = 0; i < I; i++)
    {
        bool trovato = false; // Flag per verificare se l'elemento è già stato incontrato
        // Controlla se l'elemento a[i] è già stato visto
        for (int j = 0; j < i; j++)
        {
            if (a[i] == a[j])
            {
                trovato = true;
                break; // Se l'elemento è stato trovato, non lo consideriamo
            }
        }

        // Se l'elemento non è stato trovato prima, incrementiamo il contatore
        if (!trovato)
        {
            el++;
        }
    }

    for (int i = 0; i < I; i++)
    {
        int freq = 1;

        for (int j = i + 1; j < I; j++)
        {
            if (a[i] == a[j])
            {
                freq++;
            }
        }
        b[i] = freq;
    }
    for (int i = 0; i < I; i++)
    {
        cout << b[i] << endl;
    }

    return el;
}

/*
• Si scriva quindi un programma per verificare il corretto funzionamento del template di funzione.
Il programma chiederà all’utente di inserire da tastiera i valori per un array di 10 numeri interi, per un
array di 10 numeri reali e per una stringa contenente al massimo 9 caratteri, chiamerà contaDistinti per
ciascuno dei tre array e stamperà a video i tre valori di ritorno. Tali operazioni potranno essere ripetute
finché l’utente lo desidera.

*/
int main()
{

    int arr[I] = {0};
    double arr2[I] = {0};
    string arr3[10];
    double arr4[10] = {0};
    cout << "inserisci arr" << endl;
    for (int i = 0; i < I; i++)
    {
        cin >> arr[i];
    }
    /*         cout<<"inserisci arr2"<<endl;
        for(int i =0 ; i<I; i++){
            cin>>arr2[i];
        }
            cout<<"inserisci arr3"<<endl;
        for(int i =0 ; i<I; i++){
            cin>>arr3[i];
        }
     */
    int ris = contaDistinti(arr, arr4);
    cout << "elementi arr: " << ris << endl;
    /*
            int ris2= contaDistinti(arr2,arr4);
        cout<<"elementi arr2: "<<ris2<<endl;

            int ris3= contaDistinti(arr3,arr4);
            cout<<"elementi arr3: "<<ris3<<endl;
     */
    return 0;
}