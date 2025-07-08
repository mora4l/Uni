#include "punto2d.h"
#include "poligono2d.h"
#include <iostream>
#include <cmath>
using namespace std;

/*
Si scriva infine un programma C++ per verificare il corretto funzionamento della classe sviluppata.
Il programma:
• chiederà all’utente di inserire da tastiera il numero di vertici desiderato per il poligono,
• dichiarerà un oggetto di classe poligono2d passando al costruttore il numero di vertici desiderato,
• chiederà quindi all’utente di inserire da tastiera le coordinate dei vertici del poligono utilizzando l’operatore
di estrazione,
• calcolerà infine il perimetro del poligono e ne stamperà a video il valore.
*/
int main()
{
    int vertici = 0;
    cout << "inserisci il numero di vertici desiderato" << endl;
    cin >> vertici;
    poligono2d nuovo(vertici);

    cout << "Inserisci le coordinate" << endl;
    cin >> nuovo;

    double ris = nuovo.perimetro();
    cout << "il perimetro è" << endl
         << ris << endl;
    return 0;
}