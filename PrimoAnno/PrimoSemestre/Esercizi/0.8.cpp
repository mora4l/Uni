/*
Allo scopo di gestire i propri investimenti, una società finanziaria rileva su base giornaliera il prezzo di venti diverse
azioni. Per analizzare l’andamento di tali prezzi, si sviluppi quanto segue nel linguaggio C++:

*/
#include <iostream>
#include <fstream>
#define R 30
#define C 20
using namespace std;

double media_prezzi(double P [R][C],int n){
/*
1. La funzione media_prezzi che riceva come parametri una matrice di numeri reali P di 30 righe e 20 colonne e un
numero intero n e restituisca come valore di ritorno un numero reale. La matrice P contiene i prezzi di ciascuna
delle 20 azioni, rilevati negli ultimi 30 giorni. Dopo aver verificato che n sia compreso tra 0 e 19, la funzione
calcolerà e restituirà come valore di ritorno il prezzo medio della n-esima azione negli ultimi 30 giorni (ovvero la
media degli elementi nella n-esima colonna della matrice P). Nel caso in cui il parametro n assuma un valore non
valido, la funzione restituirà -1.0.
*/
    double mediaAzione =0 ,azioni=0; 
    
    if((n>=0)&&(n<=19)){
    for(int i = 0 ; i <R;i++){
        azioni+=P[i][n];
    }

    }

    mediaAzione=azioni/R;

    if(mediaAzione>0){

    return mediaAzione ; 
    
    }else{
    
    return -1;
    }

}


double variazione_prezzi(double P[30][20],int n){
/*
2. La funzione variazione_prezzi che riceva come parametri una matrice di numeri reali P di 30 righe e 20 colonne,
definita come nel punto 1, e un numero intero n e restituisca come valore di ritorno un numero reale. Dopo aver
verificato che n sia compreso tra 0 e 19, la funzione calcolerà e restituirà come valore di ritorno la differenza tra il
valore di prezzo massimo e il valore di prezzo minimo contenuti nell’n-esima colonna della matrice P. Nel caso in
cui n assuma un valore non valido, la funzione restituirà -1.0.
*/
    double variazione =0 ,min=P[0][0],max=P[0][0]; 
    
        if((n>=0)&&(n<=19)){
            for(int i =0 ; i<R;i++){
                if(P[i][n]>max){
                    max=P[i][n];
                }
                if(P[i][n]<min){
                    min=P[i][n];
                }
            }

            variazione = max/min;
        }else{
            return -1;
        }

    return variazione;
}

/*
3. La funzione estremi_prezzi che riceva come parametri in ingresso una matrice di numeri reali P di 30 righe e 20
colonne definita come nel punto 1 e un carattere alfanumerico c. La funzione ha inoltre un parametro di uscita
pmin (un numero intero) e restituisce come valore di ritorno un numero intero. La funzione opererà come segue:

nel caso in cui il carattere c valga ‘p’, considererà i prezzi dei primi 10 giorni (ovvero le righe con indice da 0 e 9)
e restituirà nel parametro di uscita pmin, l’indice dell’azione (ovvero della colonna) che ha ottenuto il minimo
prezzo e, come valore di ritorno, l’indice dell’azione (ovvero della colonna) che ha ottenuto il massimo prezzo;

nel caso in cui il carattere c valga ‘s’, eseguirà la stessa operazione considerando i prezzi dei 10 giorni intermedi
(ovvero le righe con indice da 10 a 19); nel caso in cui il carattere c valga ‘t’, eseguirà la stessa operazione
considerando i prezzi degli ultimi 10 giorni (ovvero le righe con indice da 20 a 29). In caso di valore non valido
del carattere c, la funzione assegnerà il valore -1 a pmin e restituirà -1 come valore di ritorno.
*/

int estremi_prezzi(double P[R][C],char c,int &pmin){

    int max=0,min=0,indicemax=0; 

    if(c=='p'){
        for(int i =0 ;i<10;i++){
            max=P[i][0];
            min=P[i][0];
            for(int j=0 ; j<C;j++){
                if(P[i][j]>max){
                    max=P[i][j];
                    indicemax=j;
                }
                if(P[i][j]<min){
                    min=P[i][j];
                    pmin=j;
                }
            }
        }
    }else if(c=='s'){
        for(int i =10 ;i<C;i++){
            max=P[i][0];
            min=P[i][0];
            for(int j=0 ; j<C;j++){
                if(P[i][j]>max){
                    max=P[i][j];
                    indicemax=j;
                }
                if(P[i][j]<min){
                    min=P[i][j];
                    pmin=j;
                }
            }
        }
    }else if(c=='t'){
        for(int i =20 ;i<R;i++){
            max=P[i][0];
            min=P[i][0];
            for(int j=0 ; j<C;j++){
                if(P[i][j]>max){
                    max=P[i][j];
                    indicemax=j;
                }
                if(P[i][j]<min){
                    min=P[i][j];
                    pmin=j;
                }
            }
        }
    }else{
        pmin=-1;
        return -1;
    }

    return indicemax;
}

int main (){
/*
4. La funzione main che operi come segue: dichiari una matrice di numeri reali PZ di 30 righe e 20 colonne; apra in
lettura il file Prezzi.txt contenente una matrice di numeri reali di 30 righe e 20 colonne e la copi nella matrice PZ;
per ogni colonna della matrice PZ, chiami la funzione variazione_prezzi (punto 2) e ne stampi a video il risultato.
*/

    double PZ[R][C]={{0}};
//    int azione =0 ; 
    fstream filelettura;

    filelettura.open("Prezzi.txt",ios::in);

    if(!filelettura){
        return -1;
    }

/*     cout<<"inserisci il numero dell'azione che vuoi monitorare: (0-19)"<<endl;
    cin>>azione; */

    for(int i = 0 ;i<R;i++){
        for(int k=0;k<C;k++){
            filelettura>>PZ[i][k];
        }
    }
    for(int i =0 ; i<C;i++){

            int risultato = variazione_prezzi(PZ,i);
            cout<<"il risultato della colonna "<<i<<" è "<< risultato<<endl;

    }

    filelettura.close();
    return 0; 
}