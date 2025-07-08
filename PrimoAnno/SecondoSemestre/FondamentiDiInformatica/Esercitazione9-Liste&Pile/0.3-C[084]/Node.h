#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;
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
#endif // DEBUG