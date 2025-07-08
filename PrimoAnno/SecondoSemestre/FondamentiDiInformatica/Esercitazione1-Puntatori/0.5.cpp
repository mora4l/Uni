/*
 Il programma dovrà richiedere all'utente di inserire tre numeri interi.
L'obiettivo del programma è determinare quale tra i numeri inseriti è il
massimo. A tal fine, utilizza il riferimento `max` e una condizione con
(? :).
• Dopo aver trovato il massimo, il programma ne incrementa il valore
utilizzando il riferimento.
• Alla fine, il programma stampa i valori delle tre variabili per verificare
se l'incremento è stato effettuato correttamente.
• Perché non si può usare una sequenza delle istruzioni «if» al posto di ? perche  è piu compatto 
*/

#include <iostream>

using namespace std;

int main(){

    int uno=0,due=0,tre=0;

    cout<<"inserisci tre valori: "<<endl;

    cin>>uno>>due>>tre;
    int max =0 ; 
    //int max=((uno>due) && (uno > tre))? uno : ((due>tre)? due:tre) ; 
    if((uno>due)&&(due>tre)){
        max = uno ; 
    }
    if((due>tre)&&(due>uno)) {
        max = due ; 
    }else{
        max=tre;
    }
    int &maxx=max;


    maxx++;
    cout<<"massimo: "<<max<<endl;
    cout<<"variabili : "<<uno<<due<<tre<<endl;

    return 0;
}