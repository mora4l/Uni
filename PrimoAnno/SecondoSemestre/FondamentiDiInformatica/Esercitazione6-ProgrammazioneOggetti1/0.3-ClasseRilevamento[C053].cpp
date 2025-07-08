/*
Si desidera ora modificare la rappresentazione dei dati all’interno della classe rilevamento. Anziché, cioè,
rappresentare temperatura e pressione come due distinti attributi della classe, li si vuole aggregare in un
unico array. 



Osservate le modifiche al codice che si sono rese necessarie e commentatele: è stato necessario modificare le
funzioni stampa_rilevamento, leggi_rilevamento e main? Perché? Che cosa sarebbe successo se avessimo
dichiarato gli attributi della classe rilevamento come pubblici e le tre funzioni sopra citate avessero effettuato un
accesso diretto agli attributi, anziché passare per i selettori?
*/

#include <iostream>
using namespace std;

/*
La classe rilevamento avrà quindi un unico attributo: un array _dati costituito da due numeri
reali. Il primo elemento dell’array _dati sarà la misura della temperatura rilevata, il secondo elemento
sarà la misura della pressione rilevata
*/
/*
• Scrivere una nuova classe rilevamento che implementi la variazione richiesta, modificando i metodi ove
necessario. Per provare la versione modificata della classe si utilizzino le funzioni stampa_rilevamento e
leggi_rilevamento sviluppate in precedenza e la stessa funzione main, modificandone eventualmente il
codice ove necessario.
*/
class Rilevamento
{
public:
    // costruttori
    // Rilevamento();
    Rilevamento();
    //Rilevamento(double temperatura, double pressione);
    Rilevamento(double dati[]);
    Rilevamento(Rilevamento &r);

    // distruttori
    ~Rilevamento();

    // metodi
    void stampa_rilevamento(Rilevamento &r);

    void leggi_rilevamento(Rilevamento &r);
    // selettori
    //double getTemperatura();
    //double getPressione();

    double *getDati();

    // modificatori
    //void setTemperatura(double temperatura);
    //void setPressione(double pressione);

    void setDati(double dati[]);

private:
    // attributi
/*  double _temperatura;
    double dati[2]; */
    double _pressione;
    double _dati[2];
};

Rilevamento::Rilevamento() : _dati{0}
{
    cout << "crostruttore default" << endl;
}

Rilevamento::Rilevamento(double dati[]) 
{
    for(int i = 0 ; i<2; i++){
        _dati[i]=_dati[i];
    }


if((_dati[0]<-40)){
        cout<<"valori non validi della temperatura, li resetto a 0 "<<endl; 
        _dati[0]=0 ; 
        }else if((_dati[1]>1000)){
        cout<<"valori non validi della pressione, li resetto a 0 "<<endl; 
        _dati[1]=0 ; 
        }
    cout << "Questo e’ il secondo costruttore array" << endl;
}

Rilevamento::Rilevamento(Rilevamento &r)
{
    cout<<"sono il costruttore con parametro &r"<<endl ;
    for(int i = 0 ; i<2; i++){
        _dati[i]=r._dati[i];
    }
}



Rilevamento::~Rilevamento()
{
    cout << "questo è il distruttore della classe rilevamento " << endl;
}

//setter
void Rilevamento::setDati(double dati[]){
    cout<<"sono setdati"<<endl ;

    for(int i =0 ; i<2;i++){

        _dati[i]=dati[i];
    }
}

//getter
double *Rilevamento::getDati(){
    cout<<"sono getdati"<<endl ;
return _dati; 
}

void leggi_rilevamento(Rilevamento &r){
cout<<"sono la funzione leggi rilevamento "<<endl ;
    
    double temperatura = 0;
    double pressione = 0;
    cout << "inserisci temperatura e pressione : " << endl;
    cin >> temperatura;
    cin >> pressione;

double nuovidati[]={temperatura,pressione};

r.setDati(nuovidati);
}

void stampa_rilevamento(Rilevamento &r)
{


    cout<<"sono la funzione stampa rilevamento"<<endl ; 
    cout << "temperatura:" << endl
         << r.getDati()[0] << endl;
    cout << "pressione:" << endl
         << r.getDati()[1] << endl;
        
}

int main(){

    Rilevamento r4;

    leggi_rilevamento(r4);

    stampa_rilevamento(r4);

    return 0 ; 
}