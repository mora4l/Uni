/*
Un indirizzo IP è costituito da 4 numeri interi che possono assumere valori tra 0 e 255 ed è normalmente rappresentato
separando i 4 numeri con il carattere ‘.’. Ad esempio: 192.168.0.24.
*/
#include <iostream>

using namespace std;

int strToIP(string bit,int address[4]){

/*
Si scriva la funzione C++ strToIP che riceva in ingresso una stringa di caratteri s e un array di quattro numeri interi ip
e restituisca come valore di ritorno un numero intero. 
La stringa s contiene un indirizzo IP formattato come descritto sopra. 
Dopo avere inizializzato a zero tutti gli elementi dell’array ip, la funzione scandisce la stringa s e assegna a
ciascun elemento dell’array ip il corrispondente valore contenuto nella stringa. Al primo elemento di ip sarà assegnato
quindi il primo numero intero che compone l’indirizzo IP rappresentato dalla stringa s, al secondo elemento di ip sarà
assegnato il secondo numero intero che compone l’indirizzo IP rappresentato dalla stringa s e così via. Se, ad esempio,
si avesse s = “192.168.0.24”, si otterrebbe l’array ip = {192, 168, 0, 4}. Nel caso in cui il valore di almeno uno dei
quattro numeri interi componenti l’indirizzo IP non sia valido, la scansione si interrompe e la funzione restituisce -1.
Altrimenti la funzione restituisce 1. Per semplicità si assuma che la stringa s sia sempre formattata correttamente.
*/

    int n=1,num=0,indiceottetto=0;

    char c;
    
    for(int i =0 ;i<16;i++){
        c=bit[i];

        if(c=='.'){
            address[indiceottetto]=num;
            num=0;
            indiceottetto++;
        }else{
            num=num*10+(c-'0');

            if(num>255){
                cout<<"uno dei bit non è valido"<<endl;
                n=-1;
            }
        }
    }
    address[indiceottetto]=num;

    return n;
}

int main(){
/*
Si scriva infine un programma C++ che dichiari un array address di 4 numeri interi, chieda all’utente di inserire da
tastiera una stringa str formattata come descritto sopra (la stringa contiene al massimo 15 caratteri), chiami la funzione
strToIP passandole come parametri address e str e stampi a video il valore degli elementi dell’array address dopo la
chiamata della funzione. L’utente può ripetere le operazioni sopra specificate finché lo desidera
*/
    int scegli =0 ; 
    int address[4]={0};
    string bit="";

    while(scegli==0){
        

    cout<<"inserisci la stringa"<<endl;
    cin>>bit;

    if(bit.size()>15){
        bit.substr(0,16);
    }

    int result=strToIP(bit,address);

    if(result==1){

    for(int i=0 ;i<4;i++){
        cout<<address[i]<<".";
    }
    }else{
        cout<<"c'è un errore nella dimensione degli ottetti"<<endl;
    }
    
    cout<<endl<<"digita 1 se vuoi continuare , altrimenti 0"<<endl;
    cin>>scegli;

    bit.clear();
    
    for(int i =0 ; i<4;i++){
        address[i]=0;
    }
    }

    return 0;
}