/*
Si scriva la funzione C++ massimo che riceva come parametri i puntatori a tre numeri interi a, b e c e restituisca
come valore di ritorno il puntatore al più grande dei tre numeri (un puntatore a numero intero).
• Nel caso in cui vi siano due numeri uguali, entrambi più grandi del terzo numero, la funzione restituisce il
puntatore al primo dei due.
• Si scriva quindi un programma C++ per verificare il corretto funzionamento della funzione.
• Il programma chiederà all’utente di immettere da tastiera tre numeri interi, chiamerà la funzione massimo e
stamperà a video il valore puntato dal puntatore che la funzione restituisce come valore di ritorno.
▫ Esempio: se a vale 3, b vale 10 e c vale 5, la funzione restituirà come valore di ritorno il puntatore a b e il programma
stamperà a video 10.
*/

#include <iostream>
using namespace std;

 int* massimo(int *a,int *b,int *c){
    int *max=a;
    if(*b>*max){
        max=b;
    }else if(*c>*max){
        max=c; 
    }

    if((a>c)&&(b>c)){
        *max=*a;
    }
    
        return max;
} 

int main(){

    int uno=0,due=0,tre=0;
    cout<<"Inserisci i valori negro :"<<endl;
    cin>>uno>>due>>tre;

    int *unoo=&uno;
    int *duee=&due;
    int *tree=&tre;

    int *ris=massimo(unoo,duee,tree);

    cout<<"Il valore massimo è: "<<*ris<<endl;;
    return 0;
}