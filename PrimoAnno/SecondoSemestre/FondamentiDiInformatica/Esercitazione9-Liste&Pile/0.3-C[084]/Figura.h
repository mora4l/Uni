/*
i progetti e si implementi in linguaggio C++ la classe Figura2D per rappresentare una figura complessa come una
collezione di poligoni bidimensionali. Internamente alla classe, una figura sarà rappresentata da una lista di
oggetti della classe Poligono2D; la classe Figura2D conterrà cioè, come attributo, una lista _poligoni di oggetti di
classe Poligono2D. A tale scopo, si riutilizzi la classe sviluppata nelle esercitazioni precedenti
*/
#ifndef FIGURA_H
#include "Poligono2D.h"
#include "List.h"
#include <iostream>
using namespace std;

class Figura2D{
    public:

    Figura2D(); //costruttore default
    Figura2D(Poligono2D* p,int n); //costruttore con parametri

    ~Figura2D(); //distruttore

    int numero_figure(); //ritorna il numero di figure
    const Poligono2D * ritorno_poligono(int i); //ritorna l'i-esimo elemento cercato
    void scambio_elemento(int i , Poligono2D p); //scambia un elemento dell'i-esima posizione con un nuovo elemento passato per parametro
    void inserisci_figura(Poligono2D nuovoPoligono); //inserisce una nuova figura in fondo
    void elimina_figura(int i ); //elimina un elemento

    Figura2D& operator=(const Figura2D& other);
    Figura2D operator*(double scalar) const;

    private:

    List<Poligono2D> poligoni;

};


#endif 