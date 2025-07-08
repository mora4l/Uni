/*Si scriva in linguaggio C++ l'interfaccia della classe raccolta_musicale, 
che contiene le informazioni relative alle caratteristiche principali di una raccolta di brani musicali, acquistabile online. 
La classe è dotata dei seguenti attributi: 
il numero intero _durata che rappresenta la durata in secondi dell'intera raccolta, 
il numero intero _brani che rappresenta il numero di brani di cui la raccolta si compone,
il carattere alfabetico _genere che rappresenta il genere della raccolta (ad esempio musica classica, pop, rock e così via), 
il numero reale _prezzo che rappresenta il prezzo per l'acquisto della raccolta. 

La classe è, inoltre, dotata dei
seguenti metodi:
• Il costruttore di default.
• Un costruttore con parametri che riceva i valori della durata, del numero di brani contenuti nella raccolta, del genere musicale e del prezzo.
• Il costruttore di copia.
• Il distruttore.
• I selettori (un metodo per ciascun attributo).
• I modificatori (un metodo per ciascun attributo).

• L'operatore di assegnamento.
• L'operatore == per stabilire se una raccolta di brani musicali è identica ad un'altra raccolta.
• L'operatore di inserimento.
• L'operatore di estrazione.*/
#include <iostream>
using namespace std;

class Raccolta_musicale{
    public:

    Raccolta_musicale();
    Raccolta_musicale(int durata,int brani,char genere,double prezzo);
    Raccolta_musicale(const Raccolta_musicale &r);

    ~Raccolta_musicale();

    int get_durata() const;
    int get_brani() const;
    char get_genere() const;
    double get_prezzo() const;

    void set_durata(int durata);
    void set_brani(int brani);
    void set_genere(char genere);
    void set_prezzo(double prezzo);

     const Raccolta_musicale& operator=(const Raccolta_musicale &r);
     
     bool operator==(Raccolta_musicale &r)const;

     friend std::istream &operator>>(istream &is, Raccolta_musicale &r);
     friend std::ostream &operator<<(ostream &os,const Raccolta_musicale &r);


    private:
    int _durata;
    int _brani;
    char _genere;
    double _prezzo;
    
};

Raccolta_musicale::Raccolta_musicale(){
    _durata=0;
    _brani=0;
    _genere=' ';
    _prezzo=0.0;
}

Raccolta_musicale::Raccolta_musicale(int durata,int brani,char genere,double prezzo){
    _durata=durata;
    _brani=brani;
    _genere=genere;
    _prezzo=prezzo;
}

Raccolta_musicale::Raccolta_musicale(const Raccolta_musicale &r){
    _durata=r._durata;
    _brani=r._brani;
    _genere=r._genere;
    _prezzo=r._prezzo;
}

Raccolta_musicale::~Raccolta_musicale(){};

int Raccolta_musicale::get_durata()const {
    return _durata;
}
int Raccolta_musicale::get_brani()const {
    return _brani;
}
char Raccolta_musicale::get_genere()const {
    return _genere;
}
double Raccolta_musicale::get_prezzo()const {
    return _prezzo;
}

void Raccolta_musicale::set_durata(int durata){
    _durata=durata;
}
void Raccolta_musicale::set_brani(int brani){
    _brani=brani;
}
void Raccolta_musicale::set_genere(char genere){
    _genere=genere;
}
void Raccolta_musicale::set_prezzo(double prezzo){
    _prezzo=prezzo;
}

const Raccolta_musicale& Raccolta_musicale::operator=(const Raccolta_musicale &r){
    if(this!=&r){

    _durata=r._durata;
    _brani=r._brani;
    _genere=r._genere;
    _prezzo=r._prezzo;

    }

    return *this;
}

bool Raccolta_musicale::operator==(Raccolta_musicale &r)const{
    return (    (_durata==r._durata)&&
                 (_brani==r._brani)&&
                (_genere==r._genere)&&
                (_prezzo==r._prezzo));
}

std::istream &operator>>(istream &is, Raccolta_musicale &r){
    is>>r._durata>>r._brani>>r._genere>>r._prezzo;
    return is;
}

std::ostream &operator<<(ostream &os,const Raccolta_musicale &r){
    os<<r._durata<<r._brani<<r._genere<<r._prezzo;
    return os;
}

int main()
{

    return 0 ; 
}