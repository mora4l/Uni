
#include <iostream>
using namespace std;

class Rilevamento
{
public:
    // costruttori
    Rilevamento();
    Rilevamento(double temperatura, double pressione);
    Rilevamento(Rilevamento &r);

    // distruttori
    ~Rilevamento();

    // metodi
    void stampa_rilevamento(Rilevamento &r);
    void leggi_rilevamento(Rilevamento &r);

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

Rilevamento::Rilevamento() : _temperatura(0), _pressione(0)
{
    cout << "sono il costruttore default [1]" << endl;
}
Rilevamento::Rilevamento(double t, double p) : _temperatura(t), _pressione(p)
{
    if ((_temperatura < -40))
    {
        cout << "valori non validi della temperatura, li resetto a 0 " << endl;
        _temperatura = 0;
    }
    else if ((_pressione < -500))
    {
        cout << "valori non validi della pressione, li resetto a 0 " << endl;
        _pressione = 0;
    }

    cout << "costruttore diretto nell argomento con t e p" << endl;
}

Rilevamento::Rilevamento(Rilevamento &r)
{
    cout << "sono la copia del costruttore [1]" << endl;
    _temperatura = r._temperatura;
    _pressione = r._pressione;
}

/*
• aggiungere il distruttore. A scopo didattico, aggiungere nel corpo del distruttore la stampa a video del
seguente messaggio “Questo e’ il distruttore della classe rilevamento”.
*/

Rilevamento::~Rilevamento()
{
    cout << "questo è il distruttore [1]" << endl;
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
    if ((temperatura < -40) || (temperatura > 70))
    {
        cout << "valori non validi della temperatura " << endl;
    }
    cout << "sono il modificatore di temperatura" << endl;

    _temperatura = temperatura;
}

void Rilevamento::setPressione(double pressione)
{
    if ((pressione < -500) || (pressione > 1000))
    {
        cout << "valori non validi della pressione " << endl;
    }
    cout << "sono il modificatore di pressione" << endl;

    _pressione = pressione;
}

/*
• modificare la funzione stampa_rilevamento, rendendola una funzione esterna alla classe.
*/

void Rilevamento::stampa_rilevamento(Rilevamento &r)
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

void Rilevamento::leggi_rilevamento(Rilevamento &r)
{
    double temperatura = 0;
    double pressione = 0;
    cout << "inserisci temperatura e pressione : " << endl;
    cin >> temperatura;
    cin >> pressione;

    r.setPressione(pressione);
    r.setTemperatura(temperatura);
}

/*
Per fare di più:
• Implementare le verifiche della validità dei dati anche per la classe tempo.

• Implementare la verifica di validità anche per il metodo leggi aggiunto alla classe rilevamento. Anche in questo
caso, il metodo continuerà a chiedere all’utente di inserire i dati finché non si ottengano dei dati validi (ovvero
un valore tra -40 °C e 70 °C per la temperatura e un valore compreso tra 900 e 1100 hPa per la pressione).
*/

/*
Sviluppare la classe tempo avente i seguenti attributi: l’ora, il minuto e il secondo in cui è stato effettuato un
rilevamento (tre numeri interi). Si implementino, inoltre, i seguenti metodi:
*/
class tempo
{

public:
    // costruttori

    tempo();                                 // default
    tempo(int ora, int minuto, int secondo); // con parametri
    tempo(tempo &r);                         // di copia
    ~tempo();                                // distruttore

    // setter
    void setOra(int ora);
    void setMinuto(int minuto);
    void setSecondo(int secondo);

    // getter
    int getOra();
    int getMinuto();
    int getSecondo();

