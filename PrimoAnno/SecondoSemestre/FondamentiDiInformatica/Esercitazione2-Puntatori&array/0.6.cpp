/*
Scrivere un programma che carichi un vettore di caratteri e conti quante consonanti e
vocali sono presenti, visualizzando i risultati a video. Si utilizzino i puntatori

In dettaglio:
▫ Scrivi una funzione che prenda come argomenti un puntatore a carattere e un intero, e riempa il vettore di
lunghezza specificata con i caratteri inseriti dall'utente. La funzione deve quindi stampare il vettore.


▫ Scrivi una funzione conta che prenda come argomenti un puntatore a carattere e un intero, e conti il numero
di vocali e consonanti presenti nel vettore. La funzione deve quindi stampare il numero di vocali e
consonanti.

▫ Scrivi il programma principale che controlli il funzionamento corretto delle funzioni. Il programma definisce
un vettore di caratteri di lunghezza massima 100, e chiede all'utente di inserire il numero di caratteri da
caricare nel vettore.
[Esercizio C017] - 
*/

#include <iostream>
#include <cctype>
using namespace std;


void funzione(char *p, int o){
cout<<"Inserisci "<<o<<" caratteri"<<endl;

for(int i =0 ; i< o;i++){
    cin>>*(p+i);
}

cout<<"stampo il vettore : "<<endl;
for(int i =0 ; i< o;i++){
    cout<<*(p+i)<<endl;
}
}
void conta(char* s , int z){
    int vocali=0 ,cons=0; 
    for(int i=0;i<z;i++){

        *(s+i)=tolower(*(s+i));
        if((*(s+i)=='a')||(*(s+i)=='e')||(*(s+i)=='i')||(*(s+i)=='o')||(*(s+i)=='u')){
vocali++;
        }else{
            cons++;
        }
    }

    cout<<"le vocali sono :"<<vocali<<endl;
    cout<<"le consonanti sono :"<<cons<<endl;
    
}

int main(){
    char vector[101];   
    
    cout<<"inserisci il numero di caratteri da caricare nel vettore"<<endl; 
    int n=0 ; 
    cin>>n;
    funzione(vector, n);
    conta(vector,n);
    return 0; 
}