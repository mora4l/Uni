
#include <iostream>
#include <fstream>
using namespace std;

/*Allo scopo di gestire il magazzino di un grande negozio di scarpe, si sviluppi in C++ la classe Scarpa avente i seguenti 
attributi: un codice identificativo della marca e del modello (un numero intero), il numero della scarpa (un numero 
intero), la quantità di scarpe presenti in magazzino (un numero intero) e il prezzo in Euro della scarpa (un numero 
reale). Si implementino, inoltre, i seguenti metodi: */

class Scarpa{
    
    public:

    Scarpa();
    Scarpa(int marca,int modello,int numero,int quantita,double prezzo);
    ~Scarpa();

    int get_marca();
    int get_modello();
    int get_numero();
    int get_quantita();
    double get_prezzo();

    void set_marca(int marca);
    void set_modello(int modello);
    void set_numero(int numero);
    void set_quantita(int quantita);
    void set_prezzo(double prezzo);

    bool operator<=(Scarpa &s)const ;
    Scarpa operator=(Scarpa &s);
    friend std::istream &operator>>(std::istream &in,Scarpa& s);
    friend std::ostream& operator<<(std::ostream& out, const Scarpa& s);

    private:

    int _marca;
    int _modello;
    int _numero;
    int _quantita;
    double _prezzo;

};
//- Il costruttore di default che inizializzi a zero tutti gli attributi, usando la lista di inizializzazione. 
Scarpa::Scarpa():_marca(0),_modello(0),_numero(0),_quantita(0),_prezzo(0){}

/*- Un costruttore con parametri che riceva come parametri i valori del codice identificativo di marca e modello, del 
numero della scarpa, della quantità di scarpe presenti in magazzino e del prezzo e inizializzi i corrispondenti 
attributi della classe usando la lista di inizializzazione. Si assuma che i valori dei parametri siano sempre validi. */
Scarpa::Scarpa(int marca,int modello,int numero,int quantita,double prezzo):_marca(marca),_modello(modello),_numero(numero),_quantita(quantita),_prezzo(prezzo){}

//- Il distruttore. 
Scarpa::~Scarpa(){}

//- I selettori (un metodo per ciascun attributo). (getter)
int Scarpa::get_marca(){
    return _marca;
}
int Scarpa::get_modello(){
    return _modello;
}
int Scarpa::get_numero(){
    return _numero;
}
int Scarpa::get_quantita(){
    return _quantita;
}
double Scarpa::get_prezzo(){
    return _prezzo;
}

/*- I modificatori (un metodo per ciascun attributo). Per semplicità, si assuma che i valori assegnati ai parametri dei 
modificatori siano sempre validi. */

void Scarpa::set_marca(int marca){
    _marca=marca;
}
void Scarpa::set_modello(int modello){
    _modello=modello;
}
void Scarpa::set_numero(int numero){
    _numero=numero;
}
void Scarpa::set_quantita(int quantita){
    _quantita=quantita;
}
void Scarpa::set_prezzo(double prezzo){
    _prezzo=prezzo;
}

/*- L’operatore <= per il quale una scarpa è minore o uguale di un’altra se il numero della scarpa è minore o uguale 
del numero dell’altra scarpa. */

bool Scarpa ::operator<=(Scarpa &s)const {
return this->_numero <= s._numero;
}

//operatore di assegnamento
Scarpa Scarpa::operator=(Scarpa &s){
    if(this!= &s){
        _marca=s._marca;
        _modello=s._modello;
        _numero=s._numero;
        _quantita=s._quantita;
        _prezzo=s._prezzo;
    }

    return *this;
}

/*- L’operatore di estrazione. */

std::istream &operator>>(std::istream &in, Scarpa &s) {
    in >> s._marca >> s._modello >> s._numero >> s._prezzo >> s._quantita;
    return in;
}
std::ostream& operator<<(std::ostream& out, const Scarpa& s) {
    // Scriviamo i dati dell'oggetto 's' nel flusso 'out' (ad esempio, std::cout)
    out << s._marca << " " << s._modello << " " << s._numero << " " << s._prezzo << " " << s._quantita;
    return out; // Restituiamo il flusso per permettere l'uso in catena
}


/*Si sviluppi quindi la funzione main che operi come segue: 



 */
int main(){

    fstream file;

    file.open("MagazzinoScarpe.txt",ios::in);

/*     - Apra in lettura il file MagazzinoScarpe.txt. Tale file contiene nella sua prima riga il numero di righe n di cui il file 
si compone e nelle righe successive, per ciascuna di esse, le informazioni relative alle scarpe nel seguente ordine: 
codice identificativo di marca e modello, numero, quantità di scarpe presenti in magazzino, prezzo.  */

//- Legga la prima riga del file MagazzinoScarpe.txt e allochi dinamicamente un array ms di n oggetti di tipo Scarpa. 
int numerorighe=0;
file>>numerorighe;

    Scarpa *ms=new Scarpa[numerorighe];


/*- Sfruttando l’operatore di estrazione, sopra definito per la classe Scarpa, legga le righe successive del file e assegni 
agli elementi dell’array ms le informazioni contenute in ciascuna riga del file. Per semplicità, si supponga che il 
file non sia vuoto e che i dati in esso contenuti siano validi. */

for(int i =0 ; i<numerorighe;i++){
    file>>ms[i];
}

/*- Chieda all’utente di inserire da tastiera un numero di scarpa, scandisca l’array ms e stampi a video la quantità di 
scarpe presenti in magazzino per il numero inserito dall’utente. */
    int sca=0;
    cout<<"inserisci numero scarpa:"<<endl;
    cin>>sca;

    int nsca=0;
    for(int i =0 ; i<numerorighe;i++){
        cout<<ms[i]<<endl;
        if(ms[i].get_numero()==sca){
            nsca++;

        }
    }

    cout<<"Numero di scarpe con il numero "<<sca<<":"<<nsca<<endl;
//- Deallochi l’array ms, chiuda il file e termini.

delete []ms;
file.close();

    return 0; 
}