    // metodi
    void stampa_tempo();
    void leggi();

private:
    int _ora;
    int _minuto;
    int _secondo;
};
/*
• Modificarne di conseguenza il costruttore con parametri, i modificatori e il metodo leggi in modo tale che
accertino che il valore passato od ottenuto per l’ora sia compreso tra 0 e 23 e che il valore passato od ottenuto
per i minuti e per i secondi sia compreso tra 0 e 59. In particolare, in caso di dati non validi, il costruttore con
parametri inizializzerà a zero tutti gli attributi della classe, i modificatori non modificheranno il valore degli
attributi e il metodo leggi continuerà a chiedere all’utente di inserire i dati finché non si ottengano dei dati
validi.
*/
/*
• Il costruttore di default che inizializzi a zero tutti gli attributi. Si può scegliere se implementare il
costruttore usando oppure non usando la lista di inizializzazione. A scopo didattico, aggiungere nel corpo
del costruttore la stampa a video del seguente messaggio “Questo e’ il costruttore di default della classe
tempo”.
*/
tempo::tempo()
{

    cout << "sono il costruttore default [2]" << endl;
    _ora = 0;
    _minuto = 0;
    _secondo = 0;
}

/*
• Un costruttore con parametri che riceva in ingresso (ovvero come parametri) tre numeri interi
rappresentanti l’ora, il minuto e il secondo in cui è stato effettuato un rilevamento e assegni tali valori ai
corrispondenti attributi della classe tempo. Per semplicità, si assuma che i valori passati come parametri
attuali al costruttore siano sempre validi. Si può scegliere se implementare il costruttore usando oppure
non usando la lista di inizializzazione.
*/
tempo::tempo(int ora, int minuto, int secondo) : _ora(ora), _minuto(minuto), _secondo(secondo)
{
    cout << "sono il costruttore con parametri [2]" << endl;
    if ((ora < 0 || ora > 23) && (minuto < 0 || minuto > 59) && (secondo < 0 || secondo > 59))
    {
        cout << "dati dell'orario non validi, verranno resettati a zero." << endl;
        _ora = 0;
        _minuto = 0;
        _secondo = 0;
    }
}

/*
• Il costruttore di copia. Si può scegliere se implementare il costruttore usando oppure non usando la lista
di inizializzazione
*/
tempo::tempo(tempo &r) : _ora(r._ora), _minuto(r._minuto), _secondo(r._secondo)
{
    cout << "sono il costruttore copia [2]" << endl;
    if ((r._ora < 0 || r._ora > 23) && (r._minuto < 0 || r._minuto > 59) && (r._secondo < 0 || r._secondo > 59))
    {
        cout << "dati dell'orario non validi, verranno resettati a zero." << endl;
        _ora = 0;
        _minuto = 0;
        _secondo = 0;
    }
}

/*
Il distruttore. A scopo didattico, aggiungere nel corpo del distruttore la stampa a video del seguente
messaggio “Questo e’ il distruttore della classe tempo”.
*/
tempo::~tempo()
{
    cout << "sono il distruttore [2]" << endl;
}

/*
• I selettori (un metodo per ciascun attributo).
*/
void tempo::setOra(int ora)
{
    cout << "sono il setter [2]" << endl;
    _ora = ora;

    if ((ora < 0) || (ora > 23))
    {
        ora = 0;
    }
}
void tempo::setMinuto(int minuto)
{
    cout << "sono il setter [2]" << endl;
    _minuto = minuto;

    if ((minuto < 0) || (minuto > 59))
    {
        _minuto = 0;
    }
}
void tempo::setSecondo(int secondo)
{
    cout << "sono il setter [2]" << endl;
    _secondo = secondo;

    if ((secondo < 0) || (secondo > 59))
    {
        secondo = 0;
    }
}

/*
• I modificatori (un metodo per ciascun attributo). Per semplicità, si assuma che i valori passati come
parametri attuali ai modificatori siano sempre validi.
*/
int tempo::getOra()
{
    cout << "sono il getter [2]" << endl;
    return _ora;
}
int tempo::getMinuto()
{
    cout << "sono il getter [2]" << endl;
    return _minuto;
}
int tempo::getSecondo()
{
    cout << "sono il getter [2]" << endl;
    return _secondo;
}

/*
• Il metodo stampa che stampi a video il momento in cui un rilevamento è stato effettuato, secondo il
seguente formato: “Ore: h:m:s” dove al posto di h, m e s vengono sostituiti i valori correnti degli attributi
della classe tempo contenenti l’informazione relativa a ora, minuto e secondo del rilevamento,
rispettivamente. Il metodo non restituisce alcun valore di ritorno.
*/
void tempo::stampa_tempo()
{
    cout << "rilevamento effettuato" << endl;
    cout << _ora << ":" << _minuto << ":" << _secondo << endl;
}

/*
Il metodo leggi che legga da tastiera il momento in cui un rilevamento è stato effettuato (ora, minuto e
secondo) e assegni i valori letti ai corrispondenti attributi della classe tempo. Il metodo non restituisce
alcun valore di ritorno.
*/
void tempo::leggi()
{
    int repeat = 0;
    do
    {
        repeat++;
        if (repeat > 1)
        {
            cout << "reinserisci i valori , non erano validi" << endl;
        }
        cout << "inserisci ora,minuto e secondo della rilevazione" << endl;
        cin >> _ora >> _minuto >> _secondo;

    } while ((_ora < 0 || _ora > 23) && (_minuto < 0 || _minuto > 59) && (_secondo < 0 || _secondo > 59));
}

class lettura_sensore
{
public:
    // costruttore

    lettura_sensore();                         // default
    lettura_sensore(tempo &t, Rilevamento &r); // con parametri
    // lettura_sensore(tempo &t, Rilevamento &r); // copia

    // distruttore
    ~lettura_sensore();

    // setter
    void setT(tempo t);
    void setR(Rilevamento r);

    // getter
    tempo &getT();
    Rilevamento &getR();

