/*
Un’azienda ha otto dipartimenti. I dipendenti che lavorano in ciascun dipartimento possono
appartenere ad una di cinque diverse classi stipendiali.
*/
#include <iostream>
#include <fstream>
using namespace std;
class Dipendente
{
public:
    // costruttori
    Dipendente();                       // default
    Dipendente(double s[], int D[][5]); // conm parametri
    Dipendente(Dipendente &d);          // di copia

    // distruttore
    ~Dipendente();

    // setter
    void setS(double s[]);
    void setD(int D[][5]);

    // getter
    const double *getS();
    int getD(int h, int k);

    // metodi
    int totaleDipendenti(int D[][5]);
    void estremiStipendio(int &minimo, int &massimo);

private:
    /*
    • un array _s di cinque numeri reali per rappresentare lo stipendio corrispondente a ciascuna delle
    cinque classi stipendiali e
    • una matrice di numeri interi _D di otto righe e cinque colonne i cui elementi rappresentano, per
    ciascun dipartimento, il numero di dipendenti appartenenti a ciascuna classe stipendiale. Se, ad
    esempio, l’elemento nella terza riga e quarta colonna di _D valesse 10, significherebbe che nel terzo
    dipartimento lavorano 10 dipendenti appartenenti alla quarta classe stipendiale
    */
    double _s[5];
    int _D[8][5];
};

/*
• Il costruttore di default che inizializzi a zero tutti gli elementi dell’array _s e della matrice _D.
*/
Dipendente::Dipendente()
{
    for (int i = 0; i < 5; i++)
    {
        _s[i] = 0;
    }
    for (int i = 0; i < 8; i++)
    {

        for (int j = 0; j < 5; j++)
        {
            _D[i][j] = 0;
        }
    }
}

/*
• Il costruttore con parametri che riceva come parametri un array di cinque numeri reali e una matrice
di numeri interi di otto righe e cinque colonne e li assegni rispettivamente all’array _s e alla matrice
_D. Per semplicità si supponga che i valori passati al costruttore siano sempre validi.
*/
Dipendente::Dipendente(double s[], int D[][5])
{
    for (int i = 0; i < 5; i++)
    {
        _s[i] = s[i];
    }
    for (int i = 0; i < 8; i++)
    {

        for (int j = 0; j < 5; j++)
        {
            _D[i][j] = D[i][j];
        }
    }
}

/*
• Il costruttore di copia.
*/
Dipendente::Dipendente(Dipendente &d)
{
    for (int i = 0; i < 5; i++)
    {
        _s[i] = d._s[i];
    }
    for (int i = 0; i < 8; i++)
    {

        for (int j = 0; j < 5; j++)
        {
            _D[i][j] = d._D[i][j];
        }
    }
}

/*
• Il distruttore.
*/
Dipendente::~Dipendente()
{
    cout << "sono il distruttore [Dipendente]" << endl;
}

/* • I selettori per l’array _s e per la matrice _D:
- Il selettore per _s restituirà come valore di ritorno un puntatore a costante all’array stesso.
- Il selettore per _D riceverà in ingresso (ovvero come parametri) due numeri interi h e k e
restituirà come valore di ritorno l’elemento della matrice _D di indici h e k (un numero intero). Nel caso in
cui il valore di almeno uno dei due parametri h e k non fosse valido, il metodo restituirà -1.
 */
const double *Dipendente::getS()
{
    return _s;
}
int Dipendente::getD(int h, int k)
{
    if ((h < 0) || (k < 0))
    {
        return -1;
    }
    else
    {

        return _D[h][k];
    }
}
/*
I modificatori per l’array _s e per la matrice _D. Per semplicità, si supponga che l’array passato
come parametro al modificatore per _s e la matrice passata come parametro al modificatore per
_D abbiano le dimensioni corrette e che i loro elementi assumano valori validi.
*/
void Dipendente::setS(double s[])
{
    for (int i = 0; i < 5; i++)
    {
        _s[i] = s[i];
    }
}
void Dipendente::setD(int D[][5])
{
    for (int i = 0; i < 8; i++)
    {

        for (int j = 0; j < 5; j++)
        {
            _D[i][j] = D[i][j];
        }
    }
}

/*
Il metodo totaleDipendenti che calcoli e restituisca come valore di ritorno il numero totale dei
dipendenti dell’azienda (un numero intero dato dalla somma degli elementi della matrice _D)
*/
int Dipendente::totaleDipendenti(int D[][5])
{
    int somma = 0;
    for (int i = 0; i < 8; i++)
    {

        for (int j = 0; j < 5; j++)
        {
            somma += _D[i][j];
        }
    }
    return somma;
}
/*
• Il metodo estremiStipendio che calcoli e restituisca come parametri di uscita (ovvero passati per
riferimento) gli indici dei due dipartimenti (due numeri interi) per i quali l’azienda spende
l’ammontare massimo e l’ammontare minimo per gli stipendi dei dipendenti. Il metodo non
restituisce alcun valore di ritorno
*/
void Dipendente::estremiStipendio(int &minimo, int &massimo)
{
    int spese[8];
    minimo = spese[0];
    massimo = spese[0];

    for (int i = 0; i < 8; i++)
    {

        for (int j = 0; j < 5; j++)
        {

            spese[i] += _s[j] * _D[i][j];
        }
    }
    for (int i = 0; i < 8; i++)
    {

        if (spese[i] > massimo)
        {
            massimo = i;
        }
        if (spese[i] < minimo)
        {
            minimo = i;
        }
    }
}

int main()
{
    /*
    • Dichiari un array stp di cinque numeri reali e una matrice di numeri interi Dip di otto righe e cinque colonne.
     */
    double stp[5];
    int Dip[8][5];

    /*
    • Apra in lettura il file Dati.txt. Tale file contiene nella prima riga cinque numeri reali che rappresentano gli
    stipendi associati a ciascuna classe stipendiale e nelle otto righe successive, per ciascuna riga, cinque
    numeri interi che rappresentano il numero di dipendenti inquadrati in ciascuna classe stipendiale per il
    dipartimento corrispondente alla riga in esame. Per semplicità si supponga che i valori contenuti nel file
    siano validi. Nel caso in cui il file Dati.txt non esista, main termina con valore di ritorno -1.
    */
    fstream file;
    file.open("Dati0.1.txt", ios::in);

    if (!file)
    {
        return -1;
    }

    /*
    • Legga la prima riga del file Dati.txt assegnandone i valori agli elementi dell’array stp e le righe
    successive assegnandone i valori agli elementi della matrice Dip.
    */

    for (int i = 0; i < 5; i++)
    {
        file >> stp[i];
    }

    for (int i = 0; i < 8; i++)
    {

        for (int j = 1; j < 5; j++)
        {
            file >> Dip[i][j];
        }
    }

    /*
    • Utilizzando il costruttore con parametri, allochi dinamicamente un oggetto pdip di tipo Dipendenti,
    passando l’array stp e la matrice Dip come parametri al costruttore.
    */
    Dipendente *pdip = new Dipendente(stp, Dip);

    /*
    • Invochi su tale oggetto i metodi totaleDipendenti ed estremiStipendio e stampi a video il risultato.
    */
    int minimo = 0;
    int massimo = 0;
    int somma = pdip->totaleDipendenti(Dip);
    pdip->estremiStipendio(minimo, massimo);

    cout << "totale dipendenti:" << somma << endl
         << endl
         << "Estremi stipendio:" << endl
         << minimo << "," << massimo << endl;

    /*
    • Deallochi l’oggetto pdip e termini.
    */
    delete pdip;
    return 0;
}