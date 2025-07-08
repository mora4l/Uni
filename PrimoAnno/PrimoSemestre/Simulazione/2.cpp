/*
Allo scopo di analizzare in modo automatico le risposte a un quiz di tipo “Vero o Falso”, 
si consideri la matrice Q di numeri interi, avente 30 righe e 11 colonne. 

La prima colonna della matrice Q rappresenta le risposte corrette alle 30 domande del quiz (dove 0 significa “Falso” e 1 significa “Vero”), 
le successive 10 colonne rappresentano le risposte date da 10 partecipanti. 

Si sviluppi in linguaggio C++ 

ATTENZIONE: è possibile inserire il codice qui sotto OPPURE inviare un file di testo contenente il codice sorgente.
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#define R 30
#define C 11
#define ASSEGNAZIONI 1000
using namespace std;
/*
la 
funzione primo_classificato che riceva come parametro d’ingresso la matrice Q e
restituisca come parametri di uscita due numeri interi che rappresentano l’indice del partecipante che ha ottenuto il punteggio più alto e tale punteggio. 
Il punteggio è calcolato come il numero di risposte corrette. 
Nel caso in cui più di un partecipante ottenga lo stesso punteggio massimo, si considera il partecipante con indice di colonna più piccolo. 
Per semplicità, si assuma che i valori contenuti nella matrice Q siano validi. 
La funzione non restituisce alcun valore di ritorno.
*/

void primo_classificato(int &indiceHigh, int &punteggioHigh,int Q[R][C]){
    int punteggiocorrente=Q[0][0];
for(int i = 0 ;i<R;i++){

if(punteggiocorrente<Q[i][0]){

    punteggioHigh=Q[i][0];
    indiceHigh=i;

}else if(punteggiocorrente==Q[i][0]){
    if(indiceHigh>i){
        break;
    }
}
}
}
int main(){
/*
Si scriva quindi un programma C++ che operi come segue: 

Definisca una matrice M di 30 righe e 11 colonne. 

Per 1000 volte assegni a ciascun elemento della matrice il valore 0 oppure il valore 1 scelti in modo casuale, 

chiami la funzione primo_classificato passando come parametri attuali la matrice M e due numeri interi n e p e 

calcoli la somma dei punteggi via via ottenuti.

Stampi a video la media dei punteggi ottenuti e termini.

Nota: per generare un numero casuale che valga 0 oppure 1 si può usare, ad esempio, l'espressione rand() % 2. Per utilizzare la funzione rand() occorre importare le libererie cstdlib e ctime, inizializzando il processo di generazione dei numeri casuali con srand(time(0));

*/
srand(time(0));
int M[R][C],n=0 ,p=0;
for(int i =0 ; i<ASSEGNAZIONI;i++){

for(int i = 0 ; i<R;i++){
    for(int j =0 ; j<C;j++){
M[i][j]=rand()%2;
}
}
}

primo_classificato(n,p,M);

cout<<"ha vinto il numero "<<n<< " con "<<p<<" punti"<<endl;
    return 0;
}