    // metodi
    void stampaFinale(tempo &t, Rilevamento &r);
    void leggi(tempo &t, Rilevamento &r);

private:
    /*
    • un oggetto _t di classe tempo che rappresenta il tempo in cui si è effettuato il rilevamento (ovvero il momento
    in cui è stata effettuata la lettura dei dati) e
    • un oggetto _r di classe rilevamento che rappresenta i valori rilevati (ovvero il risultato della lettura dei dati).
    */
    tempo _t;
    Rilevamento _r;
};

/*
• Il costruttore di default, utilizzando la lista di inizializzazione. A scopo didattico, aggiungere nel corpo del
costruttore la stampa a video del seguente messaggio “Questo e’ il costruttore di default della classe
lettura_sensore”.
*/
lettura_sensore::lettura_sensore() : _t(), _r()
{
    cout << "sono il costruttore default [3]" << endl;
}

/*
• Un costruttore con parametri che riceva in ingresso (ovvero come parametri) un oggetto t di classe tempo
e un oggetto r di classe rilevamento e, utilizzando la lista di inizializzazione, assegni i due oggetti ai
corrispondenti attributi della classe.
*/
lettura_sensore::lettura_sensore(tempo &t, Rilevamento &r) : _t(t), _r(r)
{
    cout << "sono il costruttore con parametri [3]" << endl;
}

/*
• Il costruttore di copia, utilizzando la lista di inizializzazione.
*/
/* lettura_sensore::lettura_sensore(tempo &t, Rilevamento &r) : _r(r), _t(t)
{
    cout << "sono il costruttore copia [3]" << endl;
} */

/*
Il distruttore. A scopo didattico, aggiungere nel corpo del distruttore la stampa a video del seguente
messaggio “Questo e’ il distruttore della classe lettura_sensore”.
*/
lettura_sensore::~lettura_sensore()
{
    cout << "sono il distruttore [3]" << endl;
}

/*
I modificatori (un metodo per ciascun attributo). Nota: in questo caso specifico sarà possibile utilizzare l’operatore
di assegnamento che effettuerà un assegnamento bit a bit dei valori degli attributi.
*/
void lettura_sensore::setT(tempo t)
{
    cout << "sono il setter[3]" << endl;
    _t = t;
}
void lettura_sensore::setR(Rilevamento r)
{
    cout << "sono il setter[3]" << endl;
    _r = r;
}

/*• I selettori (un metodo per ciascun attributo).*/
tempo &lettura_sensore::getT()
{
    cout << "sono il getter [3]" << endl;
    return _t;
}
Rilevamento &lettura_sensore::getR()
{
    cout << "sono il getter [3]" << endl;
    return _r;
}

/*
• Il metodo stampa che, invocando i metodi corrispondenti delle classi rilevamento e tempo, stampi a video il
momento in cui un rilevamento è stato effettuato e i valori rilevati di temperatura e pressione. Il metodo non
restituisce alcun valore di ritorno.
*/
void lettura_sensore::stampaFinale(tempo &t, Rilevamento &r)
{
    cout << "sono stampa [3]" << endl;
    _r.stampa_rilevamento(r);
    _t.stampa_tempo();
}

/*
Il metodo leggi che, invocando i metodi corrispondenti delle classi rilevamento e tempo, legga da tastiera il momento
in cui un rilevamento è stato effettuato e i valori rilevati di temperatura e pressione. Il metodo non restituisce alcun
valore di ritorno
*/
void lettura_sensore::leggi(tempo &t, Rilevamento &r)
{
    cout << "sono leggi [3]" << endl;
    _r.leggi_rilevamento(r);
    _t.leggi();
}

int main()
{

    /* • Dichiari un array d composto di tre oggetti di classe lettura_sensore.
     */
    lettura_sensore d[3];
    tempo t;
    Rilevamento r;
    /*
    • Scandisca l’array d e, invocando il metodo leggi su ciascuno dei suoi elementi, legga da tastiera i dati relativi
    alle tre letture di dati dal sensore.
    */
    for (int i = 0; i < 3; i++)
    {
        cout << "lettura elemento " << i << " dell'array di oggetti" << endl;
        d[i].leggi(t, r);
        cout << endl
             << endl
             << endl
             << endl;
    }

    cout << endl
         << endl
         << endl
         << endl
         << "fine lettura elementi" << endl
         << endl
         << endl
         << endl
         << endl;
    /* • Scandisca nuovamente l’array d e, invocando il metodo stampa su ciascuno dei suoi elementi, stampi a video i
    dati relativi alle tre letture appena effettuate. */
    for (int i = 0; i < 3; i++)
    {
        /*
        Eseguite il programma, osservate le stampe a video dei messaggi prodotti dalle chiamate ai costruttori e al distruttore
        e commentatele: quante volte vengono chiamati i costruttori di ciascuna delle tre classi? In che ordine? Quante volte
        vengono chiamati i distruttori di ciascuna delle tre classi? In che ordine?
        */
        cout << "lettura elemento " << i << " dell'array di oggetti" << endl;
        d[i].stampaFinale(t, r);
        cout << endl
             << endl
             << endl
             << endl;
    }

    cout << endl
         << endl
         << endl
         << endl
         << "fine stampa elementi" << endl
         << endl
         << endl
         << endl
         << endl;

    return 0;
}