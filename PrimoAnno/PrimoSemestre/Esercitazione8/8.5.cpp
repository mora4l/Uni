/*
Alcuni sensori di temperatura scrivono le loro misure (dei numeri reali) su file il cui nome è la località in cui sono installati (ad esempio "genova.txt").
Il numero di misure trascritte è diverso per ciascun file e non è noto al programmatore.
Si scriva un programma in linguaggio C++ che chieda all’utente di immettere da tastiera
il nome del file che desidera analizzare, apra il file indicato, lo scandisca e stampi a video la temperatura massima e minima registrata dal sensore corrispondente.
Se il file non esiste, il programma chiede all’utente di immettere di nuovo il nome del file.
L’utente può ripetere le operazioni quante volte desidera e può uscire dal programma digitando la parola "exit", anziché il nome di un file.
Prima di terminare, il programma stampa a video il numero di file non vuoti elaborati. Si supponga che i valori contenuti nei file siano validi.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){

    fstream file;
    string nomefile,esci="exit";
    bool huf=1;
    
    do{
    cout<<"nome file"<<endl;
    cin>>nomefile;
    file.open(nomefile,ios::in);
    huf=0;
    if(!file){
        cout<<"riprova";
        huf = 1;
    }


    }while(nomefile!=esci && huf==1);


    int temp=0,max=0,min=0;

    file>>temp;
    max,min=temp;
    while(!file.eof()){

        if(temp>max){
            max=temp;
        }
        if(temp<min){
            min=temp;
        }
        

        file>>temp;
    }

    cout<<"max "<<max<<", min "<<min<<endl;

    return 0;
}