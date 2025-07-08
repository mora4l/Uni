#ifndef POLIGONO2D_H
#define POLIGONO2D_H
#include "punto2d.h"
#include <iostream>
using namespace std;

class poligono2d
{
public:
    // costruttori
    poligono2d();
    poligono2d(int dim);
    poligono2d(punto2d pti[], int dim);
    poligono2d(poligono2d &p);

    // getter (selettori)
    punto2d *getPunto();
    int getN();
    void setArray(punto2d pti[], int dim);

    // operatori
    poligono2d operator*(double scalare);       // scalare
    poligono2d &operator=(const poligono2d &p); // di assegnamento
    punto2d &operator[](int indice);            // di indice
    bool operator==(const poligono2d &p);       // uguaglianza
    friend std::istream &operator>>(std::istream &in, poligono2d &p);
    friend std::ostream &operator<<(std::ostream &out, poligono2d &p);

    // metodi

    double perimetro();

private:
    /*
    La classe avrà pertanto i seguenti attributi:
    • il puntatore _p ad un array di oggetti di classe punto2d
    • il numero _n di punti contenuti nell’array (un numero intero).
    */
    // attributi
    punto2d *_p;
    int _n;
};
#endif 