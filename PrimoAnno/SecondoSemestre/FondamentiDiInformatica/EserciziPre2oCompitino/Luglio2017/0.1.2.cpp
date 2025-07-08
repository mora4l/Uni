/*
Si implementino, inoltre, i seguenti metodi:
o Il costruttore di default che inizializzi il valore di _n a zero e il valore di _p a NULL.


o Il distruttore.
o I selettori (un metodo per ciascun attributo).
o


o Il metodo stampa che stampi a video l’intera matrice diagonale (compresi gli zeri al di fuori della diagonale).

Si sviluppi, infine, la funzione main che operi nel modo seguente:
1. Dichiari un array v di 5 numeri reali e chieda all’utente di inserirne da tastiera gli elementi.
2. Utilizzando il costruttore con parametri, dichiari un oggetto M di classe MatDiag, assegnando il tipo double al
parametro  T.  L’oggetto  M  verrà  inizializzato  passando  al  costruttore  con  parametri  della  classe  MatDiag
l’array v e la sua dimensione (pari a 5).
3. Dichiari un oggetto P di classe MatDiag, assegnando il tipo double al parametro T e assegni M a P.
4. Chieda all’utente di inserire da tastiera un numero reale a e, utilizzando l’operatore *, moltiplichi P per a.
5. Chiamando il metodo stampa della classe MatDiag, stampi le matrici diagonali M e P e termini.
*/
#include <iostream>
using namespace std;

/*Allo scopo di rappresentare le matrici diagonali n × n in un software per il calcolo scientifico, si realizzi in linguaggio
C++ il template di classe MatDiag, parametrizzato sul tipo T e avente per attributi la dimensione _n della matrice (un
numero intero) e un puntatore _p a un array di _n valori di tipo T, che rappresentano gli elementi sulla diagonale della
matrice (gli altri elementi non si rappresentano, avendo valore pari a 0). */
template <typename T>
class matdiag
{

public:
    matdiag();
    matdiag(int n, T D[]);
    matdiag(const matdiag &m);
    ~matdiag();

    int get_n() const;
    T *get_p() const;

    void set_p(T array[]);

    matdiag<T> operator*(const T val);
    matdiag<T> &operator=(const matdiag &m);

    const void stampa();

private:
    int _n;
    T *_p;
};
template <typename T>
matdiag<T>::matdiag()
{
    _n = 0;
    _p = nullptr;
}

/*o Il  costruttore  con  parametri  che  riceva come  parametri  la  dimensione  n  della  matrice (un numero intero)  ed un
array D di n elementi di tipo T, allochi dinamicamente l’array puntato da _p e vi copi gli elementi di D. */
template <typename T>
matdiag<T>::matdiag(int n, T D[])
{
    _n = n;
    _p = new T[_n];
    for (int i = 0; i < n; i++)
    {
        _p[i] = D[i];
    }
}

/*o Il  costruttore  di  copia  che  allochi  dinamicamente  l’array  puntato  da  _p,  copiando  la  dimensione  dell’array  e
l’array stesso dall’oggetto passato come parametro.  */
template <typename T>
matdiag<T>::matdiag(const matdiag &m)
{
    _n = m._n;
    T *_p = new T[_n];
    for (int i = 0; i < _n; i++)
    {
        _p[i] = m._p[i];
    }
}

template <typename T>
matdiag<T>::~matdiag()
{
    delete[] _p;
}

template <typename T>
int matdiag<T>::get_n() const
{
    return _n;
}
template <typename T>
T *matdiag<T>::get_p() const
{
    return _p;
}

/*Il  modificatore  per l’array  puntato  da  _p.  Il  modificatore  riceverà  come  parametro  un  array  contenente  i  nuovi
valori. Per semplicità, si supponga che l’array puntato da _p sia già stato correttamente allocato delle dimensioni
volute e che l’array passato come parametro al modificatore abbia le dimensioni corrette. */
template <typename T>
void matdiag<T>::set_p(T array[])
{
    for (int i = 0; i < _n; i++)
    {
        _p[i] = array[i];
    }
}

/*o L’operatore  *  che  riceva  come  parametro  un  valore  di  tipo  T  e  moltiplichi  ciascun  elemento  della  matrice
diagonale per tale valore. L’operatore restituirà come valore di ritorno un riferimento a MatDiag. */
template <typename T>
matdiag<T> matdiag<T>::operator*(const T val)
{
    for (int i = 0; i < _n; i++)
    {
        _p[i] *= val;
    }
    return *this;
}

/*o L’operatore  di  assegnamento.  L’operatore  deallocherà  l’array  puntato  da  _p  e  lo  riallocherà  delle  dimensioni
opportune, copiandolo dall’oggetto passato come parametro. */
template <typename T>
matdiag<T> &matdiag<T>::operator=(const matdiag &m)
{
    if (this != &m)
    {
        if (_p != nullptr)
        {
            delete[] _p;
            if (m._n != 0)
            {
                _p = new T[m._n];
                for (int i = 0; i < _n; i++)
                {
                    _p[i] = m._p[i];
                }
            }
            else
            {
                _p = nullptr;
                _n = 0;
            }
        }
        else
        {
            _p = nullptr;
            _n = 0;
        }
    }
    return *this;
}

template <typename T>
const void matdiag<T>::stampa()
{
    for (int i = 0; i < _n; i++)
    {
        cout << _p[i];
    }
}

/*
 */

int main()
{

    return 0;
}