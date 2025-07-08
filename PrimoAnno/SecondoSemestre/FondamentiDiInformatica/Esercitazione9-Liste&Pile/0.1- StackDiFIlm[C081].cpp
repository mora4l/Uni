#include <iostream>
#include <cstring>

using namespace std;

class Film
{
private:
    char *_titolo;
    int _durata;
    int _anno;

public:
    Film();
    Film(const char *titolo, int durata, int anno);
    Film(const Film &f);

    ~Film();

    char *get_titolo() const;
    int get_anno() const;
    int get_durata() const;

    void set_titolo(const char *titolo);
    void set_anno(const int anno);
    void set_durata(const int durata);

    void stampaFilm();

    bool operator==(const Film &f1) const;

    friend ostream &operator<<(ostream &os, const Film &f);
    friend istream &operator>>(istream &is, Film &f);
};

Film::Film()
{
    _titolo = new char[20];
    strcpy(_titolo, "N/D");
    _durata = 0;
    _anno = 0;
}

Film::Film(const char *titolo, int durata, int anno)
{
    _titolo = new char[strlen(titolo) + 1];
    strcpy(_titolo, titolo);
    _durata = durata;
    _anno = anno;
}

Film::Film(const Film &f)
{
    _titolo = new char[strlen(f._titolo) + 1];
    strcpy(_titolo, f._titolo);
    _durata = f._durata;
    _anno = f._anno;
}

Film::~Film()
{
    delete[] _titolo;
}

char *Film::get_titolo() const
{
    return _titolo;
}

int Film::get_anno() const
{
    return _anno;
}

int Film::get_durata() const
{
    return _durata;
}

void Film::set_titolo(const char *titolo)
{
    delete[] titolo;
    _titolo = new char[strlen(titolo) + 1];
    strcpy(_titolo, titolo);
}

void Film::set_anno(const int anno)
{
    _anno = anno;
}
void Film::set_durata(const int durata)
{
    _durata = durata;
}

void Film::stampaFilm()
{
    cout << "stampa del film" << endl;
    cout << "titolo:" << _titolo << " , durata:" << _durata << " , anno:" << _anno << endl;
}

bool Film::operator==(const Film &f1) const
{
    return (strcmp(this->get_titolo(), f1.get_titolo()) == 0 &
                this->get_durata() == f1.get_durata() &&
            this->get_anno() == f1.get_anno());
};
// classe default node
template <typename T>
class Node
{
public:
    // costruttori
    Node(const T &data, Node<T> *next); // con parametri
    Node(const Node<T> &node);
    ~Node(); // distruttori
    // selettori
    const T &getData() const;
    Node<T> *getNext() const;
    // modificatori
    void setData(const T &data);
    void setNext(Node<T> *next);

private:
    Node(); // costruttore default (privato poiche non puoi creare un nodo senza dati dall'esterno)
    T _data;
    Node<T> *_next;
};

/*
costruttore default
*/
template <typename T>
Node<T>::Node() : _data(), _next(0) {}

/*
costruttore con parametri
*/
template <typename T>
Node<T>::Node(const T &data, Node<T> *next)
    : _data(data), _next(next) {}

// costruttore di copia
template <typename T>
Node<T>::Node(const Node<T> &node)
    : _data(node._data), _next(node._next) {}

// distruttore
template <typename T>
Node<T>::~Node() {}
// selettori (getter) restituisce il dato
template <typename T>
inline const T &Node<T>::getData() const
{
    return _data;
}

// selettore (getter) restituisce il puntatore al nodo successivo
template <typename T>
inline Node<T> *Node<T>::getNext() const
{
    return _next;
}

// modificatore (setter) imposta un nuovo valore
template <typename T>
void Node<T>::setData(const T &data)
{
    _data = data;
}

// modificatore (setter) imposta il nodo successivo
template <typename T>
void Node<T>::setNext(Node<T> *next)
{
    _next = next;
}

////////////////////////////////////////////////////////////////////////////

template <typename T>
class Stack
{
private:
    Node<T> *_head; // in questo caso , il tipo di struttura 'stack' ha un attributo di tipo puntatore all 'elemento in cima della struttura dati poiche in questa struttura si lavora sull elemento piu in cima. infatti il puntatore è di tipo node , poiche è legato ad un oggetto della classe nodee
    int _numItems;  // e infine ha un attributo che descrive il numero di oggetti che ha la struttura (cioe il numero di nodi (cioe oggetti), che vengono pero creati dalla classe node)

public:
    // costruttori e distruttore
    Stack();
    Stack(const Stack<T> &s);
    ~Stack();
    // selettori per gli attributi
    int isEmpty() const;
    int numItems() const;
    // operazioni
    void push(const T &data);
    void pop();
    Node<T> *getHead() const;
    void clear();
};

template <typename T>
Stack<T>::Stack() : _head(NULL), _numItems(0) {}

template <typename T>
Stack<T>::Stack(const Stack<T> &s) : _head(nullptr), _numItems(0)
{
    Node<T> *temp = s._head;
    while (temp != nullptr)
    {
        push(temp->data);
        temp = temp->next;
    }
}

template <typename T>
Stack<T>::~Stack()
{
    clear();
}

template <typename T>
int Stack<T>::isEmpty() const
{
    return _head == nullptr;
}

template <typename T>
int Stack<T>::numItems() const
{
    return _numItems;
}

template <typename T>
void Stack<T>::push(const T &data)
{
    Node<T> *newNode = new Node<T>(data, _head);
    _head = newNode;
    _numItems++;
}

template <typename T>
void Stack<T>::pop()
{
    if (_head != nullptr)
    {
        Node<T> *temp = _head;
        _head = _head->getNext();
        delete temp;
        _numItems--;
    }
}

template <typename T>
Node<T> *Stack<T>::getHead() const
{
    return _head;
}

template <typename T>
void Stack<T>::clear()
{
    while (!isEmpty())
        pop();
}

ostream &operator<<(ostream &os, const Film &f)
{
    os << "Titolo: " << f.get_titolo() << ", Durata: " << f.get_durata() << " minuti, Anno: " << f.get_anno();
    return os;
}

istream &operator>>(istream &is, Film &f)
{
    char temp[100];
    is >> temp;
    f._titolo = new char[strlen(temp) + 1];
    strcpy(f._titolo, temp);
    is >> f._durata >> f._anno;
    return is;
}

int main()
{

    Stack<Film> filmazzo;

    filmazzo.push(Film("dema", 120, 100));
    filmazzo.push(Film("demaaaaa", 120, 124));
    filmazzo.push(Film("meya", 32, 1340));

    while (!filmazzo.isEmpty())
    {
        Film f1 = filmazzo.getHead()->getData();
        cout << f1 << endl;
        filmazzo.pop();
    }
    cout << "non ci sono elementi" << endl;

    filmazzo.clear();

    return 0;
}