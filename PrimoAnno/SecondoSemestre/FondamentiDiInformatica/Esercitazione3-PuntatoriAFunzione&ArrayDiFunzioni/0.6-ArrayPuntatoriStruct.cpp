/*
Scrivi un programma che gestisce un array di film utilizzando strutture (struct) e puntatori. L'utente
dovrà inserire le informazioni di tre film, e il programma dovrà determinare e restituire il film più
recente confrontando l'anno di uscita.


*/

#include <iostream>
using namespace std;

struct Film
{
    char titolo[20];
    double durata;
    int anno;
};
/*
▫ La funzione piu_recente riceve come argomento l'array di puntatori a film e il numero di film.

▫ La funzione confronta l'anno di uscita dei film e restituisce il puntatore al film che ha l'anno di uscita più
recente.
▫ Se ci sono più film con lo stesso anno di uscita, la funzione restituisce il primo film con quell'anno.
*/
Film *piu_recente(Film *parray[], int n)
{

    Film *piurec = parray[0];

    for (int i = 1; i < n; i++)
    {
        if ((parray[i]->anno) > (piurec->anno))
        {
            piurec = parray[i];
        }
    }
    return piurec;
}
/*
▫ il programma utilizza un array di puntatori a strutture film. Ogni elemento dell'array punta a un film diverso.

▫ Il programma chiederà all'utente di inserire il titolo, la durata e l'anno di uscita di tre film.
▫ Dopo aver ottenuto i dati, verrà invocata la funzione piu_recente per determinare il film più recente.
▫ Infine, verrà stampato il titolo del film più recente, insieme al suo anno di uscita
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

    Film *ris = piu_recente(parray, n);

    cout << "il film piu recente è: " << ris->titolo << " del " << ris->anno << endl;
    return 0;
}