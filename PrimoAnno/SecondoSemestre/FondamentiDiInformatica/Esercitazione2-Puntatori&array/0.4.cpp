/*
Si scriva la funzione C++ swap che riceva come parametri i puntatori a tre numeri interi a, b e c e ne ruoti i valori,
ovvero: a b viene assegnato il valore di a, a c viene assegnato il valore di b e ad a viene assegnato il valore di c.
• Si scriva quindi un programma C++ per verificare il corretto funzionamento della funzione.
• Il programma chiederà all’utente di immettere da tastiera tre numeri interi, chiamerà la funzione swap per
ruotarne i valori e stamperà a video il risultato.
• Esempio: se a vale 3, b vale 5 e c vale 10, dopo la chiamata alla funzione si avrà che a varrà 10,
b varrà 3 e c varrà 5
*/
#include <iostream>
using namespace std; 

void swap(int *a,int *b, int *c){

int *temp= b; 
int *temp2=c;
b=a;

c=temp;

a=temp2; 

cout<<*a<<endl<<*b<<endl<<*c<<endl;
}
/*
Se non si volessero utilizzare i puntatori come si potrebbe re-implementare la funzione? 
• Per verificarlo, scrivete una funzione swap_2 che scambi i valori senza usare i puntatori e utilizzatela nel
programma sviluppato.
• Confrontate il codice dell’implementazione con i puntatori e di quella senza i puntatori. In che cosa si
differenziano?
*/
void swap_2(int &uno,int &due,int &tre){
    int temp=uno;

    uno=tre;
    tre=due;
    due=temp;

    cout<<uno<<due<<tre<<endl;
}
int main(){
int uno=0,due=0,tre=0;
int *unoo=&uno,*duee=&due,*tree=&tre;

cout<<"inserisci tre valori"<<endl;
cin>>uno>>due>>tre;
swap(unoo,duee,tree);
swap_2(uno,due,tre);
    return 0; 
}

