#include <iostream>
#include <math.h>
using namespace std;
/*
Sviluppare in linguaggio C++ un programma che chieda all’utente di immettere la lunghezza
(intera) di due cateti di un triangolo rettangolo e stampi a terminale il quadrato dell’ipotenusa*/

int main(){
    int cateti[3];
    int ipotenusa=0;

    for (int i=0;i<2;i++){
        cout << "inserisci il cateto "<<i<<" :";

        cin>> cateti[i];

    }
    for(int i =0;i<2;i++){

    ipotenusa += cateti[i]*cateti[i];
    }
    cout<< "Il quadrato dell'ipotenusa è : ";
    cout<<sqrt(ipotenusa) <<"\n";
    return 0;
}