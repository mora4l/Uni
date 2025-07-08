/*
Si rielabori il programma già sviluppato per la risoluzione di una equazione di secondo
grado (Esercizio 3.1) in questo modo:
− Si definisca una struttura equazione che abbia come campi i tre coefficienti a, b e c
(tre numeri reali) di una equazione di secondo grado nella forma ax^2 + bx + c = 0.
− Si definisca una struttura soluzione che abbia come campi le due soluzioni x1 e x2
(due numeri reali).
− Si definisca la funzione risolvi che riceva come parametro in ingresso una struttura di tipo
equazione, come parametro di uscita una struttura di tipo soluzione e restituisca come
valore di ritorno 1 se l’equazione ha soluzioni reali e 0 altrimenti.
− Si rielabori la funzione main in modo da utilizzare le strutture e la funzione definite sopra.
*/

#include <iostream>
#include <cmath>
using namespace std;

struct Equazione
{
    double a, b, c;
};
struct Soluzione
{
    double x1, x2;
};

int risolvi(Equazione &eq, Soluzione &sol)
{
    int ret = 0;
    double delta = 0, ris1 = 0, ris2 = 0;

    delta = sqrt(eq.b * eq.b - 4 * eq.a * eq.c);

    sol.x1 = (-eq.b + delta) / 2 * eq.a;
    sol.x2 = (-eq.b - delta) / 2 * eq.a;

    if (delta > 0)
    {
        ret = 1;
    }
    else
    {
        ret = 0;
    }

    return ret;
}

int main()
{

    Equazione eq;
    Soluzione sol;
    cout << "Inserisci il valore a: " << endl;
    cin >> eq.a;
    cout << "Inserisci il valore b: " << endl;
    cin >> eq.b;
    cout << "Inserisci il valore c: " << endl;
    cin >> eq.c;

    int risultati = risolvi(eq, sol);

    if (risultati == 0)
    {
        cout << "Non ha soluzioni in R. " << endl;

        return 1;
    }
    else
    {
        cout << "Le soluzioni sono x1= " << sol.x1 << " , x2= " << sol.x2 << endl;
    }

    return 0;
}