/*
Scrivere un programma in C++ che gestisca un array dinamico di caratteri, permettendo all'utente di eseguire le
seguenti operazioni in seguente ordine:

*/

#include <iostream>
using namespace std;
/*
3. Inserire un nuovo carattere: Successivamente, il programma deve chiedere all'utente la posizione in cui inserire
un nuovo carattere e il carattere stesso. La funzione dovrà gestire l'inserimento e restituire il puntatore all'array
aggiornato.
*/
char *inserimento(char *a, char c, int pos, int dim)
{

    char *nuovo = new char[dim + 1];

    for (int i = 0; i < pos; i++)
    {
        nuovo[i] = a[i];
    }

    nuovo[pos] = c;

    for (int i = pos + 1; i < dim; i++)
    {
        nuovo[i] = a[i];
    }

    for (int i = 0; i < dim; i++)
    {
        a[i] = nuovo[i];
    }
delete[] nuovo;

    return a;
}

/*
4. Cancellare un carattere: Il programma deve poi chiedere all'utente di indicare la posizione dell'elemento che
vuole cancellare. Una funzione dovrà gestire la cancellazione del carattere nella posizione specificata e restituire
il puntatore all'array modificato.
*/
char *elimina(char *a, int dim, int posdel)
{
    char *nuovo2 = new char[dim];

    for (int i = 0; i < posdel; i++)
    {
        nuovo2[i] = a[i];
    }
    for (int i = posdel+1; i < dim; i++)
    {
        nuovo2[i] = a[i];
    }

    for (int i = 0; i < dim; i++)
    {
        a[i] = nuovo2[i];
    }
delete[] nuovo2;

    return a;
}

/*
1. Inserire caratteri nell'array: Il programma deve chiedere all'utente quanti caratteri vuole inserire, allocare
dinamicamente un array per questi caratteri e poi consentire all'utente di inserire i caratteri uno alla volta.

2. Visualizzare l'array: Dopo aver inserito i caratteri, il programma deve stampare l'array creato dall'utente.

*/
int main()
{

    cout << "inserisci il numero di caratteri che l'array deve avere: " << endl;
    int dim = 0;
    cin >> dim;

    char *a = new char[dim];

    for (int i = 0; i < dim; i++)
    {
        cin >> a[i];
    }

    cout << "array inserito : " << endl;

    for (int i = 0; i < dim; i++)
    {
        cout << a[i];
    }

    cout << endl
         << "ora devi inserire un nuovo carattere:" << endl;
    char c;
    cin >> c;

    cout << "In che posizione lo inseriamo?" << endl;
    int pos = 0;
    cin >> pos;
    if (pos > dim)
    {
        return -1;
    }

    a = inserimento(a, c, pos, dim);
    cout << "array nuovo:" << endl;
    for (int i = 0; i < dim; i++)
    {
        cout << a[i] << endl;
    }
    
    cout<<"dimmi in che posizione dell'array vuoi eliminare un carattere:"<<endl;
    int posdel=0 ;
        cin>>posdel;
    if(posdel>dim){
        return -1;
    }
    a=elimina(a,dim,posdel);
    cout<<"array con elemento eliminato :"<<endl;
/*     5. Visualizzare l'array finale: Infine, il programma deve stampare l'array dopo ogni operazione di inserimento e
cancellazione, in modo da permettere all'utente di vedere l'array aggiornato. */
        for (int i = 0; i < dim; i++)
    {
        cout << a[i] << endl;
    }

/*     6. Deallocazione della memoria: Al termine, il programma deve deallocare la memoria dinamica utilizzata per gli
array. */

    return 0;
}