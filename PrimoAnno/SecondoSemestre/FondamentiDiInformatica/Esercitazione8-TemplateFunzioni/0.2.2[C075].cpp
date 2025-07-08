/*
Crea una classe Persona (con degli attributi: nome, cognome, codice
fiscale, età, gender)


*/
#include <iostream>
using namespace std;
template <typename T>
class Tripla
{

public:
    // costruttore
    Tripla(T uno, T due, T tre); // default

    // metodi
    T trovaMassimo();
    T trovaMinimo();
    void ordina();
    void stampaTripla();
    void inserisciValori();

private:
    T _uno;
    T _due;
    T _tre;
};
/*
▫ Un costruttore che permetta di inizializzare la tripla con tre valori dello stesso
tipo.
*/
template <typename T>
Tripla<T>::Tripla(T uno, T due, T tre)
{
    _uno = uno;
    _due = due;
    _tre = tre;
}

/*
▫ Un metodo `trovaMassimo()` che restituisca il valore massimo tra i tre elementi
della tripla.
*/
template <typename T>
T Tripla<T>::trovaMassimo()
{

    T max = _uno;
    if (_due > max)
    {
        max = _due;
    }
    if (_tre > max)
    {
        max = _tre;
    }
    return max;
}

/*
▫ Un metodo `trovaMinimo()` che restituisca il valore minimo tra i tre elementi
della tripla.
*/
template <typename T>
T Tripla<T>::trovaMinimo()
{

    T min = _uno;
    if (_due < min)
    {
        min = _due;
    }
    if (_tre < min)
    {
        min = _tre;
    }
    return min;
}

/*
▫ Un metodo `ordina()` che ordini i tre elementi della tripla in ordine crescente.
*/
template <typename T>
void Tripla<T>::ordina()
{
    T temp;

    if (_uno > _due)
    {
        temp = _uno;
        _uno = _due;
        _due = temp;
    }
    if (_uno > _tre)
    {
        temp = _uno;
        _uno = _tre;
        _tre = temp;
    }
    if (_due > _tre)
    {
        temp = _due;
        _due = _tre;
        _tre = temp;
    }
}

/*
▫ Un metodo stampaTripla() che stampa i valori di 3 elementi.
*/
template <typename T>
void Tripla<T>::stampaTripla()
{

    cout << _uno << _due << _tre << endl;
}

// faccio un metodo per inserire i dati
template <typename T>
void Tripla<T>::inserisciValori()
{
    cout << endl
         << "inserisci valori della tripla:" << endl;
    cin >> _uno >> _due >> _tre;
}

template <typename T, typename S, typename P>
class Persona
{

public:
    Persona();
    T getEta();
    void setEta(S eta);

    /*
    ▫ sovraccarica gli operatori necessari per poter svolgere le operazioni su una
    tripla di persone (come trovare massimo, minimo etc), utilizza l’attributo
    età per fare il confronto fra due persone
    */
    bool operator>(const Persona &p) const
    {
        return _eta > p._eta;
    }
    bool operator<(const Persona &p) const
    {
        return _eta < p._eta;
    }
    bool operator==(const Persona &p) const
    {
        return _eta == p._eta;
    }

    void inserisciValori()
    {
        cout << endl
             << "inserisci eta:" << endl;
        cin >> _eta;
    }
    friend std::ostream &operator<<(std::ostream &os, const Persona &p)
    {
        os << p._nome << " (" << p._eta << " anni)";
        return os;
    }

private:
    T _nome;
    T _cognome;
    T _cf;
    S _eta;
    P _gender;
};
template <typename T, typename S, typename P>
Persona<T, S, P>::Persona()
{
    T _nome = "";
    T _cognome = "";
    T _cf = "";
    S _eta = 0;
    P _gender = false;
}
template <typename T, typename S, typename P>
T Persona<T, S, P>::getEta()
{
    return _eta;
}

/*
• I modificatori (un metodo per ciascun attributo)
*/
template <typename T, typename S, typename P>
void Persona<T, S, P>::setEta(S eta)
{
    _eta = eta;
}

/* Nel main:
▫ utilizza il template creato in C072
▫ creara una tripla di persone
▫ ordina una tripla di persone */
int main()
{

    Persona<string, int, bool> p1, p2, p3;
    p1.inserisciValori();
    p2.inserisciValori();
    p3.inserisciValori();
    Tripla<Persona<string, int, bool>> t(p1, p2, p3);

    cout << "tripla start:" << endl;
    t.stampaTripla();

    cout << "tripla ordinata:" << endl;
    t.ordina();
    t.stampaTripla();

    return 0;
}