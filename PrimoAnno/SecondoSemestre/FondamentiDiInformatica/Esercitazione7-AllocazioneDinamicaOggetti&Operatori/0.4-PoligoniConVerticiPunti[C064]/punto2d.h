#ifndef PUNTO2D_H
#define PUNTO2D_H
#include <iostream>
using namespace std;

class punto2d
{

public:
    // Costruttori
    punto2d();
    punto2d(double x, double y);
    punto2d(const punto2d &p);

    // Distruttore
    ~punto2d();

    // Selettori
    double getX() const;
    double getY() const;

    // Modificatori
    void setX(double x);
    void setY(double x);

    // Operatori sovraccaricati
    punto2d operator-() const;
    punto2d &operator++();
    punto2d operator++(int);
    punto2d &operator--();
    punto2d operator--(int);
    punto2d operator+(punto2d p) const;
    punto2d operator-(punto2d p) const;
    punto2d operator*(double s) const;
    int operator==(punto2d p) const;
    const punto2d &operator=(const punto2d &p);
    friend ostream &operator<<(ostream &os, const punto2d &p);
    friend istream &operator>>(istream &is, punto2d &p);

    // Operazioni
    double distanza(punto2d p) const;

private:
    double _x;
    double _y;
};
#endif