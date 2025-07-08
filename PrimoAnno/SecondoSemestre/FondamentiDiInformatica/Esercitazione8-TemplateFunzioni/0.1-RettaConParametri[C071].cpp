/*
Allo scopo di sviluppare un software per la geometria analitica si realizzi in linguaggio C++ il template di classe
Retta, parametrizzato sul tipo T ed avente per attributi il coefficiente angolare _m e l’intercetta _q (entrambi
di tipo T) di una retta sul piano cartesiano, secondo l’equazione y = mx + q. Si implementino, inoltre, i seguenti
metodi:
*/
#include <iostream>
#include <math.h>
using namespace std;

template <typename T>
class Retta
{

public:
    // costruttori
    Retta();         // default
    Retta(T m, T q); // con parametri
    Retta(Retta &r); // copia

    // distruttore
    ~Retta();

    // selettori (getter)
    T getM();
    T getQ();

    // modificatori (setter)
    void setM(T m);
    void setQ(T q);

    // metodi
    void InserisciDati();
    void stampaDati();
    T calcolaDistanza(T xP, T yP);

private:
    T _m;
    T _q;
};

/* • Il costruttore di default che inizializzi il valore di _m e di _q a zero, utilizzando la lista di inizializzazione. */
template <typename T>
Retta<T>::Retta() : _m(0), _q(0) {}

/*
• Il costruttore con parametri che riceva come parametri il valore del coefficiente angolare m e
dell’intercetta q (entrambi di tipo T) ed inizializzi i corrispondenti attributi della classe usando la lista di
inizializzazione.
*/
template <typename T>
Retta<T>::Retta(T m, T q) : _m(m), _q(q) {}

/*
Il costruttore di copia
*/
template <typename T>
Retta<T>::Retta(Retta &r) : _m(r._m), _q(r._q) {}

/*
• Il distruttore
*/
template <typename T>
Retta<T>::~Retta() {}

/*
• I selettori (un metodo per ciascun attributo)
*/
template <typename T>
T Retta<T>::getM()
{
    return _m;
}
template <typename T>
T Retta<T>::getQ()
{
    return _m;
}

/*
• I modificatori (un metodo per ciascun attributo)
*/
template <typename T>
void Retta<T>::setM(T m)
{
    _m = m;
}
template <typename T>
void Retta<T>::setQ(T q)
{
    _q = q;
}

/*
• Il metodo inserisciDati per leggere da tastiera i valori del coefficiente angolare _m e dell’intercetta _q. Il
metodo non restituisce alcun valore di ritorno.
*/
template <typename T>
void Retta<T>::InserisciDati()
{
    cout << "inserisci i dati " << endl;
    cin >> _m >> _q;
}

/*
• Il metodo stampaDati che stampi a video l’equazione della retta secondo il seguente formato: r: y = mx
+ q; dove a m viene sostituito il valore corrente di _m e a q il valore corrente di _q. Il metodo non
restituisce alcun valore di ritorno.
*/
template <typename T>
void Retta<T>::stampaDati()
{
    cout << "la retta ha forma:" << endl;
    cout << "y=" << _m << "x+" << _q << endl;
}
/*
Il metodo calcolaDistanza che riceva come parametri le coordinate (xP, yP) di un punto P (due
valori di tipo T), calcoli e restituisca come valore di ritorno la distanza d di P dalla retta (un numero
reale), calcolata come: d= ( | y(p)-(mx(p)+q |) / (rad(1+m^2) )
*/
template <typename T>
T Retta<T>::calcolaDistanza(T xP, T yP)
{

    return (yP - (_m + _q)) / sqrt(1 + pow(_m, 2));
    ;
}
/*
Si sviluppi, infine, la funzione main che operi nel modo seguente:
*/
int main()
{

    /*
    • Dopo aver chiesto all’utente di inserire da tastiera un numero intero n e avere verificato che n sia positivo, allochi
    dinamicamente un array R di n oggetti di classe Retta, assegnando il tipo double al parametro T. Nel caso in cui n sia
    negativo, main terminerà stampando a video un messaggio di errore.
    */
    int n = 0;
    cout << "inserisci il numero di oggetti Retta che vuoi avere" << endl;
    cin >> n;

    if (n < 0)
    {
        cout << "valore non consentito , coglione" << endl;
        return -1;
    }

    Retta<double> *R = new Retta<double>[n];

    /*
    • Scandisca l’array R e assegni i valori di _m e _q a ciascun elemento di R, chiamando il metodo inserisciDati.
    */
    for (int i = 0; i < n; i++)
    {
        R[i].InserisciDati();
    }

    /*
    • Chieda all’utente di inserire le coordinate (xQ, yQ) di un punto Q (due numeri reali), scandisca l’array R, invochi su
    ciascun elemento dell’array R la funzione calcolaDistanza e ne stampi a video il valore di ritorno (ovvero la distanza
    del punto Q da ciascuna delle rette contenute nell’array R).
    */
    cout << "inserisci le coordinate del punto Q" << endl;
    double xQ = 0, yQ = 0;
    cin >> xQ >> yQ;

    for (int i = 0; i < n; i++)
    {
        double distanza = 0;
        distanza = R[i].calcolaDistanza(xQ, yQ);
        cout << distanza << endl;
    }

    /*
    • Deallochi l’array R e termini.
    */
    delete[] R;

    return 0;
}