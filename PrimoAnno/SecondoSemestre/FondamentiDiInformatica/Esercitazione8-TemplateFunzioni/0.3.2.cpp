/*
Provate infine ad aggiungere al template di classe array l’operatore di selezione con indice []. Il template di
classe array così realizzato permette di svolgere le stesse operazioni normalmente supportate dagli array
predefiniti? Permette anche di svolgere ulteriori operazioni che gli array predefiniti non supportano?
*/
#include <iostream>
using namespace std;
/*Si progetti e si implementi in linguaggio C++ il template di classe array per realizzare un array contenente n
oggetti generici di tipo T. Si supponga che il tipo T sia dotato degli operatori di assegnamento, di inserimento e
di estrazione. Il template di classe avrà i seguenti attributi: un puntatore _pdata a un array di oggetti di tipo T
e la dimensione _dim dell’array, cioè il numero di oggetti di cui l’array si compone (un numero intero).*/
template <typename T>
class Array
{
public:
    Array();
    Array(int n);
    Array(Array &a);
    ~Array();

    int get_dim() const;
    T *get_value(int index) const;
    T *get_array() const;

    int set_size(int n);
    int set_value(int index, T &data);
    int set_array(T data[],int n);

    Array<T>& operator=(const Array<T> &a);

    void print()const;
    void read()const;


private:
    T *_pdata;
    int _dim;
};

/*Il template di classe dovrà inoltre fornire i seguenti metodi:
 */

// • Il costruttore di default che inizializzi _pdata a NULL e _dim a zero.
template <typename T>
Array<T>::Array()
{
    _pdata = nullptr;
    _dim = 0;
}
/*• Un costruttore con parametri che riceva in ingresso (ovvero come parametro) un numero intero n e
operi come segue: verifichi che n sia un numero positivo e, in tal caso, allochi dinamicamente un
array di n oggetti di tipo T, ne assegni il puntatore a _pdata e assegni a _dim il valore n. Nel caso in
cui n sia negativo o nullo, il costruttore inizializzerà _pdata a NULL e _dim a zero.*/
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
        _pdata = nullptr;
        _dim = 0;
    }
}

// • Il costruttore di copia.
template <typename T>
Array<T>::Array(Array &a)
{
    if ((a._dim < 0) || (a._pdata == nullptr))
    {
        _dim = 0;
        _pdata = nullptr;
    }
    else
    {
        _dim = a._dim;
        _pdata = new T[_dim];
        for (int i = 0; i < _dim; i++)
        {
            _pdata[i] = a._pdata[i];
        }
    }
}

// • Il distruttore.*/
template <typename T>
Array<T>::~Array()
{
    delete[] _pdata;
}

// • Il selettore get_size che restituisca la dimensione _dim dell’array (un numero intero).
template <typename T>
int Array<T>::get_dim() const
{
    return _dim;
}

/*• Il selettore get_value che riceva come parametro un numero intero index e, dopo aver verificato che
index sia compreso tra 0 e _dim – 1, restituisca come valore di ritorno il puntatore all’elemento
dell’array di indice index (un puntatore a costante di tipo T). Nel caso in cui il valore di index non sia
valido o il puntatore _pdata sia nullo, il selettore restituisce NULL.*/
template <typename T>
T *Array<T>::get_value(int index) const
{
    if ((index < 0) || (index > index - 1) || _pdata == nullptr)
    {
        return nullptr;
    }
    return &_pdata[index];
}

/*Il selettore get_array che restituisca come valore di ritorno il puntatore al primo elemento dell’array
(un puntatore a costante di tipo T).*/
template <typename T>
T *Array<T>::get_array() const
{
    return &_pdata[0];
}

