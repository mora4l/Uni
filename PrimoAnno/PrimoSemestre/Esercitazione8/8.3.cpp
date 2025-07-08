/*
Si scriva un programma in linguaggio C++ che apra in lettura il file "input.txt" 
e generi come output un file chiamato “output.txt”. 
Il file "input.txt" contiene un testo di lunghezza non nota al programmatore che il programma leggerà carattere per carattere. 

Il file "output.txt" è formato da tante righe quante sono le lettere dell’alfabeto anglosassone (quindi 26 righe) e 
riporta per ciasucna riga una lettera e quante volte tale lettera compare nel file “input.txt”.

Suggerimento: si può definire un array di 26 numeri interi, inizializzandolo a zero. Ogni
volta che si legge un carattere, si incrementa l’elemento dell’array nella posizione
corrispondente (il primo per il carattere ‘a’, il secondo per ‘b’ e così via).
*/

#include <iostream>
#include <fstream>
using namespace std;
#define N 26
int main(){

    fstream fileopen;
    fstream filewrite;
    fileopen.open("input.txt",ios::in);
    filewrite.open("output.txt",ios::out);
    int array['z'-'a'+1];
    char lettere[N*2];
    char c ;
    for(int i=0;i<N;i++){
        array[i]=0;
    }
int i =0;
    while(fileopen.get(c)){
        if((c>='a')&&(c<='z')){
            int posizione= c-'a';
            array[posizione]++;
        }
        if((c>='A')&&(c<='A')){
            int posizione= c-'A';
            array[posizione]++;
        }
        c=lettere[i];
        i++;
    }

    for (int i =0;i<N;i++){
        c='a'+i;
        filewrite<<c <<" : "<< array[i]<<endl;
    }


    fileopen.close();
    filewrite.close();
    return 0;
}