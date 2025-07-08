/*
Partendo dall’esercizio C051:

*/
/*
Allo scopo di gestire l’acquisizione di dati da un sensore meteorologico che rileva la temperatura (misurata in gradi Celsius)
e la pressione (misurata in hPa) dell’aria, si sviluppi in C++ la classe rilevamento avente i seguenti attributi: un numero
reale _temperatura e un numero reale _pressione.
Si implementino, inoltre, i seguenti metodi:
*/

#include <iostream>
using namespace std;

class Rilevamento
{
public:
    // costruttori
    // Rilevamento();
    Rilevamento();
    Rilevamento(double temperatura, double pressione);
    Rilevamento(double dati[]);
    Rilevamento(Rilevamento &r);

    // distruttori
    ~Rilevamento();

    // metodi
    void stampa_rilevamento();

    // selettori
    double getTemperatura();
    double getPressione();

    // modificatori
    void setTemperatura(double temperatura);
    void setPressione(double pressione);

private:
    // attributi
    double _temperatura;
    double _pressione;
    double dati[2];
};

/* • Il costruttore di default che inizializzi a zero entrambi gli attributi. A scopo didattico, aggiungere nel corpo del
costruttore la stampa a video del seguente messaggio “Questo e’ il costruttore di default della classe rilevamento”.
 */
/* Rilevamento::Rilevamento()
{

} */
/* • Un costruttore con parametri che riceva in ingresso (ovvero come parametri) due numeri reali t e p e inizializzi
l’attributo _temperatura al valore di t e l’attributo _pressione al valore di p. Per semplicità, si assuma che i valori assunti
da t e da p siano sempre validi. A scopo didattico, aggiungere nel corpo del costruttore la stampa a video del seguente
messaggio “Questo e’ il primo costruttore con parametri della classe rilevamento”.
 */
/* Rilevamento::Rilevamento(double t, double p)
{
    cout << "free davide lacerenza, ci bossi di brutto" << endl;
    _temperatura = t;
    _pressione = p;
} */

/*
Un costruttore con parametri che riceva in ingresso (ovvero come parametri) un array dati di due numeri reali e
inizializzi l’attributo _temperatura al valore del primo elemento dell’array dati e l’attributo _pressione al valore del
secondo elemento dell’array dati.
Per semplicità, si assuma che i valori assunti dagli elementi dell’array dati siano
sempre validi. A scopo didattico, aggiungere nel corpo del costruttore la stampa a video del seguente messaggio
“Questo e’ il secondo costruttore con parametri della classe rilevamento”.
*/

/* Rilevamento::Rilevamento(double dati[])
{
    _temperatura = dati[0];
    _pressione = dati[1];

    cout << "Questo e’ il secondo costruttore con parametri della classe rilevamento" << endl;
} */

/*
• Il costruttore di copia. A scopo didattico, aggiungere nel corpo del costruttore la stampa a video del messaggio “Questo
e’ il costruttore di copia della classe rilevamento”.
*/

/* Rilevamento::Rilevamento(){
    cout<<"costruttore copia"<<endl;
} */
/*
• implementare i costruttori utilizzando le liste di inizializzazione
*/
/*
Opzionale:
• Infine, supponiamo ora che il sensore meteorologico possa misurare temperature comprese tra -40 °C e
70 °C e pressioni comprese tra 500 e 1000 hPa. Modificare di conseguenza i costruttori con parametri e i
modificatori della classe rilevamento affinché verifichino la validità dei dati. In particolare, in caso di dati
non validi, i costruttori con parametri inizializzeranno a zero entrambi gli attributi della classe, mentre i
modificatori non modificheranno il valore degli attributi.
*/
Rilevamento::Rilevamento() : _temperatura(0), _pressione(0)
{
    cout << "crostruttore default" << endl;
}
Rilevamento::Rilevamento(double t, double p) : _temperatura(t), _pressione(p)
{
    if((_temperatura<-40)){
        cout<<"valori non validi della temperatura, li resetto a 0 "<<endl; 
        _temperatura=0 ; 
        }else if((_pressione<-500)){
        cout<<"valori non validi della pressione, li resetto a 0 "<<endl; 
        _pressione=0 ; 
        }

    cout << "costruttore diretto nell argomento con t e p" << endl;
}

Rilevamento::Rilevamento(double dati[]) : _temperatura(dati[0]), _pressione(dati[1])
{
if((dati[0]<-40)){
        cout<<"valori non validi della temperatura, li resetto a 0 "<<endl; 
        _temperatura=0 ; 
        }else if((dati[1]>1000)){
        cout<<"valori non validi della pressione, li resetto a 0 "<<endl; 
        _pressione=0 ; 
        }
    cout << "Questo e’ il secondo costruttore array" << endl;
}

Rilevamento::Rilevamento(Rilevamento &r)
{
    cout << "sono la copia del costruttore " << endl;
    _temperatura = r._temperatura;
    _pressione = r._pressione;
}

/*
• aggiungere il distruttore. A scopo didattico, aggiungere nel corpo del distruttore la stampa a video del
seguente messaggio “Questo e’ il distruttore della classe rilevamento”.
*/

Rilevamento::~Rilevamento()
{
    cout << "questo è il distruttore della classe rilevamento " << endl;
}

