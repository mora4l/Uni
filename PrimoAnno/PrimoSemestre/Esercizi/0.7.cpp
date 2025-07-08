/*
Si scriva un programma C++ che dichiari due array a e b di 12 numeri interi, chieda all’utente di inserirne da tastiera i
valori dell’array a e operi come segue: assegni inizialmente il valore 1 al primo ed all’ultimo elemento dell’array b;

quindi partendo dal penultimo elemento dell’array a e fino al secondo elemento, assegni al corrispondente elemento
dell’array b il prodotto dell’elemento precedente e di quello seguente nell’array a. Il programma stamperà infine a
video l’array b e ripeterà tutte le operazioni finché l’utente lo desidera. Ad esempio, se a = {1, 3, 4, 2, 9, 5, 3, 2, 2, 6,
3, 3}, l’array b sarà b = {1, 4, 6, 36, 10, 27, 10, 6, 12, 6, 18, 1}.
*/

#include <iostream>
#define N 12
using namespace std;

int main(){

while(1){

int a[N]={0};
int b[N]={0};

cout<<endl<<endl<<"Inserisci valori array a: "<<endl;

    b[0]=1; 
    b[11]=1;

for(int i = 0 ; i < N ; i++){
     cin>>a[i];
}

for ( int i = 10; i >0 ; i--){
    b[i]= a[i-1]*a[i+1];
    
}
for(int i =0 ; i<N ; i++){
    cout<<b[i]<<" ";
}
}

    return 0 ; 
}