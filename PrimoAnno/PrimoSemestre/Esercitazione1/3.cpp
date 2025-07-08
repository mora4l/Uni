/*
Sviluppare in linguaggio C++ un programma che chieda all’utente di immettere due numeri
interi, divida il primo numero per il secondo, e stampi a terminale il quoziente e il resto
*/
#include <iostream>
using namespace std;

int main(){

    int numeri[2];
    int quoziente=0,resto=0;

    for (int i =0;i<2;i++){
        cout<< "inserisci il "<<i<< " numero : ";
        cin>> numeri [i];

        if(numeri[i]==0){
            exit(1);
        }


    }
    

        quoziente = numeri [0] / numeri [1];
        resto = numeri[0]&numeri[1];
    

    cout <<"Il quoziente è : "<< quoziente << " e il resto è : "<< resto <<".";



    return 0;
}