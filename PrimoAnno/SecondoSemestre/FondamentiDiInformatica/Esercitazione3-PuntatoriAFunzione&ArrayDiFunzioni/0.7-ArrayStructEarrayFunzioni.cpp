/*
Scrivi un programma che gestisca una lista di film, memorizzando i dati relativi a ciascun film in una
struttura film. Ogni film ha un titolo, una durata, e un anno di uscita. Il programma dovrà svolgere le
seguenti operazioni:
▫ permettere all'utente di inserire i dati di tre film.
▫ creare un array di puntatori a queste strutture film.
▫ utilizzare un array di puntatori a funzioni per eseguire le seguenti operazioni in ordine:
 stampare le informazioni sui film.
 aggiornare la durata di ogni film, impostando la durata a 120 minuti per i film con durata maggiore.
 stampare nuovamente le informazioni sui film aggiornati.

▫ Perciò servono 2 funzioni:

*/

#include <iostream>
using namespace std;
/*
Scrivi un programma che gestisca una lista di film, memorizzando i dati relativi a ciascun film in una
struttura film. Ogni film ha un titolo, una durata, e un anno di uscita. Il programma dovrà svolgere le
seguenti operazioni:
*/

struct Film
{
    char titolo[20];
    double durata;
    int anno;
};

/*
 funzione aggiorna_durata: prende un array di puntatori a film e un intero n, e aggiorna la durata del film a 120
minuti se la durata è maggiore di 120 minuti.
*/
void aggiorna_durata(Film *parray[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if ((parray[i]->durata) > 120)
        {
            parray[i]->durata = 120;
        }
    }
}
/*
 funzione stampa_film: prende un array di puntatori a film e un intero n, e stampa le informazioni di ogni film
nell'array.
*/
void stampa_film(Film *parray[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << "titolo film" << i << ":" << parray[i]->titolo << endl;
        cout << "durata film" << i << ":" << parray[i]->durata << endl;
        cout << "anno di pubblicazione film" << i << ":" << parray[i]->anno << endl;
    }
}
/*
▫ In main():
 viene creato un array di puntatori a film per memorizzare i dati dei film.
 viene creato un array di puntatori a funzioni per eseguire le operazioni di stampa e aggiornamento durata.
 un ciclo for esegue ogni funzione nell'array di puntatori a funzioni, passando l'array di film
*/
int main()
{
    int n = 3;
    Film *parray[n];

    Film film1;
    cout << "inserisci il titolo 1:" << endl;
    cin >> film1.titolo;
    cout << "inserisci la durata [min]" << endl;
    cin >> film1.durata;
    cout << "inserisci anno" << endl;
    cin >> film1.anno;

    parray[0] = &film1;

    Film film2;
    cout << "inserisci il titolo 2:" << endl;
    cin >> film2.titolo;
    cout << "inserisci la durata [min]" << endl;
    cin >> film2.durata;
    cout << "inserisci anno" << endl;
    cin >> film2.anno;

    parray[1] = &film2;

    Film film3;
    cout << "inserisci il titolo 3:" << endl;
    cin >> film3.titolo;
    cout << "inserisci la durata [min]" << endl;
    cin >> film3.durata;
    cout << "inserisci anno" << endl;
    cin >> film3.anno;

    parray[2] = &film3;

    void (*pf[2])(Film *[], int) = {aggiorna_durata, stampa_film};

    for (int i = 0; i < 2; i++)
    {
        (pf[i])(parray, n);
    }
    return 0;
}