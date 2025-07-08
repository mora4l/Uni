/*
acquisisca tre numeri reali dall'utente (cin) e utilizzi i puntatori per
determinare e stampare il valore massimo tra i tre numeri inseriti.
• Il programma deve svolgere le seguenti operazioni:
▫ chiedere all'utente di inserire tre numeri reali,
▫ assegnare i puntatori corrispondenti ai numeri reali,
▫ trovare il massimo tra i tre numeri utilizzando i puntatori,
▫ stampare il valore massimo trovato utilizzando un puntatore.
*/

#include <iostream>
using namespace std;

int main(){

    double uno=0 , due =0 , tre=0 ; 

    cout<<"Inserisci valore"<<endl;
    cin>>uno;

    double *unoo=&uno;

    cout<<endl<<"Inserisci valore"<<endl;
    cin>>due;

    double *duee=&due;

    cout<<endl<<"Inserisci valore"<<endl;
    cin>>tre;

    double *tree=&tre;

    double max=*unoo;

    if(*unoo<*duee){
        max=*duee;
    }
    if(*duee<*tree){
        max=*tree;
    }

    cout<<"Il max è: "<<max<<endl;

    return 0; 
}