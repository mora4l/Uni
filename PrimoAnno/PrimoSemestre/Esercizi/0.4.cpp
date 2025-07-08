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
#include <string>
#define tr 13
using namespace std;
int somma(int a[], int n)
{
    /*
    1. La funzione somma che riceva come parametri un array a di numeri interi e la sua dimensione n e restituisca
come valore di ritorno la somma degli elementi contenuti nell’array (un numero intero).


    */
    int som = 0;

    for (int i = 0; i < tr; i++)
    {

        if (a[i] != 0)
        {
            som += a[i];
        }
    }
    return som;
}

int leggi(string s, int n[tr], int &ris, fstream &filelettura)
{
    /*
2. La funzione leggi che riceva come parametri una stringa str, un array num di 13 numeri interi e, per riferimento
(si tratta cioè di un parametro di uscita), un numero intero ris.

La funzione riceve nella stringa str una riga del file Dati.txt, formattata come descritto, scandisce la stringa e assegna agli elementi dell’array num la rappresentazione
decimale dei numeri binari contenuti nella stringa prima del caratten[i]=decimalere ‘=’. Se str contiene meno di 13 addendi, gli
elementi non utilizzati dell’array num vengono impostati a zero.

La funzione assegna infine al parametro ris la
rappresentazione decimale del numero binario che si trova dopo il carattere ‘=’ e restituisce il numero di addendi
contenuti in str e inseriti in num (un numero intero).
Nota: si può usare la funzione converti dell’Esercizio 5.

*/
    string numero2, dopouguale;
    int index = 0;
    int addendi = 0;
    bool afterequal = false;

    for (int i = 0; i < s.length(); i++)
    { // Cicla attraverso ogni carattere della stringa

        if (isdigit(s[i]))
        { // Se è un numero, aggiungilo al numero2
            numero2.push_back(s[i]);
        }

        // Quando trovi il carattere '+', significa che hai completato un addendo
        if (s[i] == '+')
        {
            addendi++; // Incrementa il numero di addendi

            // Converte il numero binario in decimale
            int decimale = 0;
            for (int k = 0; k < numero2.length(); k++)
            {
                decimale = decimale * 2 + (numero2[k] - '0'); // Conversione binario -> decimale
            }
            n[index] = decimale; // Assegna il risultato all'array

            numero2 = ""; // Resetta il numero binario per il prossimo
            index++;      // Aumenta l'indice
        }

        // Se trovi il carattere '=', inizia a raccogliere i bit dopo di esso,MA prima calcola il decimale dell'ultimo valore prima dell'uguale
        if (s[i] == '=')
        {
            afterequal = true;
            addendi++; // Incrementa il numero di addendi

            // Converte il numero binario in decimale
            int decimale = 0;
            for (int k = 0; k < numero2.length(); k++)
            {
                decimale = decimale * 2 + (numero2[k] - '0'); // Conversione binario -> decimale
            }
            n[index] = decimale; // Assegna il risultato all'array

            numero2 = ""; // Resetta il numero binario per il prossimo
            index++;      // Aumenta l'indice
        }

        if (afterequal)
        {
            if (s[i] == '1' || s[i] == '0')
            {
                dopouguale.push_back(s[i]); // Aggiungi i bit a dopouguale
            }
        }
    }
    // Converti i bit dopo '=' in decimale e assegna il risultato a ris
    int risultato = 0;
    for (int z = 0; z < dopouguale.length(); z++)
    {
        risultato = risultato * 2 + (dopouguale[z] - '0');
    }
    ris = risultato; // Assegna il risultato alla variabile ris
    // Restituisci array
    return n[tr];
}
int main()
{

    fstream filelettura;
    fstream filescrittura;

    filelettura.open("Dati.txt", ios::in);
    filescrittura.open("Somme.txt", ios::out);
    /* (b) Per ciascuna riga del file Dati.txt, legga la riga in un’opportuna stringa di caratteri, chiami la funzione leggi per
    ottenere gli addendi e il risultato della somma contenuti nella riga del file, chiami la funzione somma per calcolare
    il risultato corretto della somma degli addendi, verifichi quindi che la somma calcolata corrisponda al risultato
    contenuto nel file, ottenuto dalla funzione leggi.
    Se la somma è corretta, la scriva (in rappresentazione decimale)
    nella corrispondente riga del file Somme.txt, altrimenti scriva “Errore”. */

    string caratteri;
    int num[tr] = {0};
    int ris = 0;
    int a = 0;

    while (!filelettura.eof())
    {

        getline(filelettura, caratteri);

        leggi(caratteri, num, ris, filelettura);
        int risultatodallafunzionesomma = 0;
        risultatodallafunzionesomma = somma(num, a);

        if (risultatodallafunzionesomma == ris)
        {
            filescrittura << "Risultato dell'operazione: " << risultatodallafunzionesomma << endl;
        }
        else
        {
            filescrittura << "Errore" << endl;
        }
    }

    filelettura.close();
    filescrittura.close();
    return 0;
}