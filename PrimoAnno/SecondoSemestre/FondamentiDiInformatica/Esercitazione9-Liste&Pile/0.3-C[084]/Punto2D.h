#ifndef PUNTO2D_H
#define PUNTO2D_H

#include <iostream>
using namespace std;

class Punto2D
{
public:
    // Costruttori
    Punto2D();
    Punto2D(double x, double y);
    Punto2D(const Punto2D &p);

    // Distruttore
    ~Punto2D();

    // Selettori
    double getX() const;
    double getY() const;

    // Modificatori
    void setX(double x);
    void setY(double y);

    // Operatori sovraccaricati
    Punto2D operator-() const;
    Punto2D &operator++();
    Punto2D operator++(int);
    Punto2D &operator--();
    Punto2D operator--(int);
    Punto2D operator+(Punto2D p) const;
    Punto2D operator-(Punto2D p) const;
    Punto2D operator*(double s) const;
    int operator==(Punto2D p) const;
    const Punto2D &operator=(const Punto2D &p);
    friend ostream &operator<<(ostream &os, const Punto2D &p);
    friend istream &operator>>(istream &is, Punto2D &p);

    // Operazioni
    double distanza(Punto2D p) const;

private:
    double _x;
    double _y;
};

#endif
