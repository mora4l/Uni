/*
Scrivere un programma in C++ che richieda all'utente di inserire tre
lettere, e utilizzi i puntatori per determinare e stampare la lettera che
viene prima nell'ordine alfabetico.
• Il programma inizia chiedendo all'utente di inserire tre lettere.
Successivamente, utilizzando i puntatori a variabili di tipo char,
confronta le lettere per determinare quella che appare prima nell'ordine
alfabetico (secondo la codifica ASCII). Alla fine, il programma stampa la
lettera che viene prima.
*/

#include <iostream>
#include <cctype>
using namespace std;

int main(){

    char uno,due,tre; 

    cout<<"inserisci tre lettere minuscole: "<<endl;
    cin>>uno>>due>>tre;
    uno=tolower(uno);
    due=tolower(due);
    tre=tolower(tre);

    char *unoo=&uno,*duee=&due,*tree=&tre;

/*     int numUno= 'a'-uno;
    int numDue= 'a'-due;
    int numTre= 'a'-tre;

    int *numUnoo=&numUno;
    int *numDuee=&numDue;
    int *numTree=&numTre; */
    char min=*unoo;

    if(*duee<min){
        min=*duee;
    }
    if(*tree<min){
        min=*tree;
    }



    cout<<"Il char che appare prima è :"<<min<<endl;

    return 0; 
}