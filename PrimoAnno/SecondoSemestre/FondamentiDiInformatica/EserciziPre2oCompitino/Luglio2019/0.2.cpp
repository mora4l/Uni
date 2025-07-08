/*Si implementino, inoltre, i seguenti metodi: */
#include <iostream>
#include <cmath>
using namespace std;

/*Per gestire calcoli con polinomi di una sola variabile a coefficienti interi e reali, si sviluppi in C++ il template di classe 
Polinomio avente i seguenti attributi: il grado _n del polinomio (un numero intero), il puntatore _p a un array di _n + 1 
oggetti di tipo T che rappresentano i coefficienti dei termini del polinomio. */
template <typename T>
class Polinomio{

    public:

    Polinomio();
    Polinomio(int g,T c[]);
    Polinomio(Polinomio &p);
    ~Polinomio();

    int getN();
    T* getP() const;

    bool operator==(const Polinomio &p)const;
    Polinomio<T>& operator=(const Polinomio<T> &p);

    T calcola(T x);



    private:
    int _n;
    T *_p;
};

/*
/*- Il costruttore di default che inizializzi _n a zero e _p a NULL. */
template <typename T>
Polinomio<T>::Polinomio(){
    _n=0;
    _p=nullptr;
}

/*- Un costruttore con parametri che riceva in ingresso (ovvero come parametri) il grado g di un polinomio (un 
numero intero) e un array c  di g + 1 oggetti di tipo T. 
Il costruttore opera come segue: alloca un array di g  + 1 oggetti di tipo T e ne assegna il puntatore a _p, inizializza quindi _n con il valore di g e l’array puntato da _p 
copiando ciascun elemento dell’array c  nel corrispondente elemento dell’array puntato da _p. Se g assume un 
valore negativo o l’allocazione dinamica non ha successo, il costruttore inizializza _n a zero e _p a NULL. */
template <typename T>
Polinomio<T>::Polinomio(int g,T c[]){

   _p=new T[g+1];
    _n=g;

    if((g<0)||(_p=nullptr)){
        _n=0;
        _p=nullptr;
    }

    for(int i=0 ; i<_n;i++){
        _p[i]=c[i];
    }
}

/*- Il costruttore di copia. */
template <typename T>
Polinomio<T>::Polinomio(Polinomio &p){
    if((p._p=nullptr)||(p._n<0)){
        _n=0;
        _p=nullptr;
        return ;
    }
    _n=p._n;

    _p=new T[_n+1];

    for(int i =0  ; i<_n;i++){
        _p[i]=p._p[i];
    }

}

/*- Il distruttore. */
template <typename T>
Polinomio<T>::~Polinomio(){
    delete [] _p;
}

//- I selettori (un metodo per ciascun attributo). 
template <typename T>
int Polinomio<T>::getN(){
    return _n;
}
template <typename T>
T* Polinomio<T>::getP()const {
    return _p;
}

//- L’operatore == per il quale due polinomi sono uguali se hanno lo stesso grado e gli stessi coefficienti.
template <typename T>
bool Polinomio<T>::operator==(const Polinomio &p)const{

    int corretto=0;

        if(_n==p._n){
            return false;
        }

        for(int i=0;i<=_n;i++){
            if(_p[i]=! p._p[i]){
                return false;
            }
        }
    return true;
}
//- L’operatore di assegnamento.   
template <typename T>
Polinomio<T> &Polinomio<T>::operator=(const Polinomio<T> &p){

if(this!=&p){

    if(_p != nullptr){
        delete[] _p;
    }

    _n=p._n;

    _p=new T[_n+1];

    for(int i=0 ; i<_n;i++){
        _p[i]=p._p[i];
    }
}

return *this;

}

/*- Il metodo calcola che riceva in ingresso (ovvero come parametro) un oggetto x di tipo T, calcoli e restituisca come 
valore di ritorno il valore y (un oggetto di tipo T) dato da: y = an xn + an-1 xn-1 + ... + a2 x2 + a1 x + a0, essendo gli ai 
i coefficienti dei termini del polinomio. Nota: per le potenze si può usare la funzione pow disponibile in cmath.  */
template <typename T>
T Polinomio<T>::calcola(T x){
    T ris;

    for(int i =0 ; i<x._n;i++){
        ris+=_p[i]*pow(x,i);
    }
    return ris;
}

/*Si sviluppi quindi la funzione main che operi come segue: 



passando un valore di x inserito dall’utente e stampi a video il risultato; assegni l’oggetto pol all’oggetto prev_pol*/
int main(){


    /*- Dichiari un array coeff di tre numeri reali e inizializzi tutti i suoli elementi a zero. 
- Dichiari un oggetto prev_pol di tipo Polinomio, istanziato con il tipo concreto double, utilizzando il costruttore 
con parametri al quale viene passato l’array coeff.  */
    int n = 3 ;
    double coeff[n]={0};



    Polinomio<double> prev_pol(n,coeff);

    int scelta=0;
    /*- Finché l’utente lo desidera operi come segue: chieda all’utente di inserire da tastiera i tre coefficienti (tre numeri 
reali) di un polinomio di secondo grado e li copi nei corrispondenti elementi dell’array coeff; */
    do{
        cout<<"inserisci i valori dei coefficienti"<<endl;
        for(int i =0 ; i<n;i++){
            cin>>coeff[i];
        }

/*crei un oggetto pol di tipo Polinomio, istanziato con il tipo concreto double, utilizzando il costruttore con parametri al quale è passato 
l’array coeff;*/
        Polinomio<double> pol(n,coeff);

/* verifichi se il polinomio appena inserito dall’utente è uguale al polinomio rappresentato dall’oggetto 
prev_pol e in caso affermativo stampi a video un messaggio per l’utente; */
if(prev_pol==pol){
    cout<<"gli oggetti sono uguali"<<endl;
}else{
    cout<<"gli oggetti non sono uguali"<<endl;
}

double x=0;
cout<<"inserisci x"<<endl;
cin>>x;
//invochi su pol il metodo calcola passando un valore di x inserito dall’utente e stampi a video il risultato; assegni l’oggetto pol all’oggetto prev_pol
double risultato=pol.calcola(x);
cout<<"il risultato è:"<<risultato<<endl;
prev_pol=pol;

        cout<<"premi [0] per uscire o [1] per continuare"<<endl;
        cin>>scelta;
    }while(scelta==1);


    return 0 ;
}