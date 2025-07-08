/*
Allo scopo di rappresentare le matrici diagonali n × n in un software per il calcolo scientifico, si realizzi in linguaggio 
C++ 
Si implementino, inoltre, i seguenti metodi:  
*/
#include <iostream>
using namespace std;

template <typename T>
/*template di classe MatDiag, parametrizzato sul tipo T e avente per attributi la dimensione _n della matrice (un 
numero intero) e un puntatore _p a un array di _n valori di tipo T, che rappresentano gli elementi sulla diagonale della 
matrice (gli altri elementi non si rappresentano, avendo valore pari a 0). */
class MatDiag{

    public:

    MatDiag();
    MatDiag(int n , T D[]);
    MatDiag(MatDiag &m);
    ~MatDiag();

    T* get_p()const;
    int get_n()const;

    void set_p(const T D[]);

     MatDiag<T> operator*(T val);
     MatDiag<T> &operator=(const MatDiag &m);

     void stampa();
    private:

    int _n;
    T *_p;


};
//o Il costruttore di default che inizializzi il valore di _n a zero e il valore di _p a NULL.  
template <typename T>
MatDiag<T>::MatDiag(){
    _n=0;
    _p=nullptr;
}

/*o Il  costruttore  con  parametri  che  riceva come  parametri  la  dimensione  n  della  matrice (un numero intero)  ed un 
array D di n elementi di tipo T, allochi dinamicamente l’array puntato da _p e vi copi gli elementi di D. */
template <typename T>

MatDiag<T>::MatDiag(int n, T D[]){

    _n=n;
        _p=new T[n];

        for(int i =0 ; i<n;i++){
            _p[i]=D[i];
        }

        
}

/*o Il  costruttore  di  copia  che  allochi  dinamicamente  l’array  puntato  da  _p,  copiando  la  dimensione  dell’array  e 
l’array stesso dall’oggetto passato come parametro.  */
template <typename T>

MatDiag<T>::MatDiag(MatDiag &m):_n(m._n){

    T *_p=new T[m._n];

    for(int i =0 ;i<m._n;i++){
        _p[i]=m._p[i];
    }

}

/*o Il distruttore. */
template <typename T>

MatDiag<T>::~MatDiag(){
    delete [] _p;
}

/*o I selettori (un metodo per ciascun attributo). getter*/
template <typename T>
T* MatDiag<T>::get_p()const{
return _p;
}
template <typename T>
int MatDiag<T>::get_n()const{
    return _n;
}

/*o Il  modificatore  per l’array  puntato  da  _p.  Il  modificatore  riceverà  come  parametro  un  array  contenente  i  nuovi 
valori. Per semplicità, si supponga che l’array puntato da _p sia già stato correttamente allocato delle dimensioni 
volute e che l’array passato come parametro al modificatore abbia le dimensioni corrette. */
template <typename T>
void MatDiag<T>::set_p(const T D[]){

for(int i=0 ; i<_n;i++){
    _p[i]=D[i];
}
}

/*o L’operatore  *  che  riceva  come  parametro  un  valore  di  tipo  T  e  moltiplichi  ciascun  elemento  della  matrice 
diagonale per tale valore. L’operatore restituirà come valore di ritorno un riferimento a MatDiag. */
template <typename T>
 MatDiag<T> MatDiag<T>::operator*(T val){


    for(int i =0 ;i<_n;i++){
        
        _p[i]*=val;
    }

    return *this;
}

/*o L’operatore  di  assegnamento.  L’operatore  deallocherà  l’array  puntato  da  _p  e  lo  riallocherà  delle  dimensioni 
opportune, copiandolo dall’oggetto passato come parametro. */
template <typename T>
MatDiag<T> &MatDiag<T>::operator=(const MatDiag &m){
    if(this!=&m){
        delete[] _p;
        _n=m._n;
        _p=new T[m._n];

        for(int i=0;i<m._n;i++){
            _p[i]=m._p[i];
        }
    }

    return *this;

}

/*o Il metodo stampa che stampi a video l’intera matrice diagonale (compresi gli zeri al di fuori della diagonale). */
template <typename T>
void MatDiag<T>::stampa(){

    for(int j=0;j<_n;j++){
        for(int i=0;i<_n;i++){
            if(i==j){

                cout<<_p[i];
            }else{
                cout<<"0";
            }
    }
        cout<<endl;
    }
}

/*Si sviluppi, infine, la funzione main che operi nel modo seguente: 
*/
int main(){

    //1. Dichiari un array v di 5 numeri reali e chieda all’utente di inserirne da tastiera gli elementi. 

    int n =5;
    double v[n];

    cout<<"inserisci valori dell'array:"<<endl;
    
    for(int i=0 ; i<n;i++){
        cin>>v[i];
    }

    /*2. Utilizzando il costruttore con parametri, dichiari un oggetto M di classe MatDiag, assegnando il tipo double al 
parametro  T.  L’oggetto  M  verrà  inizializzato  passando  al  costruttore  con  parametri  della  classe  MatDiag 
l’array v e la sua dimensione (pari a 5). */

    MatDiag<double> M(n,v);

    //3. Dichiari un oggetto P di classe MatDiag, assegnando il tipo double al parametro T e assegni M a P. 

    MatDiag<double> P;
    P.operator=(M);

    //4. Chieda all’utente di inserire da tastiera un numero reale a e, utilizzando l’operatore *, moltiplichi P per a.  

    cout<<"inserisci un numero reale:"<<endl;
    double real=0;
    cin>>real;
    P.operator*(real);

    //5. Chiamando il metodo stampa della classe MatDiag, stampi le matrici diagonali M e P e termini.*/

        M.stampa();
        cout<<endl;
        P.stampa();

    return 0;
}