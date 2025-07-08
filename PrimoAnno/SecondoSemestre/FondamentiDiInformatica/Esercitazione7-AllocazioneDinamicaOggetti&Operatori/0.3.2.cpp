#include <iostream>
using namespace std;
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

class punto3d
{

public:
    // costruttori
    punto3d();
    punto3d(double x, double y, double z);
    punto3d(punto3d &p);

    // distruttore
    ~punto3d();

    // getter
    double getX();
    double getY();
    double getZ();

    // setter
    void setX(double x);
    void setY(double y);
    void setZ(double z);


    /*
    Forma | Che significa | Chi chiama
    ++a | incrementa e poi usa | operator++()
    a++ | usa e poi incrementa | operator++(int)
    */

    punto3d operator+();

    // funzione amica
    friend double distanza(punto3d &p1, punto3d &p2);

private:
    double _x;
    double _y;
    double _z;
};

/*
• Il costruttore di default che inizializza a zero tutti i attributi,
*/
punto3d::punto3d()
{
    _x = 0;
    _y = 0;
    _z = 0;
}
/*
• Un costruttore con parametri che riceve in ingresso (ovvero come parametri) tre numeri reali che
rappresentano le coordinate x, y e z di un punto 3D e assegna i valori dei parametri attuali ai corrispondenti
attributi della classe
*/
punto3d::punto3d(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
}
/*
• Il costruttore di copia
*/
punto3d::punto3d(punto3d &p)
{
    _x = p._x;
    _y = p._y;
    _z = p._z;
}

/*
• Il distruttore
*/
punto3d::~punto3d()
{
    cout << "sono il distruttore" << endl;
}

/*
• I selettori (un metodo per ciascun attributo)
*/
double punto3d::getX()
{
    return _x;
}
double punto3d::getY()
{
    return _y;
}
double punto3d::getZ()
{
    return _z;
}

/*
• I modificatori (un metodo per ciascun attributo)
*/
void punto3d::setX(double x)
{
    _x = x;
}
void punto3d::setY(double y)
{
    _y = y;
}
void punto3d::setZ(double z)
{
    _z = z;
}

/*
• Un funzione esterna amica per il calcolo della distanza tra due punti.
*/
double distanza(punto3d &p1, punto3d &p2)
{
    double distanza = sqrt(pow(p2._x - p1._x, 2) + pow(p2._y - p1._y, 2) + pow(p2._z - p1._z, 2));
    return distanza;
}
/*
• Gli operatori aritmetici di somma, sottrazione e moltiplicazione per scalare.
*/
punto3d punto3d::operator+(){
    return punto3d(+_x,+_y,+_z);
}
int main(){

    

    return 0 ; 
}