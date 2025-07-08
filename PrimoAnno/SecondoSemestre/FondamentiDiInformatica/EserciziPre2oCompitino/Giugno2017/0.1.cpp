/*
Allo scopo di sviluppare un software per la geometria analitica si realizzi in linguaggio C++ il template di classe Retta, 
parametrizzata sul tipo T ed avente per attributi il coefficiente angolare _m e l’intercetta _q (entrambi di tipo T) di una 
retta sul piano cartesiano, secondo l’equazione y = mx + q. Si implementino, inoltre, i seguenti metodi: 
*/
#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class Retta{

    public:

    Retta();
    Retta(T m, T q);
    Retta(Retta &r);
    ~Retta();

    T get_m();
    T get_q();

    void set_m(T m);
    void set_q(T q);

    void InserisciDati();
    void Stampa_dati();
    double calcolaDistanza(T xp,T yp);

    private:

    T _m;
    T _q;
};

/*o Il costruttore di default che inizializzi il valore di _m e di _q a zero, utilizzando la lista di inizializzazione.  */
template <typename T>
Retta<T>::Retta(): _m(0),_q(0) {};

/*
o Il  costruttore  con  parametri  che  riceva  come  parametri  il  valore  del  coefficiente  angolare  m  e dell’intercetta q 
(entrambi di tipo T) ed inizializzi i corrispondenti attributi della classe usando la lista di inizializzazione.
*/
template <typename T>
Retta<T>::Retta(T m,T q):_m(m),_q(q){}

/*
o Il costruttore di copia.  
*/
template <typename T>
Retta<T>::Retta(Retta &r){
    _m=r._m;
    _q=r._q;
}

/*
o Il distruttore. 
*/
template <typename T>
Retta<T>::~Retta(){}

/*o I selettori (un metodo per ciascun attributo). getter */
template <typename T>
T Retta<T>::get_m(){
    return _m;
}

template <typename T>
T Retta<T>::get_q(){
    return _q;
}

/*
o I modificatori (un metodo per ciascun attributo). */

template <typename T>
void Retta<T>::set_m(T m){
    _m=m;
}

template <typename T>
void Retta<T>::set_q(T q){
    _q=q;
}

/*Il metodo inserisciDati per leggere da tastiera i valori del coefficiente angolare _m e dell’intercetta _q. Il metodo 
non restituisce alcun valore di ritorno. */
template <typename T>
void Retta<T>::InserisciDati(){
    cout<<"inserisci il coefficiente angolare:"<<endl;
    cin>>_m;
    cout<<"inserisci l'intercetta:"<<endl;
    cin>>_q;
}

/*o Il metodo stampaDati che stampi a video l’equazione della retta secondo il seguente formato: 
 r: y = mx + q; 
dove a m viene sostituito il valore corrente di  _m e a q il valore corrente di _q. Il metodo non restituisce alcun 
valore di ritorno. */
template <typename T>
void Retta<T>::Stampa_dati(){
    cout<<"la retta ha forma: y="<<_m<<"x+"<<_q<<endl;
}

/*
o Il metodo calcolaDistanza che riceva come parametri le coordinate (xP, yP) di un punto P (due valori di tipo T), 
calcoli e restituisca come valore di ritorno la distanza d di P dalla retta (un numero reale), calcolata come: 
 
𝑑 = |𝑦𝑃 −(𝑚𝑥𝑝 +𝑞)|
√1+𝑚2  

*/

template <typename T>
double Retta<T>::calcolaDistanza(T xp, T yp){
double dist=(yp-(_m+_q))/sqrt(1+pow(_m,2));
return dist;
}


/*Si sviluppi, infine, la funzione main che operi nel modo seguente: 
1. Dopo aver chiesto all’utente di inserire da tastiera un numero intero n  e  avere  verificato  che  n  sia  positivo, 
allochi dinamicamente un array R di  n oggetti di classe Retta, assegnando il tipo double al parametro T. Nel 
caso in cui n sia negativo, main terminerà stampando a video un messaggio di errore. 

2. Scandisca l’array R e assegni i valori di _m e _q a ciascun elemento di R, chiamando il metodo inserisciDati. 
3. Chieda  all’utente  di  inserire  le  coordinate  (xQ,  yQ)  di  un  punto  Q  (due  numeri  reali),  scandisca l’array  R, 
invochi su ciascun elemento dell’array R la funzione calcolaDistanza e ne stampi a video il valore di ritorno 
(ovvero la distanza del punto Q da ciascuna delle rette contenute nell’array R). 
4. Deallochi l’array R e termini*/
int main(){

    int n=0 ; 
    cout<<"inserisci n"<<endl;
    cin>>n;
    if(n>0){
        Retta<double> *R=new Retta<double>[n];

        for(int i =0 ; i<n;i++)
        R->InserisciDati();

        double x=0,y=0;
        cout<<"inserisci i valori di una coordinata x y"<<endl;
        cin>>x>>y;

        double ris=0;
        ris=R->calcolaDistanza(x,y);

        cout<<"distanza:"<<ris<<endl;


    }else{
        cout<<"errore"<<endl;
    }
    return 0 ;
}