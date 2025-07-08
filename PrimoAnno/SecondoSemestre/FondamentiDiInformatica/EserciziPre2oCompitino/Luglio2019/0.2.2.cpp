/*Per gestire calcoli con polinomi di una sola variabile a coefficienti interi e reali, si sviluppi in C++ il template di classe
Polinomio avente i seguenti attributi: il grado _n del polinomio (un numero intero), il puntatore _p a un array di _n + 1
oggetti di tipo T che rappresentano i coefficienti dei termini del polinomio. Si implementino, inoltre, i seguenti metodi:
- Il costruttore di default che inizializzi _n a zero e _p a NULL.
- Un costruttore con parametri che riceva in ingresso (ovvero come parametri) il grado g di un polinomio (un
numero intero) e un array c  di g + 1 oggetti di tipo T. Il costruttore opera come segue: alloca un array di g  + 1
oggetti di tipo T e ne assegna il puntatore a _p, inizializza quindi _n con il valore di g e l’array puntato da _p
copiando ciascun elemento dell’array c  nel corrispondente elemento dell’array puntato da _p. Se g assume un
valore negativo o l’allocazione dinamica non ha successo, il costruttore inizializza _n a zero e _p a NULL.
- Il costruttore di copia.
- Il distruttore.
- I selettori (un metodo per ciascun attributo).
- L’operatore == per il quale due polinomi sono uguali se hanno lo stesso grado e gli stessi coefficienti.
- L’operatore di assegnamento.


*/
#include <iostream>
#include <cmath>
using namespace std;
template <typename T>
class Polinomio
{

public:
    Polinomio();
    Polinomio(int g, T c[]);
    Polinomio(const Polinomio &p);
    ~Polinomio();

    int get_n() const;
    T *get_p() const;

    bool operator==(const Polinomio &p) const;
    const Polinomio& operator=(const Polinomio &p);
    T calcola(T x);

private:
    int _n;
    T *_p;
};

template <typename T>
Polinomio<T>::Polinomio()
{
    _n = 0;
    _p = nullptr;
}

template <typename T>
Polinomio<T>::Polinomio(int g, T c[])
{
    _n = g;
    _p = new T[g + 1];
    if (g < 0 || _p == nullptr)
    {
        _n = 0;
        _p = nullptr;
    }
    else
    {

        for (int i = 0; i <= g; i++)
        {
            _p[i] = c[i];
        }
    }
}

template <typename T>
Polinomio<T>::Polinomio(const Polinomio &p)
{
    _n = p._n;
    T *_p = new T[_n + 1];
    for (int i = 0; i <= _n; i++)
    {
        _p[i] = p._p[i];
    }
}
template <typename T>
Polinomio<T>::~Polinomio()
{
    delete[] _p;
}
template <typename T>
int Polinomio<T>::get_n() const
{
    return _n;
}
template <typename T>
T *Polinomio<T>::get_p() const
{
    return _p;
}
template <typename T>
bool Polinomio<T>::operator==(const Polinomio &p) const
{
if(_n!=p._n){
    return true ; 
}
    for (int i = 0; i <= _n; i++)
    {
        if(_p[i] != p._p[i]){
            cout<<_p[i]<<" è diverso da "<<p._p[i]<<endl;
            return false ; 
        }
    }

    return true ; 

}

template <typename T>
const Polinomio<T>& Polinomio<T>::operator=(const Polinomio &p){
    if(this!=&p){
        if((p._n>0)&&(p._p!=nullptr)){
            delete [] _p;
            _n=p._n;
            _p=new T [_n+1];
    for (int i = 0; i <= _n; i++)
    {
        _p[i] = p._p[i];
    }
        }else{
        _p=nullptr;
        _n=0;
    }
    }
    return *this;
}

/*- Il metodo calcola che riceva in ingresso (ovvero come parametro) un oggetto x di tipo T, calcoli e restituisca come
valore di ritorno il valore y (un oggetto di tipo T) dato da: y = an xn + an-1 xn-1 + ... + a2 x2 + a1 x + a0, essendo gli ai
i coefficienti dei termini del polinomio. Nota: per le potenze si può usare la funzione pow disponibile in cmath.*/
template <typename T>
    T Polinomio<T>::calcola(T x){
        T y =T(); 
        for (int i =0  ;i<_n+1;i++){
            y+=_p[i]*pow(x,i);
        }

        return y;
    }


/*Si sviluppi quindi la funzione main che operi come segue:
- Dichiari un array coeff di tre numeri reali e inizializzi tutti i suoli elementi a zero.
- Dichiari un oggetto prev_pol di tipo Polinomio, istanziato con il tipo concreto double, utilizzando il costruttore
con parametri al quale viene passato l’array coeff.
- Finché l’utente lo desidera operi come segue: chieda all’utente di inserire da tastiera i tre coefficienti (tre numeri
reali) di un polinomio di secondo grado e li copi nei corrispondenti elementi dell’array coeff; crei un oggetto pol di
tipo Polinomio, istanziato con il tipo concreto double, utilizzando il costruttore con parametri al quale è passato
l’array coeff; verifichi se il polinomio appena inserito dall’utente è uguale al polinomio rappresentato dall’oggetto
prev_pol e in caso affermativo stampi a video un messaggio per l’utente; invochi su pol il metodo calcola
passando un valore di x inserito dall’utente e stampi a video il risultato; assegni l’oggetto pol all’oggetto prev_pol.*/
    int main()
{
    int dim=3;
    double coeff[dim]={0};
    Polinomio<double> prev_pol( dim ,  coeff);
    int continua=0;
    do{

        cout<<"inserisci i 3 coefficienti"<<endl;
        for(int i =0 ; i<dim;i++){
            cin>>coeff[i];
        }
        Polinomio<double> pol(dim,coeff);

        if(pol==prev_pol){
            cout<<"sono uguali gli array"<<endl;
            double d=0 ; 
            cout<<"inserisci un valore "<<endl;
            cin>>d;
            cout<<pol.calcola(d);

            prev_pol=pol;
            
        }else{
            cout<<"Gli array non sono uguali"<<endl;
        }

        cout<<"vuoi continuare ? si[1] no[0]"<<endl;
        cin>>continua;
    }while(continua==1);


    return 0;
}