/*
Si scriva un programma in linguaggio C++ che chieda all’utente di immettere da tastiera
un numero intero per esprimere una durata misurata in secondi e calcoli e stampi a video
la stessa durata espressa in numero di settimane, di giorni, di ore, di minuti e di secondi
.*/

#include <iostream>
using namespace std;

int main(){

    int secondi=0;

    cout << " inserisci i secondi : ";
    cin>> secondi;

    cout << secondi <<" secondi sono "<< secondi/604800 <<" settimane, " << secondi/86400<< " giorni, "<< secondi/3600<< " ore, "<<secondi /60<<" minuti e "<<secondi<<" secondi";
    
    return 0;
}