/*
Si scriva la funzione C++ prodotto_scalare che riceva come parametri il puntatore px al primo elemento di un
array di numeri reali, il puntatore py al primo elemento di un array di numeri reali e la dimensione comune n dei
due array (un numero intero).
• Utilizzando l’aritmetica dei puntatori, la funzione dovrà scandire i due array e calcolarne il prodotto scalare,
restituito come valore di ritorno (un numero reale).
• Si scriva quindi un programma C++ per verificare il corretto funzionamento della funzione. Il programma
chiederà all’utente di immettere da tastiera i valori per i due array, chiamerà la funzione prodotto_scalare e ne
stamperà a video il valore di ritorno.
• Esempio: se l’array puntato da px vale {1.0, 3.0, 2.5, 0.0, 1.2} e l’array puntato da py vale {2.0, 1.0, 2.0, 3.8, 10.0}
(si ha quindi n = 5), la funzione restituisce il valore del prodotto scalare dei due array, ovvero: 1.0 × 2.0 + 3.0 ×
1.0 + 2.5 × 2 + 0.0 × 3.8 + 1.2 × 10.0 = 22.0.
*/
#include <iostream>
using namespace std; 


double prodotto_scalare(double *px,double *py,int n ){
    double result =0 ;

    
    for(int i= 0 ; i <n; i++){
        result+= *(px+i)*(*(py+i)); 
    }



    return result; 
}

int main(){

    int n=5;
    double array1[n];
    double array2[n];

    double *p=array1;
    double *pp=array2;

    cout<<"inserisci valori array1 "<<endl;
    for(int i=0 ; i<5;i++){

    cin>>array1[i]; 
    }
        cout<<"inserisci valori array2 "<<endl;
    for(int i=0 ; i<5;i++){

    cin>>array2[i]; 
    }

    double ri=prodotto_scalare(p,pp,n);

    cout<<"Il risultato è:"<<ri<<endl;

    return 0 ; 
}