/*
Sviluppare in linguaggio C++ un programma che chieda all’utente di inserire cinque numeri 
interi e ne stampi a terminale la media (approssimandola ad un numero intero)
*/
#include <iostream>
using namespace std;

int main() {

    int numeri[6];
    int media =0;

    for(int i=0;i<5;i++){
        cout<<"inserisci un numero:";
        cin>> numeri[i];

    }
    for(int i =0;i<5;i++){
        media+=numeri[i];

    }
    media=media/5;
    cout<< "La media è:";
    cout<< media;

  return 0;
} 