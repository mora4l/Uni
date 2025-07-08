#ifndef Poligono2D_H
#define Poligono2D_H
#include "Punto2D.h"
#include <iostream>
using namespace std;

class Poligono2D
{
public:
    // costruttori
    Poligono2D();
    Poligono2D(int dim);
    Poligono2D(Punto2D pti[], int dim);
    Poligono2D(Poligono2D &p);

    // getter (selettori)
    Punto2D *getPunto();
    Poligono2D getN();
    void setArray(Punto2D pti[], int dim);

    // operatori
    Poligono2D operator*(double scalare);       // scalare
    Poligono2D &operator=(const Poligono2D &p); // di assegnamento
    Punto2D &operator[](int indice);            // di indice
    bool operator==(const Poligono2D &p);       // uguaglianza
    friend std::istream &operator>>(std::istream &in, Poligono2D &p);
    friend std::ostream &operator<<(std::ostream &out, Poligono2D &p);

    // metodi

    double perimetro();

private:
    /*
    La classe avrà pertanto i seguenti attributi:
    • il puntatore _p ad un array di oggetti di classe Punto2D
    • il numero _n di punti contenuti nell’array (un numero intero).
    */
    // attributi
    Punto2D *_p;
    int _n;
};

#endif