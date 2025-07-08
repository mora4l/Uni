/*
Si progetti e si implementi in linguaggio C++ il template di classe array per realizzare un array contenente n
oggetti generici di tipo T. Si supponga che il tipo T sia dotato degli operatori di assegnamento, di inserimento e
di estrazione.

Il template di classe dovrà inoltre fornire i seguenti metodi:

*/
#include <iostream>
using namespace std;

template <typename T>
class Array
{

public:
    Array &operator=(const Array &a); // operatore di assegnamento
    /*
        DANNO PROBLEMI*/
  
/*     
non capisco perche diano problemi 
     friend std::ostream &operator<<(std::ostream &out,const Array<T> &a); //operatore di estrazione
    friend std::istream &operator>>(std::istream &in, Array<T> &a); //operatore di inserimento
       */
    // costruttori
    Array();         // default
    Array(int n);    // con parametri
    Array(Array &a); // copia

    // distruttore
    ~Array();

    // selettore (getter)
    int get_size();
    const T *get_value(const int index);
    const T *get_array();

    // modificatori (setter)
    int set_size(int n);
    int set_value(int index, T data);
    int set_array(T *data, int n);

    // metodi

    void print();
    void read();

private:
    /*
    Il template di classe avrà i seguenti attributi: un puntatore _pdata a un array di oggetti di tipo T
e la dimensione _dim dell’array, cioè il numero di oggetti di cui l’array si compone (un numero intero).
    */
    T *_pdata;
    int _dim;
};

/*
ora faccio i costruttori
*/

/*
• Il costruttore di default che inizializzi _pdata a NULL e _dim a zero.
*/
template <typename T>
Array<T>::Array() : _pdata(NULL), _dim(0) {}

/*
• Un costruttore con parametri che riceva in ingresso (ovvero come parametro) un numero intero n e
operi come segue: verifichi che n sia un numero positivo e, in tal caso, allochi dinamicamente un
array di n oggetti di tipo T, ne assegni il puntatore a _pdata e assegni a _dim il valore n. Nel caso in
cui n sia negativo o nullo, il costruttore inizializzerà _pdata a NULL e _dim a zero.
*/
template <typename T>
Array<T>::Array(int n)
{
    if (n > 0)
    {
        _pdata = new T[n];
        _dim = n;
    }
    else
    {
        _pdata = NULL;
        _dim = 0;
    }
}

/*
• Il costruttore di copia.
*/
template <typename T>
Array<T>::Array(Array &a)
{
    if (a._dim > 0)
    {
        _pdata = new Array[a._dim];
    }
    if (_pdata == NULL)
    {
        _dim = 0;
    }
    else
    {
        _dim = a._dim;
        for (int i = 0; i < _dim; i++)
        {
            _pdata[i] = a._pdata[i];
        }
    }
}

template <typename T>
Array<T>::~Array()
{
    delete[] _pdata;
}

/*
ora faccio i selettori (getter)
*/

/*
• Il selettore get_size che restituisca la dimensione _dim dell’array (un numero intero).
*/
template <typename T>
int Array<T>::get_size()
{
    return _dim;
}
/*
• Il selettore get_value che riceva come parametro un numero intero index e, dopo aver verificato che
index sia compreso tra 0 e _dim – 1, restituisca come valore di ritorno il puntatore all’elemento
dell’array di indice index (un puntatore a costante di tipo T). Nel caso in cui il valore di index non sia
valido o il puntatore _pdata sia nullo, il selettore restituisce NULL.
*/
template <typename T>
const T *Array<T>::get_value(const int index)
{
    if ((index > 0) && (index < _dim - 1) && (_pdata != NULL))
    {
        return _pdata[index];
    }
    return nullptr;
}
/*
il selettore get_array che restituisca come valore di ritorno il puntatore al primo elemento dell’array
(un puntatore a costante di tipo T).
*/
template <typename T>
const T *Array<T>::get_array()
{
    return _pdata[0];
}

/*
ora faccio i modificatori (setter)
*/
/*
 Il modificatore set_size che riceva come parametro un numero intero n, restituisca come valore di
ritorno un numero intero e modifichi l’array in modo tale che esso contenga n elementi. Il
modificatore potrà utilizzare la tecnica di riallocazione già incontrata nelle precedenti esercitazioni.
In particolare, il metodo allocherà un nuovo array di dimensione n, vi copierà gli elementi contenuti
nell’array puntato da _pdata (nel caso in cui la nuova dimensione n sia più piccola della precedente,
gli elementi eccedenti andranno perduti), deallocherà l’array puntato da _pdata e assegnerà a
_pdata il puntatore al nuovo array. Al termine della riallocazione, il modificatore assegnerà a _dim la
nuova dimensione n. Nel caso in cui il valore di n non sia valido o la riallocazione non vada a buon
fine, il metodo non modifica l’array e restituisce 0, altrimenti restituisce 1.
*/
template <typename T>
int Array<T>::set_size(int n)
{

    if (n < 0)
    {
        return 0;
    }

    T nuovoarray = new T[n];

    for (int i = 0; i < _dim; i++)
    {
        nuovoarray[i] = _pdata[i];
    }
    if (nuovoarray == nullptr)
    {
        return 0;
    }
    delete[] _pdata;

    _pdata = nuovoarray;

    _dim = n;
    return 1;
}

