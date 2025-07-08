/*
Il programma deve svolgere le seguenti operazioni:
▫ chiedere all'utente di inserire tre numeri reali,
▫ assegnare i puntatori corrispondenti ai numeri reali,
▫ creare un puntatore a puntatore per memorizzare l’indirizzo di un
puntatore al valore massimo.
▫ utilizzare questo puntatore a puntatore per trovare il massimo tra i tre
numeri,
▫ stampare il valore massimo trovato utilizzando un puntatore a puntatore
*/

#include <iostream>
using namespace std;

int main(){

    double uno=0,due=0,tre=0;

    cout<<"inserisci tre valori"<<endl;

    cin>>uno>>due>>tre;

    double *unoo=&uno,*duee=&due,*tree=&tre;





    double max=0;


    double *maxx=&max;

    double **pp=&maxx;

    if(*unoo<*duee){
        max=*duee;
    }
    if(*duee<*tree){
        max=*tree;
    }

    cout<<"il valore massimo è: "<<**pp<<endl;

    cout<<"(max)"<<max<<"->"<<"(maxx*)"<<*maxx<<"->(pp**)"<<**pp<<endl;  
    return 0;
}