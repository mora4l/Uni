#include "poligono2d.h"
#include "punto2d.h"
#include <iostream>
#include <cmath>
using namespace std;

// • Il costruttore di default che inizializzi _p a NULL e _n a zero.
poligono2d::poligono2d()
{
    _p = NULL;
    _n = 0;
}

/*
• Un costruttore con parametri che riceva in ingresso (ovvero come parametri) un numero intero dim. Il costruttore
effettuerà l’allocazione dinamica di un array di dim oggetti di classe punto2d, ne assegnerà il puntatore a _p e
assegnerà dim a _n. Nel caso in cui l’allocazione dinamica della memoria non vada a buon fine o il valore di dim non
sia valido, il costruttore inizializzerà _p a NULL e _n a zero.
*/
poligono2d::poligono2d(int dim)
{
    if ((dim > 0))
    {

        _p = new punto2d[dim];

        _n = dim;
    }
    else if ((_p == NULL) || (dim < 0))
    {
        _p = NULL;
        _n = 0;
    }
}

/*
• Un costruttore con parametri che riceva in ingresso (ovvero come parametri) un array pti di oggetti di classe
punto2d e la sua dimensione dim (un numero intero). Il costruttore opererà come segue:
*/
poligono2d::poligono2d(punto2d pti[], int dim)
{

    /*
    o nel caso in cui dim assuma un valore valido, effettuerà l’allocazione dinamica di un array di dim oggetti di
    classe punto2d e ne assegnerà il puntatore a _p;
    */
    if (dim > 0)
    {
        _p = new punto2d[dim];
    }
    else if (_p != NULL)
    {
        /*
        o nel caso in cui l’allocazione dinamica della memoria vada a buon fine, assegnerà a ciascun elemento
dell’array puntato da _p, il valore del corrispondente elemento dell’array pti e assegnerà dim a _n;
        */
        for (int i = 0; i < dim; i++)
        {
            _p[i] = pti[i];
        }
        _n = dim;
    }
    else if ((_p = NULL) || dim < 0)
    {
        /*
        o nel caso in cui l’allocazione dinamica della memoria non vada a buon fine o il valore di dim non sia valido, il
costruttore inizializzerà _p a NULL e _n a zero.
        */
        _p = NULL;
        _n = 0;
    }
}

/*
• Il costruttore di copia. Nel caso in cui l’allocazione dinamica della memoria non vada a buon fine, il costruttore
inizializzerà _p a NULL e _n a zero.
*/
poligono2d::poligono2d(poligono2d &p)
{
    cout << "sono il costruttore copia" << endl;
    if (p._n > 0)
    {
        cout << "ho creato memoria dinamica per la copia" << endl;
        _p = new punto2d[p._n];
    }
    if (_p == NULL)
    {

        _n = 0;
        cout << "allocazione della memoria fallita" << endl;
    }
    else
    {
        _n = p._n;
        for (int i = 0; i < _n; i++)
        {
            _p[i] = p._p[i];
        }
    }
}

/*
• Il distruttore.
*/
poligono2d::~poligono2d()
{
    delete[] _p;
    cout << "sono il distruttore" << endl;
}

/*
• I selettori (un metodo per ciascun attributo).
*/
punto2d *poligono2d::getPunto()
{
    return _p;
}
int poligono2d::getN()
{
    return _n;
}

/*
Il modificatore per l’array puntato da _p che riceva in ingresso (ovvero come parametri) un array pti
contenente i nuovi valori e la sua dimensione dim e operi come segue:
*/
void poligono2d::setArray(punto2d pti[], int dim)
{
    /*
    o nel caso in cui il valore di dim sia valido, dichiari un puntatore p a un array di oggetti di classe punto2D,
    effettui l’allocazione dinamica di un array di dim oggetti di classe punto2D e ne assegni il puntatore a p,
    */
    if ((dim > 0))
    {
        punto2d *p;
        p = new punto2d[dim];

        if ((p != NULL))
        {
            /*
            o nel caso in cui l’allocazione dinamica della memoria vada a buon fine, assegni a ciascun elemento
            dell’array puntato da p, il valore del corrispondente elemento dell’array a pti[], deallochi (se esiste) l’array
            puntato da _p, assegni il valore di p al puntatore _p e assegni dim a _n;
            */
            for (int i = 0; i < dim; i++)
            {
                p[i] = pti[i];
            }
            if (p != NULL)
            {
                delete[] _p;
            }
            _p = p;
            _n = dim;
        }
    }
    /*
    o nel caso in cui l’allocazione dinamica della memoria non vada a buon fine o il valore di dim non sia
    valido, il modificatore non opera alcuna modifica ai dati.
    */
    //...
}

/*
• L’operatore di moltiplicazione per scalare
*/
poligono2d poligono2d::operator*(double scalare)
{

    punto2d *_pNuovo = new punto2d[_n]; // creo un array di copia per non modificare quello gia esistente

    for (int i = 0; i < _n; i++)
    {
        _pNuovo[i] = _p[i] * scalare;
    }
    poligono2d risultato;
    risultato.setArray(_pNuovo, _n);
    delete[] _pNuovo;
    return risultato;
}

/*
• L’operatore di assegnamento. Nel caso in cui l’allocazione dinamica della memoria non vada a buon fine,
l’operatore assegnerà NULL a _p e zero a _n,
*/
poligono2d &poligono2d::operator=(const poligono2d &p)
{
    if (this != &p)
    {

        if ((p._p != NULL) && (p._n < 0))
        {
            _n = 0;
            _p = nullptr;
        }
        else
        {

            for (int i = 0; i < _n; i++)
            {
                _p[i] = p._p[i];
            }
        }
    }
    return *this;
}

/*
• L’operatore di selezione con indice,
*/
punto2d &poligono2d::operator[](int indice)
{
    return _p[indice];
}

/*
• L’operatore relazionale di uguaglianza, per il quale due poligoni sono uguali se sono uguali le coordinate di
tutti i punti che ne costituiscono i vertici,
*/
bool poligono2d::operator==(const poligono2d &p)
{
    bool var;
    if (p._n == _n)
    {
        for (int i = 0; i < _n; i++)
        {
            if (_p[i] == p._p[i])
            {
                var = true;
            }
            else
            {
                var = false;
                break;
            }
        }
    }
    return var;
}

/*
Gli operatori di inserimento ed estrazione.
*/
std::istream &operator>>(std::istream &in, poligono2d &p)
{
    cout << "inserisci i valori" << endl;
    for (int i = 0; i < p._n; i++)
    {
        cin >> p._p[i];
    }
    return in;
}
std::ostream &operator<<(std::ostream &out, poligono2d &p)
{
    cout << "Stampo i valori" << endl;
    for (int i = 0; i < p._n; i++)
    {
        cout << p._p[i];
    }
    return out;
}

/*
• Un metodo per calcolare il perimetro del poligono come somma delle distanze tra coppie di vertici
consecutivi.
*/
double poligono2d::perimetro()
{
    double distanza = 0;
    for (int i = 0; i < _n; i += 2)
    {
        distanza += sqrt(pow((_p[i + 1].getX() - _p[i].getX()), 2) + pow((_p[i + 1].getY() - _p[i].getY()), 2));
    }
    return distanza;
}
