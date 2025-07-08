#include <iostream>
#include <cmath>
#include "Node.h"
using namespace std;
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
