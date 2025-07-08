/*
A) Implementare una classe template Matrice per rappresentare una matrice di elementi generici.
*/
#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
class Matrice
{

public:
    Matrice(int N, int M);

    T getElemento(int N, int M);

    void setElemento(T numero, int N, int M);

    Matrice<T> operator*(T k);

    void stampa();

private:
    int n;
    int m;
    T **matrix;
};
template <typename T>
Matrice<T>::Matrice(int N, int M)
{
    n = N;
    m = M;
    matrix = new T *[n];
    for (int i = 0; i < n; i++)
    {

        matrix[i] = new T[m];
    }
}

/*
▫ Aggiungere alla classe Matrice un metodo getElemento() che restituisce un elemento specifico della matrice
*/
template <typename T>
T Matrice<T>::getElemento(int N, int M)
{

    return matrix[N][M];
}

/*
setElemento() per inserire un elemento,
*/
template <typename T>
void Matrice<T>::setElemento(T numero, int N, int M)
{
    matrix[N][M] = numero;
}

/*
▫ Sovraccaricare il operatore di moltiplicazione per fare una moltiplicazione scalare.
*/
template <typename T>
Matrice<T> Matrice<T>::operator*(T k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = k * matrix[i][j];
        }
    }
    return *this;
}
template <typename T>
void Matrice<T>::stampa()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

/*
B) Definire la classe Pixel che rappresenta un colore nello standard RGB (tre attributi interi).
• Nella funzione main:
▫ creare una matrice di pixel 5x5 e riempirla con colori casuali usando il template creato in punto A)
▫ moltiplicare la matrice di pixel per uno scalare e stampare la matrice risultante
*/

class Pixel
{

public:
    Pixel(int R, int G, int B);

private:
    int r;
    int g;
    int b;
};

Pixel::Pixel(int R, int G, int B)
{
    r = R;
    g = G;
    b = B;
}
/*
Nella funzione main:
▫ creare una matrice di interi 4x4 e riempirla con valori casuali.
▫ moltiplicare la matrice di interi per uno scalare e stampare la matrice risultante.
*/
int main()
{
    Matrice<int> m(4, 4);

    srand(time(NULL));

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int valuerand = 0;
            valuerand = rand() % 100;
            m.setElemento(valuerand, i, j);
        }
    }

    m.operator*(5);

    m.stampa();

    /*
    parte coi pixel
    */

    Matrice<Pixel> mat(5, 5);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            Pixel p(rand() % 254, rand() % 254, rand() % 254);
            mat.setElemento(p, i, j);
        }
    }
    return 0;
}