/*
• aggiungere i selettori (uno per ciascun attributo)
*/

double Rilevamento::getTemperatura()
{
    cout << "sono il selettore di temperatura" << endl;
    return _temperatura;
}

double Rilevamento::getPressione()
{
    cout << "sono il selettore di pressione" << endl;

    return _pressione;
}

/*
• aggiungere i modificatori (uno per ciascun attributo). Per semplicità, si assuma che i valori passati come
parametri attuali ai modificatori siano sempre validi. A quel punto si chiede di rendere tutti gli attributi delle
classe Rilevamento privati.
*/

void Rilevamento::setTemperatura(double temperatura)
{
    if((temperatura<-40)||(temperatura>70)){
        cout<<"valori non validi della temperatura "<<endl; 

        }
    cout << "sono il modificatore di temperatura" << endl;

    _temperatura = temperatura;
}

void Rilevamento::setPressione(double pressione)
{
    if((pressione<-500)||(pressione>1000)){
        cout<<"valori non validi della pressione "<<endl; 
        }
    cout << "sono il modificatore di pressione" << endl;

    _pressione = pressione;
}

/*
• Il metodo stampa_rilevamento che stampi a video i valori degli attributi secondo il seguente formato:
• “Rilevamento: temperatura = x C, pressione = y hPa” dove al posto di x e y vengono sostituiti i valori correnti degli
attributi _temperatura e _pressione, rispettivamente. La funzione non restituisce alcun valore di ritorno.
*/
/* void Rilevamento::stampa_rilevamento()
{
    cout << "temperatura:" << _temperatura << endl;
    cout << "pressione:" << _pressione << endl;
} */

/*
• modificare la funzione stampa_rilevamento, rendendola una funzione esterna alla classe.
*/

void stampa_rilevamento(Rilevamento &r)
{
    cout << "temperatura:" << endl
         << r.getTemperatura() << endl;
    cout << "pressione:" << endl
         << r.getPressione() << endl;
}

/*
• aggiungere, come funzione esterna alla classe rilevamento, la funzione leggi_rilevamento che riceva come
parametro di uscita (ovvero per riferimento) un oggetto di tipo rilevamento, chieda all’utente di inserire da
tastiera i valori di temperatura e pressione letti dal sensore meteorologico (due numeri reali) e assegni tali
valori agli attributi dell’oggetto passato come parametro attuale alla funzione. Per semplicità, si assuma che i
valori inseriti dall’utente siano sempre validi. La funzione non restituisce alcun valore di ritorno.
*/

void leggi_rilevamento(Rilevamento &r1)
{
    double temperatura = 0;
    double pressione = 0;
    cout << "inserisci temperatura e pressione : " << endl;
    cin >> temperatura;
    cin >> pressione;

    r1.setPressione(pressione);
    r1.setTemperatura(temperatura);
}


/*
Si scriva, infine, la funzione main che operi come segue:
• Dichiari un oggetto r1 di tipo rilevamento, stampando i valori di temperatura e pressione;
• Dichiari un oggetto r2 di tipo rilevamento – inizializzandolo con i valori 20.0 per la temperatura e 1000.0 per la
pressione, stampando i valori di temperatura e pressione;
• Dichiari un array ril di due numeri reali, inizializzi i due elementi di ril rispettivamente ai valori 15.0 e 1010.0, stampando
i valori di temperatura e pressione;
• Dichiari un oggetto r4 di tipo rilevamento, inizializzandolo come copia di r1, stampando i valori di temperatura e pressione
*/

// parte 2:

/*
Partendo dall’esercizio C051:

*/

int main()
{

    /*     Rilevamento r1;
        r1.stampa_rilevamento();

        Rilevamento r2(20.0, 1000.0);
        r2.stampa_rilevamento();

        double ril[2] = {15.0, 1010.0};

        Rilevamento r3(ril);
        r2.stampa_rilevamento();

        Rilevamento r4 = r1;
        r4.stampa_rilevamento(); */
    /*
    • nel main, dichiarare l’oggetto r4 di tipo rilevamento, chiamando la funzione leggi_rilevamento passandole
    l’oggetto r4 come parametro attuale e chiamare la funzione stampa_rilevamento, passandole l’oggetto r4 come
    parametro attuale.
    */
    Rilevamento r4;

    leggi_rilevamento(r4);

    stampa_rilevamento(r4);

    /*

    Eseguite il programma, osservate le stampe a video dei messaggi prodotti dalle chiamate ai costruttori e al
    distruttore e commentatele:
    • Quali costruttori vengono chiamati durante l’esecuzione delle istruzioni della funzione main? viene chiamato il default


    • Il costruttore di copia non viene ora mai esplicitamente utilizzato, ma il messaggio contenuto nel suo corpo
    risulta stampato a video. Pertanto, anche il costruttore di copia viene chiamato durante l’esecuzione del
    programma. Quando viene chiamato? Perché? 
    viene chiamato quando si crea una nuova istanza uguale ad un altra 


    • Quante volte viene chiamato il costruttore di copia durante l’esecuzione dell’ultima parte della funzione main?
    Come questo si collega alla chiamata delle due funzioni leggi_rilevamento e stampa_rilevamento?
    • Quando e per quante volte viene chiamato il distruttore? Perché?



    */
    return 0;
}