/*
Allo scopo di contribuire allo sviluppo del sistema informatico di un istituto bancario, si sviluppi in linguaggio C++ la 



*/
#include <iostream>
#include <fstream>
using namespace std; 

/*
classe ContoCorrente avente i seguenti attributi: il numero del conto corrente (un numero intero), il codice CAB della 
filiale presso la quale ha sede il conto (un numero intero), un codice identificativo dell’intestatario (un numero intero) 
e il saldo in Euro del conto corrente (un numero reale). 
*/
class Contocorrente{

    public:

    Contocorrente();
    Contocorrente(int numeroconto,int CAB,int codiceidentificativo,double saldo);
    ~Contocorrente();

    int getNumeroConto();
    int getCAB();
    int getCodiceIdentificativo();
    double getSaldo();

    void setNumeroConto(int numeroconto);
    void setCAB(int CAB);
    void setCodiceIdentificativo(int codiceidentificativo);
    void setSaldo(double saldo);

    friend istream &operator>>(std::istream &in,Contocorrente &c);
    friend ostream &operator<<(std::ostream &out, Contocorrente &c);

    private:

    int _numeroconto; 
    int _CAB;
    int _codiceIdentificativo;
    double _saldo;
};

/*
Si implementino, inoltre, i seguenti metodi: 

*/
/* -  Il costruttore di default che inizializzi a zero tutti gli attributi, usando la lista di inizializzazione. 
-  Un costruttore con parametri che riceva come parametri il valore del  numero di conto corrente, del codice CAB, 
del codice identificativo dell’intestatario e del saldo e  inizializzi  i  corrispondenti  attributi  della  classe  usando  la 
lista di inizializzazione. Per semplicità, si assuma che i valori ricevuti dai parametri siano sempre validi.  */

Contocorrente::Contocorrente():_numeroconto(0),_CAB(0),_codiceIdentificativo(0),_saldo(0){}

Contocorrente::Contocorrente(int numeroconto,int CAB,int codiceidentificativo,double saldo):_numeroconto(numeroconto),_CAB(CAB),_codiceIdentificativo(codiceidentificativo),_saldo(saldo){}

/*- Il distruttore*/
Contocorrente::~Contocorrente(){}

/* -  I selettori (un metodo per ciascun attributo).  (getter)*/
int Contocorrente::getNumeroConto(){
    return _numeroconto;
}
int Contocorrente::getCAB(){
    return _CAB;
}
int Contocorrente::getCodiceIdentificativo(){
    return _codiceIdentificativo;
}
double Contocorrente::getSaldo(){
    return _saldo;
}

/*
-  I  modificatori (un metodo per ciascun  attributo).  Per semplicità, si assuma  che i valori ricevuti dai parametri dei 
modificatori siano sempre validi. 
*/
void Contocorrente::setNumeroConto(int numeroconto){
    _numeroconto=numeroconto;
}
void Contocorrente::setCAB(int CAB){
    _CAB=CAB;
}
void Contocorrente::setCodiceIdentificativo(int codiceidentificativo){
    _codiceIdentificativo=codiceidentificativo;
}
void Contocorrente::setSaldo(double saldo){
    _saldo=saldo;
}

/*
-  Gli operatori di inserimento e di estrazione. 
*/
std::istream &operator>>(std::istream &in,Contocorrente &c){

    in>>c._numeroconto;

    in>>c._CAB;

    in>>c._codiceIdentificativo;

    in>>c._saldo;

    return in;
}

std::ostream &operator<<(std::ostream &out, Contocorrente &c){
out<<"Dati del conto corrente:"<<endl;
out<<"Numero conto corrente:"<<c._numeroconto<<endl;
out<<"CAB:"<<c._CAB<<endl;
out<<"odice identificativo:"<<c._codiceIdentificativo<<endl;
out<<"Saldo:"<<c._saldo<<endl;

return out;
}

/*
Si sviluppi quindi la funzione main che operi come segue: 
*/

int main(){

    /*
    -  Apra in lettura il file Conti.txt. Tale file contiene nella sua prima riga il numero di righe n di cui il file si compone 
e  nelle  righe  successive,  per  ciascuna  di  esse,  le  informazioni  relative  ad  un  conto  corrente  nel  seguente  ordine: 
numero di conto corrente, codice CAB, identificativo dell’intestatario e saldo. 
    */

    fstream file;

    file.open("Conti.txt",ios::in);

    /*     -  Legga la prima riga del file Conti.txt e allochi dinamicamente un array cc di n oggetti di tipo ContoCorrente. 
    */
    int numerorighe=0;

    file>>numerorighe;
    
    Contocorrente *cc=new Contocorrente[numerorighe];

    int numeroconto=0,CAB=0,codiceidentificativo=0,saldo=0;

    


/*   -  Sfruttando l’operatore di estrazione, sopra definito per la classe ContoCorrente, legga le righe successive del file 
Conti.txt e assegni agli elementi dell’array cc le informazioni contenute in ciascuna riga del file. Per semplicità, si 
supponga che il file non sia vuoto e che i dati in esso contenuti siano validi.  */

for(int i=0 ; i<numerorighe;i++){
    file>>cc[i];
}

/* -  Scandisca l’array cc e stampi a video il numero di conti corrente il cui saldo è superiore a 50.000 Euro. 
 */

 for(int i =0 ; i<numerorighe;i++){
    if(cc[i].getSaldo()>50000){
        cout<<cc[i];
    }
 }

 /*
 -  Deallochi l’array cc, chiuda il file e termini.
 */

 delete[] cc;

file.close();

    return 0;
}