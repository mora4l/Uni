/*
Implementare un programma C++ che utilizza template, puntatori a funzione e puntatori a
template di funzione per eseguire operazioni matematiche su due numeri:
*/

#include <iostream>
using namespace std;
/*definire un template di funzione sum che prende in input due numeri di tipo generico e restituisce
la loro somma*/
template <typename T,typename S>
T sum(T n,S nn){
return n+nn;
}
/*
▫ definire un template di funzione product che prende in input due numeri di tipo generico e
restituisce il loro prodotto
*/
template <typename K, typename F>
K product( K n , F nn){
    return n*nn; 
}
/*
▫ definire un template di funzione executeOperation che prende in input:
 due valori di tipo generico T
 un puntatore a funzione che prende due argomenti dello stesso tipo generico e restituisce un valore dello
stesso tipo,
 la funzione executeOperation restituisce il risultato dell'operazione specificata su quei numeri.
*/
template <typename T>

T executeOperation(T a , T b, T (*pf)(T,T)){
    
return (*pf)(a,b);
}
/*
▫ Nel main, dichiarare due numeri interi e due numeri reali e eseguire le seguenti operazioni
utilizzando executeOperation:
 somma dei due numeri
 prodotto dei due numer
*/
int main(){

    int a=1,b=2;
    double aa=3,bb=4;

    int ris= executeOperation(a,b,sum);
    cout<<ris<<endl;
    int ris2= executeOperation(aa,bb,product);
    cout<<ris2<<endl;


    return 0 ; 
}