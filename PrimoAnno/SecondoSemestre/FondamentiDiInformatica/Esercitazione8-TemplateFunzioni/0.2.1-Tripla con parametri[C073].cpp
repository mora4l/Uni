/*
Implementa una classe template chiamata `Tripla` che rappresenti una tripla
di elementi dello stesso tipo. La classe deve fornire le seguenti funzionalità:
*/
#include <iostream>
using namespace std;
template <typename T>
class Tripla
{

public:
    // costruttore
    Tripla(); // default

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
Tripla<T>::Tripla()
{
    _uno = 0;
    _due = 0;
    _tre = 0;
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
    if (_due > _tre)
    {
        temp = _due;
        _due = _tre;
        _tre = temp;
    }
    if (_uno > _tre)
    {
        temp = _uno;
        _uno = _tre;
        _tre = temp;
    }
}

/*
▫ Un metodo stampaTripla() che stampa i valori di 3 elementi.
*/
template <typename T>
void Tripla<T>::stampaTripla()
{

    cout << _uno << _due << _tre;
}

// faccio un metodo per inserire i dati
template <typename T>
void Tripla<T>::inserisciValori()
{
    cout << endl
         << "inserisci valori della tripla:" << endl;
    cin >> _uno >> _due >> _tre;
}
/*
• Infine, scrivi un programma principale per testare la classe `Tripla` con
almeno due tipi semplici di dati diversi.
*/

int main()
{
    cout << "quante triple vuoi" << endl;
    int n = 0;
    cin >> n;

    Tripla<int> *Y = new Tripla<int>[n];
    cout << "con int" << endl;
    for (int i = 0; i < n; i++)
    {
        Y[i].inserisciValori();
        cout << "il massimo è:" << Y[i].trovaMassimo() << endl;
        cout << "il minimo è:" << Y[i].trovaMinimo() << endl;
        Y[i].stampaTripla();
    }
    delete[] Y;

    Tripla<double> *X = new Tripla<double>[n];
    cout << "ora con double" << endl;
    for (int i = 0; i < n; i++)
    {
        X[i].inserisciValori();
        cout << "il massimo è:" << X[i].trovaMassimo() << endl;
        cout << "il minimo è:" << X[i].trovaMinimo() << endl;
        X[i].stampaTripla();
    }
    delete[] X;

    return 0;
}
