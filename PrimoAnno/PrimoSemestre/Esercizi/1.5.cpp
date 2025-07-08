/*
Un villaggio turistico offre ai propri clienti diverse tipologie di escursioni: 4 escursioni in barca, 6 escursioni in
pullman e 2 escursioni a piedi, per un totale di 12 escursioni diverse; ciascuna escursione ha un proprio prezzo. Allo
scopo di automatizzare la gestione delle escursioni, si sviluppi quanto segue in linguaggio C++:

*/

#include <iostream>
#include <fstream>
#define R 100
#define C 12
using namespace std;

/*
1. La funzione totVendite che riceva come parametri una matrice E di numeri interi di 100 righe e 12 colonne e
restituisca come valore di ritorno un numero intero. Ciascuna riga della matrice E rappresenta un cliente del
villaggio turistico e ciascuna colonna una delle escursioni che il villaggio turistico offre. L’elemento eij della
matrice E vale 1 se il cliente i ha partecipato all’escursione j e 0 altrimenti. Ad esempio, l’elemento e13 vale 1 se il
secondo cliente ha partecipato alla quarta escursione. La funzione calcolerà e restituirà come valore di ritorno il
numero totale di escursioni che il villaggio turistico ha venduto, cioè la somma degli elementi nella matrice E. Per
semplicità si supponga che i dati contenuti in E siano sempre validi.
*/
int totVendite(int E[R][C])
{

    int venditeEscursioniTot = 0;

    for (int i = 1; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            venditeEscursioniTot += E[i][j];
        }
    }

    return venditeEscursioniTot;
}

double totRicavo(double p[C], int E[R][C])
{
    /* 2. La funzione totRicavo che riceva come parametri un array p di 12 numeri reali e una matrice E di numeri interi di
    100 righe e 12 colonne e restituisca come valore di ritorno un numero reale. Ciascun elemento dell’array p
    rappresenta il prezzo di una escursione (il primo elemento il prezzo della prima escursione in barca, il secondo
    elemento il prezzo della seconda escursione in barca e così via). La matrice E è definita come al punto 1 di cui
    sopra. La funzione calcolerà e restituirà come valore di ritorno il ricavo totale ottenuto dal villaggio turistico,
    sommando, per ogni elemento di E con valore 1, il prezzo dell’escursione corrispondente contenuto nell’array p.
    Per semplicità si supponga che i dati contenuti in p e in E siano sempre validi.
    */
    double ricavototaleEscursioni = 0;
    for (int i = 1; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (E[i][j] == 1)
            {
                ricavototaleEscursioni += p[j];
            }
        }
    }
    return ricavototaleEscursioni;
}
/*
3. La funzione elabora che riceva come parametri un array p di 12 numeri reali e una matrice E di numeri interi di
100 righe e 12 colonne, definiti come ai punti 1 e 2 di cui sopra, un array v di 3 numeri interi e un secondo array r
di 3 numeri reali. La funzione calcolerà e assegnerà agli elementi di v rispettivamente il numero di escursioni in
barca, il numero di escursioni in pullman e il numero di escursioni a piedi vendute dal villaggio turistico.

La funzione calcolerà e assegnerà agli elementi di r rispettivamente il ricavo ottenuto dalla vendita delle escursioni in
barca, il ricavo ottenuto dalla vendita delle escursioni in pullman e il ricavo ottenuto dalla vendita delle escursioni
a piedi. Notare che le escursioni in barca corrispondono alle prime 4 colonne di E, quelle in pullman alle
successive 6 colonne e quelle a piedi alle ultime 2 colonne. Per semplicità si supponga che i dati contenuti in p e
in E siano sempre validi. La funzione non restituisce alcun valore di ritorno.
*/
void elabora(double p[C], int E[R][C], int v[3], double r[3])
{

    for (int i = 1; i < R; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            v[0] += E[i][j];
            r[0] += E[i][j] * p[j];
        }
    }
    for (int i = 1; i < R; i++)
    {
        for (int j = 4; j < 10; j++)
        {
            v[1] += E[i][j];
            r[1] += E[i][j] * p[j];
        }
    }
    for (int i = 1; i < R; i++)
    {
        for (int j = 10; j < C; j++)
        {
            v[2] += E[i][j];
            r[2] += E[i][j] * p[j];
        }
    }
}
int main()
{
    /*
    4. La funzione main che operi come segue: dichiari un array pz di 12 numeri reali, una matrice ES di numeri interi di
    100 righe e 12 colonne, un array vd di 3 numeri interi e un array rc di 3 numeri reali; inizializzi a zero tutti gli
    elementi di pz, di ES, di vd e di rc; apra in lettura il file Dati.txt contenente nella prima riga un array di 12 numeri
    reali e nelle righe successive una matrice di numeri interi di 100 righe e 12 colonne e copi la prima riga nell’array
    pz e le righe successive nella matrice ES; chiami la funzione totVendite di cui al punto 1 e stampi a video il suo
    valore di ritorno; chiami la funzione totRicavo di cui al punto 2 e stampi a video il suo valore di ritorno;

    chiami la funzione elabora di cui al punto 3, passandole gli array vd e rc come parametri attuali per i parametri formali v e
    r; stampi il contenuto di vd e rc dopo la chiamata alla funzione elabora e termini restituendo 0. Nel caso in cui il
    file Dati.txt non esista, la funzione terminerà restituendo -1; per semplicità si supponga che i dati contenuti nel
    file Dati.txt siano sempre validi
    */

    double pz[C] = {0};
    int ES[R][C] = {{0}};
    int vd[3] = {0};
    double rc[3] = {0};

    fstream filelettura;

    filelettura.open("DatiEscursioni.txt", ios::in);

    if (!filelettura)
    {
        return -1;
    }
    for (int i = 0; i < C; i++)
    {
        filelettura >> pz[i];
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            filelettura >> ES[i][j];
        }
    }

    int VenditeTotali = totVendite(ES);

    cout << "Le vendite totali sono: " << VenditeTotali << endl;

    double escursionitot = totRicavo(pz, ES);

    cout << "Le escursioni totali sono: " << escursionitot << endl;

    elabora(pz, ES, vd, rc);

    for (int i = 0; i < 3; i++)
     {
        cout << "L'escursione n° " << i << " ha avuto: " << vd[i] << " partecipanti" << endl;
        cout << "L'escursione n° " << i << " ha prodotto: " << rc[i] << " euro" << endl
             << endl;
    }


    return 0;
}