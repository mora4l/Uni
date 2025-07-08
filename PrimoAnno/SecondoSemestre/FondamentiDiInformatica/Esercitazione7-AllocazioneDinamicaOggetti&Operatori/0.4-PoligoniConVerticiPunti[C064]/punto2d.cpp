#include "punto2d.h"

#include <iostream>
using namespace std;
#include <cmath>
/////////////////////////////////////////////////////////////////////
// Costruttori della classe punto2d
/////////////////////////////////////////////////////////////////////

punto2d::punto2d()
    : _x(0.0), _y(0.0)
{
}

punto2d::punto2d(double x, double y)
    : _x(x), _y(y)
{
}

punto2d::punto2d(const punto2d &p)
    : _x(p._x), _y(p._y)
{
}

/////////////////////////////////////////////////////////////////////
// Distruttore della classe punto2d
/////////////////////////////////////////////////////////////////////

punto2d::~punto2d()
{
}

/////////////////////////////////////////////////////////////////////
// Selettori della classe punto2d
/////////////////////////////////////////////////////////////////////

double punto2d::getX() const
{
    return _x;
}

double punto2d::getY() const
{
    return _y;
}

/////////////////////////////////////////////////////////////////////
// Modificatori della classe punto2d
/////////////////////////////////////////////////////////////////////

void punto2d::setX(double x)
{
    _x = x;
}

void punto2d::setY(double y)
{
    _y = y;
}

/////////////////////////////////////////////////////////////////////
// Operatori sovraccaricati della classe punto2d
/////////////////////////////////////////////////////////////////////

punto2d punto2d::operator-() const
{
    return punto2d(-getX(), -getY());
}

punto2d &punto2d::operator++()
{
    setX(getX() + 1.0);
    setY(getY() + 1.0);
    return *this;
}

punto2d punto2d::operator++(int)
{
    punto2d temp(*this);
    setX(getX() + 1.0);
    setY(getY() + 1.0);
    return temp;
}

punto2d &punto2d::operator--()
{
    setX(getX() - 1.0);
    setY(getY() - 1.0);
    return *this;
}

punto2d punto2d::operator--(int)
{
    punto2d temp(*this);
    setX(getX() - 1.0);
    setY(getY() - 1.0);
    return temp;
}

punto2d punto2d::operator+(punto2d p) const
{
    return punto2d(getX() + p.getX(), getY() + p.getY());
}

punto2d punto2d::operator-(punto2d p) const
{
    return punto2d(getX() - p.getX(), getY() - p.getY());
}

punto2d punto2d::operator*(double s) const
{
    return punto2d(s * getX(), s * getY());
}

int punto2d::operator==(punto2d p) const
{
    return (getX() == p.getX() && getY() == p.getY());
}

const punto2d &punto2d::operator=(const punto2d &p)
{
    if (&p != this)
    {
        setX(p.getX());
        setY(p.getY());
    }
    return *this;
}

ostream &operator<<(ostream &os, const punto2d &p)
{
    os << "(" << p.getX() << "," << p.getY() << ")";
    return os;
}

istream &operator>>(istream &is, punto2d &p)
{
    double x = 0.0;
    double y = 0.0;
    is >> x >> y;
    p.setX(x);
    p.setY(y);
    return is;
}

double punto2d::distanza(punto2d p) const
{
    double deltaX = getX() - p.getX();
    double deltaY = getY() - p.getY();
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}
