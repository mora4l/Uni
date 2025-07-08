/*
Esercizio 5 
*/

#include <iostream>
using namespace std; 

/*
1. Per eseguire operazioni su un sottoinsieme di elementi di un array, si sviluppi in C++ la classe ArrayOperations 
avente i seguenti attributi: 
Gli elementi  dell’array puntato da _pMask possono assumere soltanto il valore 0 oppure 1. 
Per ciascun elemento dell’array  puntato da _pMask di valore 1, il corrispondente elemento dell’array puntato da _pVal verrà considerato nel calcolo 
dell’operazione. Ad esempio, nel caso in cui l’operazione consista nella somma degli elementi dell’array, verranno 
sommati tra loro solo quegli elementi dell’array puntato da _pVal per i quali il corrispondente elemento dell’array 
puntato da _pMask vale 1. Si implementino, inoltre, i seguenti metodi: 
*/

class ArrayOperations{

    public:

    ArrayOperations();
    ArrayOperations(double v[],int m[],int dim);
    ArrayOperations(ArrayOperations &a);

    ~ArrayOperations();

    int* get_pMask() const;
    double *  get_pVal() const;
    int get_n() const;

    const ArrayOperations &operator=(const ArrayOperations &a);

    int Calcola(double (*pf)(double[],int[],int n));

    

    private:

    int _n; //la sua dimensione _n (un numero intero)
    double *_pVal; //il puntatore _pVal a un array di numeri reali sul quale si eseguiranno le operazioni
    int *_pMask; //il puntatore _pMask a un array di numeri interi di dimensione _n. 

};

/*
- Il costruttore di default che inizializzi _n a zero e i puntatori _pVal e _pMask a NULL. 
*/
ArrayOperations::ArrayOperations(){
    _n=0;
    _pVal=nullptr;
    _pMask=nullptr;
}

/* - Un costruttore con parametri che riceva un array v di numeri reali, un array m di numeri interi e la loro 
dimensione dim (un numero intero). Il costruttore opererà come segue: ; ; se l’allocazione dinamica della memoria va a buon fine 
in entrambi i casi, copierà i valori contenuti in v nell’array puntato da _pVal,  copierà i valori contenuti in m 
nell’array puntato da _pMask e assegnerà dim a _n;   */

ArrayOperations::ArrayOperations(double v[],int m[],int dim){
    _pVal=new double[dim]; //effettuerà l’allocazione dinamica di un array di dim numeri reali e ne assegnerà il puntatore a _pVal

    _pMask=new int[dim]; //effettuerà l’allocazione dinamica di un array di dim numeri interi e ne assegnerà il puntatore a _pMask

    if((_pMask==nullptr)||(_pVal==nullptr)){ //nel caso in cui l’allocazione dinamica della memoria non vada a buon fine, il costruttore inizializzerà _pVal a NULL, _pMask a NULL e _n a zero.
        _n=0;
        _pVal=nullptr;
        _pMask=nullptr;
        return ; 
    }

    for(int i =0 ; i<dim;i++){
        _pVal[i]=v[i];
        _pMask[i]=m[i];
    }

    _n=dim;
}

//- Il costruttore di copia. 
ArrayOperations::ArrayOperations(ArrayOperations &a){
    _n=a._n;

    _pVal=new double[_n];
    _pMask=new int[_n];

    for(int i =0 ; i<_n;i++){
        _pVal[i]=a._pVal[i];
        _pMask[i]=a._pMask[i];
    }
}

//- Il distruttore. 
ArrayOperations::~ArrayOperations(){
    delete[] _pMask;
    delete[] _pVal;
}

//- Un selettore per ciascuno dei tre attributi. selettore (getter)
int *ArrayOperations::get_pMask() const{
    return _pMask;
}
double* ArrayOperations::get_pVal() const{
    return _pVal;
}
int ArrayOperations::get_n()const{
    return _n;
}

//operatore di assegnamento
const ArrayOperations &ArrayOperations::operator=(const ArrayOperations &a){
    if(this!=&a){
        delete[] _pVal;
        delete[] _pMask;
        _n=a._n;

        _pVal=new double[_n];
        _pMask=new int[_n];
        for(int i =0;i<a._n;i++){
            _pMask[i]=a._pMask[i];
            _pVal[i]=a._pVal[i];
        }
    }

    return *this;
}

/*
- Il metodo calcola che riceva come parametro il puntatore pf a una funzione che riceva come parametri un array 
di numeri reali, un array di numeri interi e la loro dimensione (un numero intero) e restituisca come valore di 
ritorno  un  numero  reale.  
Il  metodo  chiamerà  la  funzione  il  cui  puntatore  pf  è  passato  come  parametro,  
passandole gli array puntati da _pVal e _pMask e la loro dimensione _n e restituirà il valore di ritorno restituito 
dalla funzione (un numero reale). Nel caso in cui _pVal o _pMask valgano NULL, il metodo ritornerà -1.
*/

int ArrayOperations::Calcola(double (*pf)(double[],int[],int n)){

    double risultato=(*pf)(_pVal,_pMask,_n);

    if((_pMask==nullptr)||(_pVal==nullptr)){
        return -1;
    }

    return risultato;

}
/*
Si sviluppino, quindi, le seguenti funzioni in linguaggio C++: 
*/
/*
- La funzione somma che riceva come parametri un array v di numeri reali, un array m di numeri interi e la loro 
dimensione dim (un numero intero) e restituisca come valore di ritorno un numero reale. La funzione calcolerà 
la somma degli elementi di v per i quali il corrispondente elemento di m vale 1. 
*/
double somma(double v[],int m[],int dim){

    double somma=0;

    for(int i =0 ; i<dim;i++){
        if(m[i]==1){

            somma+=v[i];
        }
    }

    return somma;
}

/*
- La funzione media che riceva come parametri un array v di numeri reali, un array m di numeri interi e la loro 
dimensione dim (un numero intero) e restituisca come valore di ritorno un numero reale. La funzione calcolerà 
la media degli elementi di v per i quali il corrispondente elemento di m vale 1. 
*/

double media(double v[],int m[],int dim){

    double med=0,somma=0;
    int count=0;

    for(int i =0 ; i<dim;i++){
        if(m[i]==1){
            somma+=v[i];
            count ++;
        }
    }

    med=somma/count;

    return med;
}

/*
- La funzione main che operi come segue: dichiari un oggetto q di tipo ArrayOperations, utilizzando il costruttore 
con parametri cui vengano passati l’array di numeri reali x = {1.0, 2.0, 3.0}, l’array di numeri interi y = {1, 0, 1} 
e la loro dimensione dim = 3; chiami sull’oggetto q il metodo calcola della classe ArrayOperations passando 
come parametro per pf la funzione somma e stampi a video il risultato; chiami sull’oggetto q il metodo calcola 
della classe ArrayOperations passando come parametro per pf la funzione media e stampi a video il risultato. 
*/
int main(){

    
    int dim=3;
    double x[]= {1.0, 2.0, 3.0};
    int y[] = {1, 0, 1} ;
    
    ArrayOperations q(x,y,dim);

    int ris=q.Calcola(somma);

    cout<<"risultato:"<<ris<<endl;

    double ri=q.Calcola(media);

    cout<<"risultato:"<<ri<<endl;
    
    return 0; 
}
