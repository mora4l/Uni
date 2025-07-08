/*Si implementino, inoltre, i seguenti metodi: 
- Il costruttore di default che inizializzi _n a zero e i puntatori _pVal e _pMask a NULL. 

- Il costruttore di copia. 
- Il distruttore. 
- Un selettore per ciascuno dei tre attributi. 
- L’operatore di assegnamento. 
*/
#include <iostream>
using namespace std;

/*Per eseguire operazioni su un sottoinsieme di elementi di un array, si sviluppi in C++ la classe ArrayOperations 
avente i seguenti attributi: il puntatore _pVal a un array di numeri reali sul quale si eseguiranno le operazioni, la sua 
dimensione _n (un numero intero), il puntatore _pMask a un array di numeri interi di dimensione _n. 
Gli elementi dell’array puntato da _pMask possono assumere soltanto il valore 0 oppure 1. Per ciascun elemento dell’array 
puntato da _pMask di valore 1, il corrispondente elemento dell’array puntato da _pVal verrà considerato nel calcolo 
dell’operazione. Ad esempio, nel caso in cui l’operazione consista nella somma degli elementi dell’array, verranno 
sommati tra loro solo quegli elementi dell’array puntato da _pVal per i quali il corrispondente elemento dell’array 
puntato da _pMask vale 1. */
class arrayoperations{

    public:
    arrayoperations();
    arrayoperations(const double v[],const int m[],const int dim);
    arrayoperations(const arrayoperations &a);
    ~arrayoperations();

    double* get_pval()const;
    int* get_pmask()const;
    int get_n()const;

    arrayoperations& operator=(const arrayoperations &a);
    double calcola(double(*pf)( double[], int[], int _n));


    private:

    double *_pval;
    int *_pmask;
    int _n;
};

arrayoperations::arrayoperations(){
    _n=0;
    _pval=nullptr;
    _pmask=nullptr;
}

/*- Un costruttore con parametri che riceva un array v di numeri reali, un array m di numeri interi e la loro 
dimensione dim (un numero intero). Il costruttore opererà come segue: effettuerà l’allocazione dinamica di un 
array di dim numeri reali e ne assegnerà il puntatore a _pVal; effettuerà l’allocazione dinamica di un array di 
dim numeri interi e ne assegnerà il puntatore a _pMask; se l’allocazione dinamica della memoria va a buon fine 
in entrambi i casi, copierà i valori contenuti in v nell’array puntato da _pVal,  copierà i valori contenuti in m 
nell’array puntato da _pMask e assegnerà dim a _n; nel caso in cui l’allocazione dinamica della memoria non 
vada a buon fine, il costruttore inizializzerà _pVal a NULL, _pMask a NULL e _n a zero. */
arrayoperations::arrayoperations(const double v[],const int m[],const int dim){
    _pval=new double [dim];
    _pmask=new int[dim];

    if((_pval!=nullptr)&&(_pmask!=nullptr)){
        for(int i =0 ; i<dim;i++){
            _pval[i]=v[i];
            _pmask[i]=m[i];

        }

    }else{
        _pval=nullptr;
        _pmask=nullptr;
        _n=0;
    }
}

arrayoperations::arrayoperations(const arrayoperations &a){
    _n=a._n;
    double *_pval=new double[_n];
    int *_pmask=new int[_n];

    for(int i =0 ; i<_n;i++){
        _pmask[i]=a._pmask[i];
        _pval[i]=a._pval[i];
    }


}

arrayoperations::~arrayoperations(){
    delete[] _pmask;
    delete[] _pval;
}

int arrayoperations::get_n()const{
    return _n;
}

double* arrayoperations::get_pval()const{
    return _pval;
}

int *arrayoperations::get_pmask()const{
    return _pmask;
}

arrayoperations& arrayoperations::operator=(const arrayoperations &a){
    if(this!= &a){

        delete[] _pval;
        delete[] _pmask;

        if((a._pmask!=nullptr)&&(a._pval!=nullptr)&&(a._n>0)){
            _n=a._n;
            _pval=new double [_n];
            _pmask=new int [_n];

            for(int i = 0 ;i<_n;i++){
                _pval[i]=a._pval[i];
                _pmask[i]=a._pmask[i];
            }

        }else{
            _pval=nullptr;
            _pmask=nullptr;
            _n=0;
        }
    }

    return *this;
}

/*- Il metodo calcola che riceva come parametro il puntatore pf a una funzione che riceva come parametri un array 
di numeri reali, un array di numeri interi e la loro dimensione (un numero intero) e restituisca come valore di 
ritorno  un  numero  reale.  Il  metodo  chiamerà  la  funzione  il  cui  puntatore  pf  è  passato  come  parametro, 
passandole gli array puntati da _pVal e _pMask e la loro dimensione _n e restituirà il valore di ritorno restituito 
dalla funzione (un numero reale). Nel caso in cui _pVal o _pMask valgano NULL, il metodo ritornerà -1.*/

double arrayoperations::calcola(double(*pf)( double[], int[], int _n)){

    double res=0;
    
    if((_pval==nullptr)||(_pmask==nullptr)){
        res=-1;
    }else{
        res= (*pf)(_pval,_pmask,  _n);

    }
    return res;
}

int main(){

    return 0 ; 
}