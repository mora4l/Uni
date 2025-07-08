/*
Un’agenzia di spedizioni organizza quasi quotidianamente la movimentazione di merci tra due città collegate da una
ferrovia. La merce viene pertanto collocata su di un treno che può essere composto da un massimo di 10 vagoni. 

Per rappresentare i dati relativi a tale attività nel corso di un mese, si può utilizzare una matrice T di numeri reali di 31
righe e 10 colonne, dove le righe rappresentano i giorni di un mese e le colonne i vagoni del treno. 
L’elemento Tij della matrice rappresenta il numero di tonnellate di merce caricata su di uno specifico vagone (il j-esimo vagone) in un
giorno specifico (l’i-esimo giorno). 
Nel caso in cui il treno in un certo giorno fosse composto da meno di 10 vagoni, gli elementi restanti della riga corrispondente della matrice T sono impostati a zero. 
Se in un certo giorno il treno non ha viaggiato, tutti gli elementi della riga corrispondente della matrice T sono impostati a zero (nello stesso modo si
gestiscono i mesi che hanno meno di 31 giorni). 
Per elaborare tali dati, si sviluppi quanto segue in linguaggio C++:
*/

#include <fstream>
#include <iostream>
using namespace std;
#define R 31
#define C 10


double totaleMerce(double M[R][C]){
/*
1. La funzione totaleMerce che riceva come parametro la matrice T sopra descritta e restituisca come valore di
ritorno il numero totale di tonnellate di merce movimentata nel corso del mese (un numero reale). La funzione
calcolerà e restituirà, quindi, la somma dei valori degli elementi della matrice T. Per semplicità si assuma che i
valori assunti dagli elementi della matrice T siano sempre validi.
*/
    double tot=0;

        for(int i = 0;i<R;i++){
        for (int j=0;j<C;j++){
            tot+=M[i][j];
        }
    }

    return tot;
}


int numTreni(double M[R][C]){
/*
2. La funzione numTreni che riceva come parametro la matrice T sopra descritta e restituisca come valore di ritorno
il numero totale di treni che hanno viaggiato nel corso del mese (un numero intero). La funzione calcolerà e
restituirà, quindi, il numero di righe della matrice T che contengono almeno un elemento diverso da zero. Per
semplicità si assuma che i valori assunti dagli elementi della matrice T siano sempre validi.
*/
    int treni =0 ; 

    for (int i =0 ;i<R;i++){
        for (int j=0;j<C;j++){
            if(M[i][j]>0){
                treni ++;
                break;
            }
        }
    }

    return treni;
}


double maxTreno(double M[R][C],int &v,int &g){
/*
3. La funzione maxTreno che riceva come parametro la matrice T sopra descritta, abbia come parametri di uscita
(ovvero per riferimento) due numeri interi v e g e restituisca come valore di ritorno un numero reale. 
La funzione assegna a v il numero di vagoni del treno composto dal maggior numero di vagoni, 
assegna a g l’indice del giorno in cui tale treno ha viaggiato 
e restituisce come valore di ritorno il numero di tonnellate di merce che tale treno ha trasportato. 

Se vi è più di un treno con lo stesso numero massimo di vagoni, la funzione restituisce i dati del treno
che ha viaggiato per primo (ovvero il primo che viene trovato scandendo le righe della matrice T dalla prima
all’ultima). Per semplicità si assuma che i valori assunti dagli elementi della matrice T siano sempre validi.
*/

    double tonnellatetottreno=0,tonn=0;
    v=0;
    g=0;
    int numvagonitreno=0;

    for(int i =0 ; i<R;i++){
        for(int j=0;j<C;j++){

        if(M[i][j]>0){
            numvagonitreno++;
            tonn+=M[i][j];
        }
        

        }
        if(numvagonitreno>v){
            v=numvagonitreno;
            g=i;
            tonnellatetottreno=tonn;
        }
        if(numvagonitreno=v){
            break;
        }
        tonn=0;
    }
    return tonnellatetottreno;
}

int main(){
    /*
    4. Un programma che operi come segue: dichiari e inizializzi a zero una matrice Treni di numeri reali di 31 righe e
10 colonne organizzata come sopra descritto; apra in lettura il file Dati.txt: il file è composto di 31 linee, ciascuna
contenente 10 numeri reali (per semplicità si supponga che il file esista e che il suo contenuto sia sempre valido);
scandisca il file e assegni a ciascun elemento della matrice Treni il corrispondente valore contenuto nel file;
chiami la funzione totaleMerce e stampi a video il suo valore di ritorno; chiami la funzione numTreni e stampi a
video il suo valore di ritorno; chiami la funzione maxTreno e stampi a video il suo valore di ritorno e i valori
assunti dai parametri passati per riferimento dopo la chiamata della funzione.

    */

    double T[R][C]={{0}};
    int v=0,g=0;
    fstream filelettura;

    filelettura.open("DatiTreni.txt",ios::in);

    for(int i = 0;i<R;i++){
        for (int j=0;j<C;j++){
            filelettura>>T[i][j];
        }
    }
    double totalemerce=totaleMerce(T);

    cout<<"Il totale della merce è : "<<totalemerce<<endl;


    int numtrenitotali=numTreni(T);
    
    cout<<"il numero di treni totali questo mese è : "<<numtrenitotali<<endl;

    int maxvagEgg=maxTreno(T,v,g);

    cout<<"Il treno che ha trasportato piu tonnellate è quello che ha viaggiato nel giorno numero "<<g<<", che aveva "<<v<<" vagoni e ha trasportato in tutto "<<maxvagEgg<<" tonnellate"<<endl;

    return 0;
}