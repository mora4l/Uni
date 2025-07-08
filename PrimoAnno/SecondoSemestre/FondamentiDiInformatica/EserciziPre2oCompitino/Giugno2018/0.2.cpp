#include <iostream>
#include <cmath>
using namespace std;

/*1. Si scriva la funzione C++ AbsDiff che riceva come parametri due numeri reali e restituisca come valore di ritorno 
la differenza in valore assoluto tra i due valori passati come parametri (un numero reale). */

double AbsDiff(double n1,double n2){
return fabs(n1-n2); //serve per il modulo
}

/*2. Si scriva la funzione C++ Prod che riceva come parametri due numeri reali e restituisca come valore di ritorno il 
prodotto dei due valori passati come parametri (un numero reale). */

double Prod(double n1,double n2){
    return n1*n2;
}

/*3. Si scriva la funzione C++ Calcola che riceva come parametri due array a e b di numeri reali, la loro dimensione n 
e il puntatore pf a una funzione che riceva come parametri due numeri reali e restituisca come valore di ritorno un 
numero reale. 
La funzione scandirà gli array a e b elemento per elemento, ad ogni iterazione chiamerà la funzione 
puntata da pf passandole come parametri la corrispondente coppia di elementi di a e b e sommerà tra loro i valori 
di ritorno restituiti dalla funzione chiamata. La funzione ritornerà infine il valore di tale somma (un numero reale) 
oppure 0 nel caso in cui il puntatore pf sia nullo.  */

double Calcola(double a[],double b[],int n,double (*pf)(double,double)){

    double somma=0;
    if(pf==nullptr){

        return 0;
    }
    for(int i =0 ; i<n;i++){
        double elementoA=a[i];
        double elementoB=b[i];
         somma+=(*pf)(elementoA,elementoB);
    }
        return somma;
    
}

/*
4. Si scriva infine un programma C++ che operi come segue: chieda all’utente di inserire da tastiera due array x e y di 
5 numeri reali, chieda all’utente se desidera calcolare la norma 1 della differenza dei due  array o il loro prodotto 
scalare,  chiami  la  funzione  Calcola  di  cui  al  punto  3,  passando  come  parametro  per  pf  la  funzione  AbsDiff  nel 
primo caso e la funzione Prod nel secondo caso, stampi a video il risultato e termini.
*/

int main(){

    int n=5;
    double x[n];
    double y[n];

    cout<<"inserisci 5 valori reali per ogni array"<<endl;
    cout<<"array 1:"<<endl;

    for(int i =0 ; i<n;i++){
        cin>>x[i];
    }

    cout<<"array 2:"<<endl;

    for(int i =0 ; i<n;i++){
        cin>>y[i];
    }

    cout<<"cosa vuol calcolare? [0] la somma della differenza dei due array ; [1] il loro prodotto scalare"<<endl;

    int scelta=0;
    
    do{
        cin>>scelta;

    }while(scelta!= 1 || scelta!=0);

    double risultato=0;
    if(scelta ==0){
        risultato=Calcola(x,y,n,AbsDiff);

    }else{
        risultato=Calcola(x,y,n,Prod);
    }

    cout<<"risultato"<<endl;

    return 0 ; 
}