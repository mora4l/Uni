#include <iostream>
#include <cmath>
#include "Punto2D.h"

using namespace std;

Punto2D::Punto2D() : _x(0.0), _y(0.0) {}
Punto2D::Punto2D(double x, double y) : _x(x), _y(y) {}
Punto2D::Punto2D(const Punto2D &p) : _x(p._x), _y(p._y) {}
Punto2D::~Punto2D() {}

double Punto2D::getX() const { return _x; }
double Punto2D::getY() const { return _y; }
void Punto2D::setX(double x) { _x = x; }
void Punto2D::setY(double y) { _y = y; }

Punto2D Punto2D::operator-() const {
    return Punto2D(-getX(), -getY());
}

Punto2D &Punto2D::operator++() {
    setX(getX() + 1.0);
    setY(getY() + 1.0);
    return *this;
}

Punto2D Punto2D::operator++(int) {
    Punto2D temp(*this);
    ++(*this);
    return temp;
}

Punto2D &Punto2D::operator--() {
    setX(getX() - 1.0);
    setY(getY() - 1.0);
    return *this;
}

Punto2D Punto2D::operator--(int) {
    Punto2D temp(*this);
    --(*this);
    return temp;
}

Punto2D Punto2D::operator+(Punto2D p) const {
    return Punto2D(getX() + p.getX(), getY() + p.getY());
}

Punto2D Punto2D::operator-(Punto2D p) const {
    return Punto2D(getX() - p.getX(), getY() - p.getY());
}

Punto2D Punto2D::operator*(double s) const {
    return Punto2D(getX() * s, getY() * s);
}

int Punto2D::operator==(Punto2D p) const {
    return (getX() == p.getX() && getY() == p.getY());
}

const Punto2D &Punto2D::operator=(const Punto2D &p) {
    if (this != &p) {
        _x = p._x;
        _y = p._y;
    }
    return *this;
}

ostream &operator<<(ostream &os, const Punto2D &p) {
    os << "(" << p.getX() << ", " << p.getY() << ")";
    return os;
}

istream &operator>>(istream &is, Punto2D &p) {
    double x, y;
    is >> x >> y;
    p.setX(x);
    p.setY(y);
    return is;
}

double Punto2D::distanza(Punto2D p) const {
    double dx = getX() - p.getX();
    double dy = getY() - p.getY();
    return sqrt(dx * dx + dy * dy);
}