/*• Il modificatore set_size che riceva come parametro un numero intero n, restituisca come valore di
ritorno un numero intero e modifichi l’array in modo tale che esso contenga n elementi. Il
modificatore potrà utilizzare la tecnica di riallocazione già incontrata nelle precedenti esercitazioni.
In particolare, il metodo allocherà un nuovo array di dimensione n, vi copierà gli elementi contenuti
nell’array puntato da _pdata (nel caso in cui la nuova dimensione n sia più piccola della precedente,
gli elementi eccedenti andranno perduti), deallocherà l’array puntato da _pdata e assegnerà a
_pdata il puntatore al nuovo array. Al termine della riallocazione, il modificatore assegnerà a _dim la
nuova dimensione n. Nel caso in cui il valore di n non sia valido o la riallocazione non vada a buon
fine, il metodo non modifica l’array e restituisce 0, altrimenti restituisce 1.*/
template <typename T>
int Array<T>::set_size(int n)
{
    if ((n < 0) || (_pdata == nullptr))
    {
        T _pdatanew = new T[n];
        for (int i = 0; i < n; i++)
        {
            _pdatanew[i] = _pdata[i];
        }
        delete[] _pdata;

        _pdata = _pdatanew;

        _dim = n;

        return 1;
    }

    return 0;
}

/*• Il modificatore set_value che riceva come parametro un numero intero index e un oggetto data di
tipo T e restituisca come valore di ritorno un numero intero. Dopo aver verificato che index sia
compreso tra 0 e _dim – 1, il modificatore assegna l’oggetto T all’elemento dell’array di indice index.
Nel caso in cui il valore di index non sia valido o il puntatore _pdata sia nullo, il modificatore
restituisce 0, altrimenti restituisce 1*/
template <typename T>
int Array<T>::set_value(int index, T &data)
{
    if ((index < 0) || (_pdata == nullptr))
    {
        return 0;
    }

    _pdata[index] = data;

    return 1;
}

/*Il modificatore set_array che riceva come parametro un array data di oggetti tipo T e la sua dimensione
n e restituisca come valore di ritorno un numero intero. Dopo aver verificato che n sia pari alla
dimensione _dim dell’array puntato da _pdata, il modificatore copia gli elementi dell’array data negli
elementi dell’array puntato da _pdata. Nel caso in cui il valore di n non sia valido o il puntatore _pdata
sia nullo, il modificatore restituisce 0, altrimenti restituisce 1.*/
template <typename T>
int Array<T>::set_array(T data[],int n){

    if(n==_dim){
        return 0; 
    }

    for(int i =0 ; i<n;i++){
        _pdata[i]=data[i];
    }

    return 1;

}

/*• L’operatore di assegnamento.*/
template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &a){
    if(this != &a){  // controllo autoassegnamento
        if(_pdata != nullptr){
            delete[] _pdata;
            _pdata = nullptr;
        }

        if(a._dim > 0){
            _dim = a._dim;
            _pdata = new T[_dim];

            for(int i = 0; i < _dim; i++){
                _pdata[i] = a._pdata[i];
            }
        } else {
            _dim = 0;
            _pdata = nullptr;
        }
    }
    return *this;
}

/*• Il metodo print che scandisca l’array puntato da _pdata e ne stampi a video gli elementi.*/
template <typename T>
void Array<T>::print()const {
    for(int i =0 ; i<_dim;i++){
        cout<<_pdata[i];
    }
}

/*• Il metodo read che acquisisca da tastiera i valori degli elementi contenuti nell’array puntato da _pdata.*/
template <typename T>
void Array<T>::read()const{
    cout<<"inserisci i valori:"<<endl;
    for(int i = 0;i<_dim;i++){
        cin>>_pdata[i];
    }
}

/*Si scriva quindi un programma C++ per verificare il corretto funzionamento del template di classe.
Il programma dichiarerà un oggetto a di tipo array, istanziandone il tipo generico con il tipo int e utilizzando
il primo costruttore con parametri passando la dimensione n = 10, chiederà all’utente di inserire da tastiera
gli elementi dell’array a utilizzando il metodo read, stamperà quindi l’intero array utilizzando il metodo print,
infine scandirà l’array calcolando e stampando a video la somma dei valori in esso contenuti.*/
int main()
{

    int n=10;
    Array<int> a(n);

    a.read();
    a.print();
    
    return 0;
}