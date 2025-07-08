
#include <iostream>
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

    // operatori
    // prefissi
    punto3d operator-();
    punto3d &operator++();
    punto3d &operator--();

    // postfissi
    punto3d operator++(int);
    punto3d operator--(int);
    /*
    Forma | Che significa | Chi chiama
    ++a | incrementa e poi usa | operator++()
    a++ | usa e poi incrementa | operator++(int)
    */

    // operatori aritmetici
    punto3d operator+(double z);
    punto3d operator+(punto3d &p);
    punto3d operator-(double z);
    punto3d operator-(punto3d &p);
    punto3d operator*(double z);
    punto3d operator*(punto3d &p);

    // operatori di assegnamento
    const punto3d &operator=(const punto3d &p);

    // operatore relazionale di uguaglianza
    bool operator==(const punto3d &p) const;

    // operatore di inserimento<<
    friend std::ostream &operator<<(std::ostream &out, const punto3d &p);
    friend std::istream &operator>>(std::istream &in, punto3d &p);

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
• L’operatore unario di cambio di segno, per calcolare l’opposto di un punto 3D.
*/
punto3d punto3d::operator-()
{
    return punto3d(-_x, -_y, -_z);
}

/*
• Gli operatori unari di incremento e decremento unitario prefisso e postfisso.
*/
// prefisso
punto3d& punto3d::operator++() { // Incremento prefisso
    _x++;
    _y++;
    _z++;
    return *this;
}

punto3d punto3d::operator++(int) { // Incremento postfisso
    punto3d temp(*this);
    ++(*this);
    return temp;
}

punto3d& punto3d::operator--() { // Decremento prefisso
    _x--;
    _y--;
    _z--;
    return *this;
}

punto3d punto3d::operator--(int) { // Decremento postfisso
    punto3d temp(*this);
    --(*this);
    return temp;
}
/*
• Gli operatori aritmetici di somma, sottrazione e moltiplicazione per scalare.
*/
punto3d punto3d::operator+(double z)
{
    return punto3d(_x + z, _y + z, _z + z);
}
punto3d punto3d::operator+(punto3d &p)
{
    return punto3d(_x + p._x, _y + p._y, _z + p._z);
}

punto3d punto3d::operator-(double z)
{
    return punto3d(_x - z, _y - z, _z - z);
}
punto3d punto3d::operator-(punto3d &p)
{
    return punto3d(_x - p._x, _y - p._y, _z - p._z);
}

punto3d punto3d::operator*(double z)
{
    return punto3d(_x * z, _y * z, _z * z);
}
punto3d punto3d::operator*(punto3d &p)
{
    return punto3d(_x * p._x, _y * p._y, _z * p._z);
}

/*
• L’operatore di assegnamento.
*/
const punto3d &punto3d::operator=(const punto3d &p)
{
    if (this != &p)
    {
        _x = p._x;
        _y = p._y;
        _z = p._z;
    }
    return *this;
}

/*
• L’operatore relazionale di uguaglianza ==, per il quale due punti 3D sono uguali se hanno le stesse coordinate.
*/
bool punto3d::operator==(const punto3d &p) const
{
    return (_x == p._x) && (_y == p._y) && (_z == p._z);
}

/*
• Gli operatori di inserimento ed estrazione.
*/
std::istream &operator>>(std::istream &in, punto3d &p)
{
    cout << "Inserisci i valori per il punto3d (x, y, z): " << endl;
    in >> p._x >> p._y >> p._z; // Modifica i membri dell'oggetto
    return in;
}
std::ostream & /*questo è il tipo di ritorno della funzione (un output)*/ operator<< /*questo è il nome della funzione*/ (std::ostream & out /*<- questo è il flusso di output su cui voglio scrivere*/, const punto3d & p /*oggetto*/)
{
    cout << "punti" << endl;
    cout << p._x << "," << p._y << "," << p._z << endl;
    return out; // devi ritornare qualcosa
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

Si scriva quindi un programma C++ per verificare il corretto funzionamento della classe sviluppata.
Il programma dichiarerà due oggetti di classe punto3d, chiederà all’utente di immettere da tastiera i valori
delle coordinate dei due punti utilizzando l’operatore di inserimento, stamperà a video le coordinate
immesse utilizzando l’operatore di estrazione e calcolerà e stamperà a video la somma, la differenza, e la
distanza tra i due punti.
*/

int main()
{

    punto3d p1;
    punto3d p2;
    cout << "inserisci valori p1" << endl;
    cin >> p1;
    cout << "inserisci valori p2" << endl;

    cin >> p2;

    cout << "risultati" << endl;

    cout << p1;
    cout << p2;

    punto3d p3 = p1 + p2;

    cout << "la somma è:" << endl;
    cout << p3;

    cout << "la differenza è:" << endl;
    punto3d p4 = p1 - p2;
    cout << p4;

    double dist = distanza(p1, p2);

    cout << "distanza:" << dist << endl;

    return 0;
}