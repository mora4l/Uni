/*
Un’azienda di lavori stradali opera su diverse strade e desidera tenere traccia dei lavori eseguiti.
A tal fine si scriva un programma C++ che operi come segue:
dichiari un array km di dieci numeri reali e lo inizializzi in modo che tutti i suoi elementi valgano zero;

apra il file "Lavori.txt", tale file contiene per ciascuna riga
il numero della strada oggetto del lavoro (un numero intero),
il chilometro di inizio lavori (un numero reale) e di fine lavori (un numero reale),
il costo in Euro dei lavori (un numero reale),

il file contiene dieci righe;
per ogni riga del file, inserisca nell’array km

la lunghezza della tratta interessata dai lavori,

calcoli il costo totale dei lavori e
la lunghezza totale delle tratte interessate dai lavori;

stampi a video il costo medio a chilometro, dividendo il costo totale per la lunghezza totale delle tratte interessate.

Si supponga che i valori contenuti nel file siano validi
*/

#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
#define T 10

int main()
{

    double km[T] = {0}, kmstart = 0, kmend = 0, costo = 0;
    int numstrada = 0;

    fstream file;

    file.open("Lavori.txt", ios::in);
    if(!file){
        return 1;
    }

    double lunghtot = 0, costtot = 0;
    int i = 0;

    file >> numstrada >> kmstart >> kmend >> costo;
for(int i =0;i<T;i++){
        file >> numstrada >> kmstart >> kmend >> costo;
        double lung = kmend - kmstart;

        km[i] = lung;
        costtot += costo;
        lunghtot += lung;

}
double mee=costtot/lunghtot;
    cout << "costo medio a km:" << mee << endl;

    file.close();
    return 0;
}