/*
Allo scopo di gestire l’acquisizione di dati da un sensore meteorologico che rileva la temperatura (misurata in gradi Celsius)
e la pressione (misurata in hPa) dell’aria, si sviluppi in C++ la classe rilevamento avente i seguenti attributi: un numero
reale _temperatura e un numero reale _pressione.
Si implementino, inoltre, i seguenti metodi:



*/

#include <iostream>
using namespace std; 

class Rilevamento{
public : 

    Rilevamento ();
    Rilevamento(double t, double p ); 
    Rilevamento(double dati[]);

    void stampa_rilevamento();
    private : 

    double temperatura ; 
    double pressione ; 
    double dati[2];
  

}; 

/* • Il costruttore di default che inizializzi a zero entrambi gli attributi. A scopo didattico, aggiungere nel corpo del
costruttore la stampa a video del seguente messaggio “Questo e’ il costruttore di default della classe rilevamento”.
 */
Rilevamento::Rilevamento(){
    temperatura = 0; 
    pressione = 0 ; 
    cout<<"crostruttore zio"<<endl ;
}

/* • Un costruttore con parametri che riceva in ingresso (ovvero come parametri) due numeri reali t e p e inizializzi
l’attributo _temperatura al valore di t e l’attributo _pressione al valore di p. Per semplicità, si assuma che i valori assunti
da t e da p siano sempre validi. A scopo didattico, aggiungere nel corpo del costruttore la stampa a video del seguente
messaggio “Questo e’ il primo costruttore con parametri della classe rilevamento”.
 */
Rilevamento::Rilevamento(double t, double p ){
    cout<<"free davide lacerenza, ci bossi di brutto"<<endl ; 
    temperatura = t ; 
    pressione =  p; 
}

/*
Un costruttore con parametri che riceva in ingresso (ovvero come parametri) un array dati di due numeri reali e
inizializzi l’attributo _temperatura al valore del primo elemento dell’array dati e l’attributo _pressione al valore del
secondo elemento dell’array dati. 
Per semplicità, si assuma che i valori assunti dagli elementi dell’array dati siano
sempre validi. A scopo didattico, aggiungere nel corpo del costruttore la stampa a video del seguente messaggio
“Questo e’ il secondo costruttore con parametri della classe rilevamento”.
*/

Rilevamento::Rilevamento(double dati[]){
    temperatura = dati[0];
    pressione=dati[1];

    cout<<"Questo e’ il secondo costruttore con parametri della classe rilevamento"<<endl;
}

/*
• Il costruttore di copia. A scopo didattico, aggiungere nel corpo del costruttore la stampa a video del messaggio “Questo
e’ il costruttore di copia della classe rilevamento”.
*/

/* Rilevamento::Rilevamento(){
    cout<<"costruttore copia"<<endl; 
} */


/*
• Il metodo stampa_rilevamento che stampi a video i valori degli attributi secondo il seguente formato:
• “Rilevamento: temperatura = x C, pressione = y hPa” dove al posto di x e y vengono sostituiti i valori correnti degli
attributi _temperatura e _pressione, rispettivamente. La funzione non restituisce alcun valore di ritorno.
*/
    void Rilevamento::stampa_rilevamento(){
    cout<<"temperatura:"<<temperatura<<endl ;
        cout<<"pressione:"<<pressione<<endl ;
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

int main(){
    

   Rilevamento r1; 
   r1.stampa_rilevamento() ; 

    Rilevamento r2(20.0,1000.0) ;
    r2.stampa_rilevamento();

    double ril[2]={15.0,1010.0};

    Rilevamento r3(ril);
    r2.stampa_rilevamento();

    Rilevamento r4 =r1;
    r4.stampa_rilevamento();
    return 0 ;
}