/*
Scrivere un programma in C++ che riceva in input una sequenza di numeri interi positivi e si interrompa quando l’utente digita zero.
Il programma seleziona fra i numeri i multipli di un valore k>=2 anche esso ricevuto in input e
memorizza i numeri scelti in un file di testo di nome “multipli.txt”. 
Il programma termina se il numero k detto “divisore” è inferiore a 2.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int num=2,multiplo=0;
    fstream file;
    file.open("multipli.txt",ios::out);
    
    if(!file){
        cout<<"File inesistente";
        return 1;
    }

    cout<<"Dimmi il valore k da cui cercare i suoi multipli (>=2):"<<endl;
    cin>>multiplo;

    if(multiplo < 2){
        return 1;

    }

    while(num!=0){
        cout<<"Inserisci un altro numero :"<<endl;
        cin>>num;

        if(num%2==0){
            file<< " "<<num;
        }

    }

    
    return 0;
}