/*
Il file Dati.txt contiene, per ciascuna riga, una somma di numeri interi positivi in rappresentazione binaria e il risultato
della somma stessa secondo il seguente formato:
001100+01101+0101=011110;
0011+0101=1000;
00011+000111+000111+01010=0110011;
…
Il numero di righe di cui si compone il file non è noto al programmatore. Ciascuna riga contiene al più 127 caratteri. I
numeri binari sono composti al più da 8 bit. Ogni riga contiene almeno 2 e non più di 13 addendi. Si supponga, inoltre,
che i dati siano validi (è cioè garantito che tutte le righe del file seguono il formato specificato). Non è però garantito
che i risultati delle somme siano corretti: alcuni risultati potrebbero quindi essere errati. Per elaborare le operazioni
contenute nel file e individuare eventuali errori, si sviluppi quanto segue in linguaggio C++:


*/
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
/*
1. La funzione somma che riceva come parametri un array a di numeri interi e la sua dimensione n e restituisca
come valore di ritorno la somma degli elementi contenuti nell’array (un numero intero).
*/

int somma(int array[], int n)
{
    int sommaValori = 0;
    for (int i = 0; i < n; i++)
    {
        sommaValori += array[i];
    }
    return sommaValori;
}

/*
2. La funzione leggi che riceva come parametri una stringa str, un array num di 13 numeri interi e, per riferimento
(si tratta cioè di un parametro di uscita), un numero intero ris. La funzione riceve nella stringa str una riga del file
Dati.txt, formattata come descritto, scandisce la stringa e assegna agli elementi dell’array num la rappresentazione
decimale dei numeri binari contenuti nella stringa prima del carattere ‘=’. Se str contiene meno di 13 addendi, gli
elementi non utilizzati dell’array num vengono impostati a zero. La funzione assegna infine al parametro ris la
rappresentazione decimale del numero binario che si trova dopo il carattere ‘=’ e restituisce il numero di addendi
contenuti in str e inseriti in num (un numero intero). Nota: si può usare la funzione converti dell’Esercizio 5.
*/
int leggi(string str, int num[13], int &ris)
{
    int addendi = 0;
    int decimale = 0;
    num = {0};
    int a =0  ;
    for (int i = str.size()-1; i >=0 ; i--)
    {
        char c = str[i];

        if (isdigit(c))
        {
            cout<<"Ho un nuovo numero nella posizione "<<i<<" ed è "<<c<<endl;
            decimale += (c - '0') * pow(2,a);
            a++;
        }
        else if (c == '+')
        {

            num[addendi] = decimale;
            decimale = 0;
            addendi++;
            a=0;

            
        }
        else if (c == '=')
        {

            cout<<" il risultato in decimale del numero è "<<decimale<<endl;
            ris = decimale;
            decimale = 0;
            a=0;
        }
        
    }
    return addendi;
}

int main()
{
    /*
    3. Un programma che operi come segue. (a) Apra in lettura il file Dati.txt e in scrittura il file Somme.txt. (b) Per
ciascuna riga del file Dati.txt, legga la riga in un’opportuna stringa di caratteri, chiami la funzione leggi per
ottenere gli addendi e il risultato della somma contenuti nella riga del file, chiami la funzione somma per calcolare
il risultato corretto della somma degli addendi, verifichi quindi che la somma calcolata corrisponda al risultato
contenuto nel file, ottenuto dalla funzione leggi.

Se la somma è corretta, la scriva (in rappresentazione decimale)
nella corrispondente riga del file Somme.txt, altrimenti scriva “Errore”. (c) Dopo aver elaborato l’intero file
Dati.txt, chiuda entrambi i file e stampi a video il numero di somme per le quali è stato rilevato un risultato
corretto, il numero di somme per le quali è stato rilevato un risultato errato e la media (in rappresentazione
decimale) dei risultati delle somme per le quali il risultato era corretto.
Ad esempio, nel caso sopra riportato, il programma individuerà due somme corrette, una somma errata e la media dei
risultati delle somme corrette vale 19. Inoltre, il file Somme.txt conterrà le seguenti righe:
30
8
Errore
…
    */

    // a

    fstream filelettura;
    fstream filescrittura;
    int n = 13, sommma = 0, numerosommegiuste = 0, numerosommesbagliate = 0;
    int array[n] = {0};
    int media[n] = {0};
    int risultato = 0;

    filelettura.open("DatiBinary.txt", ios::in);
    filescrittura.open("Somme.txt", ios::out);
    if (!filelettura||!filescrittura)
    {
        cout<<"errore apertura file "<<endl;
        return -1;
    }
    string stringa;
    // b
    int i = 0;
    while (!filelettura.eof())
    {
        getline(filelettura, stringa);
        leggi(stringa, array, risultato);
        sommma = somma(array, n);

        if (sommma == risultato)
        {
            media[i] = risultato;
            filescrittura << somma;
            numerosommegiuste++;
        }
        else
        {
            filescrittura << "errore";
            numerosommesbagliate++;
        }

        risultato=0;
        i++;
    }
    // c
    filescrittura.close();
    filelettura.close();
    cout << "numero somme corrette: " << numerosommegiuste << endl;
    cout << "numero somme scorrette: " << numerosommesbagliate << endl;
    int mediarisultato = 0;

    for (int i = 0; i < n; i++)
    {

        mediarisultato += media[i];
    }
    mediarisultato = mediarisultato / numerosommegiuste;
    cout << "La media delle somme giuste è: " << mediarisultato << endl;

    return 0;
}