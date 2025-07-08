/*
Si scriva una funzione C++ che riceva come parametro una stringa di caratteri str e restituisca come valore di ritorno
un numero intero. Dopo avere verificato che la stringa sia composta da caratteri alfabetici (escluso il carattere nullo),
la funzione converte eventuali caratteri alfabetici maiuscoli in minuscoli; quindi calcola e restituisce un punteggio per
la stringa str dato dalla somma delle differenze assolute tra ciascuna coppia di caratteri consecutivi. Ad esempio, data
la stringa str = “aa”, la funzione restituisce 0 (|‘a’ – ‘a’| = 0); data la stringa str = “abf”, la funzione restituisce 5 (|‘a’ –
‘b’| + |‘b’ – ‘f’| = 1 + 4 = 5). Se la stringa non contiene solo caratteri alfabetici, la funzione restituisce -1. Si scriva
quindi un programma C++ che, finché l’utente lo desidera, gli chieda di immettere da tastiera una stringa contenente al
massimo 31 caratteri, chiami la funzione di cui sopra e, in caso di dato valido, ne stampi a video il valore di ritorno.
*/

#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;

int stringata(char str[]){
    int n=0,somma=0,charprec=0;
    char c;
while(str[n]!='\0'){
   c= str[n];

    if(!isalpha(c)){
        return -1;
    }
    if(isupper(c)){
        c=tolower(c);
    }
    if(n>0){

    somma+=abs(c-charprec);
    }

    charprec= c;
    n++;
}
    return somma;
}

int main(){
    char s[32];
    cout<<"inserisci una stringa di char"<<endl;

    cin>>s;
    
    
    int val=stringata(s);


    cout<<val<<endl;
    return 0;
}