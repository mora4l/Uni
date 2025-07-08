#include "Figura.h"
#include <iostream>
#include <cmath>
using namespace std;

/*
La classe Figura2D implementerà inoltre i seguenti metodi:
*/

/* • Il costruttore di default.
 */
Figura2D::Figura2D(){
    //il costruttore della lista fa tutto 
}
/*
• Un costruttore con parametri che riceva un array p di oggetti di tipo Poligono2D e la sua dimensione n (un
numero intero) e inizializzi la figura inserendo nella lista _poligoni gli elementi dell’array p.
*/
Figura2D::Figura2D(Poligono2D *p,int n){
    cout<<"sono il costruttore di FIGURA2D, inizializzo la figura inserendo nella lista poligoni gli elementi dell'array passato"<<endl;
    for(int i =0 ; i<n;i++){

        poligoni.insertBack(p[i]);
    }
}

/*
• Il costruttore di copia.
*/
Figura2D::Figura2D(const Figura2D &figura2d):poligoni(figura2d.poligoni){ //chiamo il costruttore di copia della lista
    cout<<"sono il costruttore di copia di FIGURA2D"<<endl;
}

/*
• Il distruttore.
*/
Figura2D::~Figura2D(){
 //viene chiamato automaticamente
cout<<"sono il distruttore di FIGURA2D"<<endl;
}

/*
• Un metodo per ottenere il numero di poligoni che compongono la figura.
*/

int Figura2D::numero_figure(){
    cout<<"restituisco il numero di figure nella lista..."<<endl;
return poligoni.numItems();
}

/*
• Un metodo che riceva come parametro un numero intero i e restituisca come valore di ritorno un puntatore a
costante all’i-esimo poligono della figura. Nel caso in cui il valore dell’indice i non sia valido, il metodo
restituisce NULL
*/

const Poligono2D* Figura2D::ritorno_poligono(int i){
    
    if((i<0)||(i>poligoni.numItems())){
        cout<<"l'indice non era valido .ho restituito nullptr"<<endl;
        return nullptr;

    }
    
    Node<Poligono2D> *oggettodatrovare=poligoni.getHead(); //creo un puntatore per cercare l'elemento che voglio

    int count=0 ; //creo una var che conta quanti elementi ho passato
 
    while((oggettodatrovare!=nullptr) && (count<i)){ //finche il puntatore non è arrivato in fondo oppure non è arrivato all'i-esimo elemento...
        oggettodatrovare=oggettodatrovare->getNext(); //scorre gli elementi della lista
        count ++;
    }
    if(oggettodatrovare=nullptr){ 
        return nullptr;
        cout<<"non ho trovato l'oggetto"<<endl;
    }

    return &(oggettodatrovare->getData()); //appena esce dal ciclo ritorna quell'elemento
}

/*
• Gli operatori di inserimento ed estrazione
*/

/*
Un metodo che riceva come parametro un numero intero i e un oggetto p di classe Poligono2D e sostituisca l’i-
esimo poligono contenuto nella lista _poligoni con il poligono p passato come parametro al metodo. Nel caso
in cui il valore dell’indice i non sia valido, la lista _poligoni non viene modificata.
*/
void Figura2D::scambio_elemento(int i,Poligono2D poligonoSostitutivo){
    if((i<0)||(i>=poligoni.numItems())){ //se l'indice non è valido esce senza fare niente
        cout<<"l'indice non era valido , esco senza fare niente"<<endl;
        return ;

    }

    Node<Poligono2D> *oggettodascambiare=poligoni.getHead(); //se no intesto ad un nuovo puntatore la testa e scorro

    int count=0; 

    while((oggettodascambiare!=nullptr)&& (count<i)){ //scorro fino a quando non trovo l'i-esimo oggetto da scambiare
        oggettodascambiare=oggettodascambiare->getNext();
        count ++;
    }
    if(oggettodascambiare!=nullptr){ //e se non punta al vuoto lo scambio

        oggettodascambiare->setData(poligonoSostitutivo);
        cout<<"ho scambiato l'oggetto"<<endl;
    }

}

/*
• Un metodo per aggiungere alla figura un nuovo poligono (passato come parametro).
*/
void Figura2D::inserisci_figura(Poligono2D nuovoPoligono){

    if(poligoni.isEmpty()){ //se la lista è vuota lo metto davanti per primo
        poligoni.insertFront(nuovoPoligono);
        cout<<"l'indice non era valido , esco senza fare niente"<<endl;
        return; //ed esco 

    }
Node <Poligono2D> *oggettopenultimo=poligoni.getHead(); //se no inizio a scorrere la lista con un puntatore d'appoggio
while(oggettopenultimo->getNext()!=nullptr){ //e scorro
    oggettopenultimo=oggettopenultimo->getNext();
}

poligoni.insertAfter(oggettopenultimo,nuovoPoligono); //e lo metto davanti all'ultimo trovato
cout<<"ho inserito il nuovo oggetto"<<endl;
}

/*
• Un metodo che riceva come parametro un numero intero i ed elimini l’i-esimo poligono dalla figura,
rimuovendolo dalla lista _poligoni. Nel caso in cui il valore dell’indice i non sia valido, la lista _poligoni non
viene modificata.
*/

void Figura2D::elimina_figura(int i){
    if((i<0)||(i>=poligoni.numItems())){ //se l'indice non è valido esco senza fare niente
        cout<<"l'indice non era valido , esco senza fare niente"<<endl;
        return;
    }
    Node<Poligono2D> *ElementoDaEliminare=poligoni.getHead();
    int count=0; 
    while((ElementoDaEliminare!=nullptr)&& (count<i)){ //scorro fino a quando non trovo l'i-esimo oggetto da eliminare
        ElementoDaEliminare=ElementoDaEliminare->getNext();
        count ++;
    }
    if(ElementoDaEliminare!=nullptr){
        poligoni.removeAt(ElementoDaEliminare);
    }

}

/*
• L’operatore di assegnamento.
*/
Figura2D& Figura2D::operator=(const Figura2D& other) {
    if (this != &other) {          // controllo self-assignment
        poligoni.clear();          // svuoto la lista attuale
        // copio la lista di poligoni dall’altro oggetto
        poligoni = other.poligoni; // usa operatore di assegnamento di List
    }
    return *this;                  // ritorno l’oggetto assegnato
}
Figura2D Figura2D::operator*(double scalar) const {
    Figura2D result;  // nuova figura vuota

    Node<Poligono2D>* p = poligoni.getHead();

    while (p != nullptr) {
        // De-referenzio getData() per ottenere l'oggetto Poligono2D
        //Poligono2D scaledPoly = p->getData() * scalar;

       // result.poligoni.insertBack(scaledPoly);

        p = p->getNext();
    }

    return result;
}