/*
• Il modificatore set_value che riceva come parametro un numero intero index e un oggetto data di
tipo T e restituisca come valore di ritorno un numero intero. Dopo aver verificato che index sia
compreso tra 0 e _dim – 1, il modificatore assegna l’oggetto T all’elemento dell’array di indice index.
Nel caso in cui il valore di index non sia valido o il puntatore _pdata sia nullo, il modificatore
restituisce 0, altrimenti restituisce 1
*/
template <typename T>
int Array<T>::set_value(int index, T data)
{

    if ((index < 0) && (index >= _dim - 1) && (_pdata == nullptr))
    {
        return 0;
    }
    _pdata[index] = data;

    return 1;
}

/*
Il modificatore set_array che riceva come parametro un array data di oggetti tipo T e la sua dimensione
n e restituisca come valore di ritorno un numero intero. Dopo aver verificato che n sia pari alla
dimensione _dim dell’array puntato da _pdata, il modificatore copia gli elementi dell’array data negli
elementi dell’array puntato da _pdata. Nel caso in cui il valore di n non sia valido o il puntatore _pdata
sia nullo, il modificatore restituisce 0, altrimenti restituisce 1.
*/
template <typename T>
int Array<T>::set_array(T *data, int n)
{
    if ((n == _dim) && (_pdata != nullptr))
    {
        for (int i = 0; i < n; i++)
        {
            _pdata[i] = data[i];
        }
    }
    else
    {
        return 0;
    }
    return 1;
}

/*
operatori di assegnamento
*/
template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &a) // copia da a in *this e restituisce un riferimento a *this per poter fare x=y=z
{

    if (this != &a) // se l'oggetto è diverso da quello dell'oggetto di riferimento
    {
        if (_pdata != NULL) // se l'array passato ha qualcosa dentro lo svuoto
        {
            delete[] _pdata;
        }
        int n = a._dim; // copio la dimensione dell altro array

        if (n > 0) // se l'array non è nullo
        {
            T *p = new T[n]; // alloco memoria dinamica , con un nuovo array di tipo T con n elementi, è una copia

            if (p != NULL) // se p non punta il vuoto
            {
                _pdata = p; // aggiorno i nuovi valori
                _dim = n;

                for (int i = 0; i < n; i++) // e copio uno ad uno gli elementi dell'array dell oggetto 'a' nell array attuale
                {
                    _pdata[i] = a._pdata[i];
                }
            }
            else
            {
                _pdata = NULL;
                _dim = NULL;
            }
        }
        else
        {
            _pdata = NULL;
            _dim = NULL;
        }
    }
    return *this;
}
/* operatore di inserimento */
 template <typename T>
std::istream operator>>(std::istream &in, Array<T> &a){
    cout<<"inserisci i valori:"<<endl;
    for(int i= 0;i<a._dim;i++){
        in>>a._pdata[i];
    }
    return in;
} 

// operatore di estrazione
 template <typename T>
std::ostream &operator<<(std::ostream &out,const Array<T> &a){
    out<<"ecco i valori dell'array:"<<endl;
    for(int i= 0;i<a._dim;i++){
        out<<a._pdata[i];
    }
    return out;
} 

/*
• Il metodo print che scandisca l’array puntato da _pdata e ne stampi a video gli elementi.
*/
template <typename T>
void Array<T>::print()
{
    for (int i = 0; i < _dim; i++)
    {
        cout << _pdata[i];
    }
}

/*
• Il metodo read che acquisisca da tastiera i valori degli elementi contenuti nell’array puntato da _pdata.
*/
template <typename T>
void Array<T>::read()
{
    cout << "inserisci gli elementi dell array puntato da pdata" << endl;
    for (int i = 0; i < _dim; i++)
    {
        cin >> _pdata[i];
    }
}
/*
Si scriva quindi un programma C++ per verificare il corretto funzionamento del template di classe.
Il programma dichiarerà un oggetto a di tipo "Array", istanziandone il tipo generico con il tipo int e utilizzando
il primo costruttore con parametri passando la dimensione n = 10,

chiederà all’utente di inserire da tastiera gli elementi dell’array a utilizzando il metodo read, stamperà quindi l’intero array utilizzando il metodo print,
infine scandirà l’array calcolando e stampando a video la somma dei valori in esso contenuti.

Provate infine ad aggiungere al template di classe array l’operatore di selezione con indice []. Il template di
classe array così realizzato permette di svolgere le stesse operazioni normalmente supportate dagli array
predefiniti? Permette anche di svolgere ulteriori operazioni che gli array predefiniti non supportano?
*/
int main()
{

    cout<<"AVVERTIMENTO: Gli operatori di inserimento ed estrazione non vanno"<<endl;

    Array<int> a(10);
    cout << "inserisci gli elementi dell'array" << endl;
    a.read();
    a.print();

    return 0;
}