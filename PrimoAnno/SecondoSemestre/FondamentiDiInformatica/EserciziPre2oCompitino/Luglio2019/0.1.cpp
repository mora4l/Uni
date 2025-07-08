/*La mappa  logistica fu proposta nel 1845 da P.F. Verhulst come modello matematico per lo studio dei fenomeni di 
crescita delle popolazioni biologiche. Se indichiamo con xn la densità di una popolazione alla generazione n – densità 
normalizzata tra 0 (popolazione assente) e 1 (densità massima) – e con λ Î R il tasso di crescita costante della 
popolazione stessa da una generazione all’altra, allora la densità xn della popolazione alla generazione n è data da: 
 
!
𝑥#=𝜆𝑥#&'(1− 𝑥#&')
𝑥-=1
5                                
 



/*Si scriva in C++ la funzione ricorsiva mappa_logistica che riceva in ingresso (ovvero come parametri) i valori di n (un 
numero intero) e di λ (un numero reale), calcoli e restituisca come valore di ritorno la densità xn della popolazione alla 
n-esima generazione (un numero reale). Nel caso in cui n assuma un valore negativo, la funzione restituisce 0. */
#include <iostream>
using namespace std;

double mappa_logistica(int n,double l){
    double nMenoUno=0;
    double ris=0;
    
    if(n>0){
        if(n==0){
            ris=1/5;
        }else{
            nMenoUno=mappa_logistica(n-1,l);
            ris=l*nMenoUno*(1-nMenoUno);
        }
    }else{
        return 0;
    }

    return ris;
}
/*Si scriva quindi un programma C++ che operi come segue: definisca un array lambda di 7 numeri reali e lo inizializzi 
con i valori seguenti {1, 2, 3, 3.25, 3.5, 3.75, 4}; per ciascuno dei valori di λ contenuti nell’array lambda, chiami la 
funzione mappa_logistica per tutti i valori di n compresi tra 0 e 10, stampandone a video il valore di ritorno*/
int main(){

    double lambda[7]={1,2,3,3.25,3.5,3.75,4};

    for(int i =0 ;i<7;i++){

        if((lambda[i]>=0)&&(lambda[i]<=10)){
            double riss=mappa_logistica(7,lambda[i]);
            cout<<"risultato per "<<i<<":"<<riss<<endl;
            riss=0;
        }
    }

    return 0 ;
}