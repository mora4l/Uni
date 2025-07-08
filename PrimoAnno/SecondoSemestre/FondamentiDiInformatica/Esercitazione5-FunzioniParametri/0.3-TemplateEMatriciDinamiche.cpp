/*
Si desidera realizzare un programma C++ per eseguire semplici elaborazioni su matrici quadrate di elementi di tipo
generico. A tale scopo si implementino i seguenti template di funzione:



*/
#include <iostream>
using namespace std; 
/*

▫ Il template di funzione somma che riceva come parametri un puntatore pM a un puntatore a un oggetto di tipo T e un numero intero n e restituisca
come valore di ritorno un oggetto di tipo T. Il puntatore pM punta a una matrice quadrata di n righe e n colonne di oggetti di tipo T. La funzione
calcola e restituisce come valore di ritorno la somma degli elementi della matrice puntata da pM.
*/

template <typename T>
T somma(T **pm,int n ){
    T sum=0 ; 
for(int i =0 ; i<n;i++){
    for(int j=0 ; j<n;j++){
        sum+= *(*(pm+i)+j);
    }
}
return sum; 
}
/*

▫ Il template di funzione prodotto che riceva come parametri un puntatore pM a un puntatore a un oggetto di tipo T e un numero intero n e restituisca
come valore di ritorno un oggetto di tipo T. Il puntatore pM punta a una matrice quadrata di n righe e n colonne di oggetti di tipo T. La funzione
calcola e restituisce come valore di ritorno il prodotto degli elementi della matrice puntata da pM.
*/

template <typename T>

T prodotto(T **pM,int n ) {
    T prod=1 ; 
for(int i =0 ; i<n;i++){
    for(int j=0 ; j<n;j++){
        prod*=( *(*(pM+i)+j));
    }
}
return prod; 

}
/*
▫ Il template di funzione traccia che riceva come parametri un puntatore pM a un puntatore a un oggetto di tipo T e un numero intero n e restituisca
come valore di ritorno un oggetto di tipo T. Il puntatore pM punta a una matrice quadrata di n righe e n colonne di oggetti di tipo T. La funzione
calcola e restituisce come valore di ritorno la traccia degli elementi della matrice puntata da pM. Si ricorda che la traccia di una matrice quadrata è
data dalla somma degli elementi sulla diagonale principale.
*/

template <typename T>
 T traccia(T **pM,int n ){
    T traccia = 0 ; 
    for(int i =0 ; i<n;i++){
    for(int j=0 ; j<n;j++){
        if(i==j){

        traccia+= *(*(pM+i)+j);
        }
    }

}
return traccia ; 
 }

/*
• Si scriva quindi un programma C++ che operi come segue:
▫ Chieda all’utente di inserire da tastiera la dimensione d (un numero intero) delle matrici quadrate che si vogliono elaborare.
*/
int main(){
    int d=0 ; 
    cout<<"inserisci dimensione "<<endl;
    cin>>d; 
//praticamente qua devo creare la matrice 2x2 dinamica
//▫ Allochi dinamicamente una matrice di d x d numeri reali. 

//A tale scopo, dichiari un puntatore a un puntatore a un numero reale pData, allochi
//dinamicamente un array di d puntatori a numeri reali e ne assegni il puntatore a pData

    double **pData;

    pData=new double *[d];

/*
, allochi dinamicamente d array di numeri reali e ne assegni i
puntatori agli elementi dell’array puntato da pData.

*/

for(int i=0 ; i<d;i++){
    pData[i]=new double [d];
}

/*
▫ Chieda all’utente di inserire da tastiera il valore di ciascun elemento della matrice così allocata.
▫ Chiami somma, prodotto e traccia e stampi a video i loro valori di ritorno.
▫ Deallochi la memoria precedentemente allocata e termini
*/
cout<<"inserisci valori matrice:"<<endl; 
for(int i =0 ; i<d;i++){
    for(int j = 0 ; j<d;j++){

        cin>>*(*(pData+i)+j);
    }
}

double ris= somma(pData,d);
cout<<ris<<endl;

double ris2= prodotto(pData,d);
cout<<ris2<<endl;

double ris3= traccia(pData,d);
cout<<ris3<<endl;


    return 0 ; 
}