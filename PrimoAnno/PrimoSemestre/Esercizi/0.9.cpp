/*
Si scriva un programma C++ che chieda all’utente di inserire da tastiera una stringa contenente al massimo 31 caratteri
e elabori tale stringa come segue: 

trasformi ogni carattere alfabetico maiuscolo nel corrispondente carattere minuscolo;

sostituisca ciascun carattere alfabetico minuscolo con il carattere che si trova due posizioni più avanti nell’alfabeto
anglosassone, in modo circolare (ad esempio, una g viene sostituita da una k; una y viene sostituita da una a e una z da
una b); 

sostituisca ciascuna cifra tra 0 e 9 con le lettere maiuscole corrispondenti partendo dalla lettera P (ad esempio 0
viene sostituto da P, 1 da Q e così via). 

Il programma stamperà infine a video la stringa risultante e ripeterà tutte le
operazioni finché l’utente lo desidera. Ad esempio la stringa “az45*PQK”, viene trasformata in “cbTU*rsm”.
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(){

    string stringa ; 
    char c;
    cout<<"Inserisci la stringa : "<<endl;
    cin>>stringa;

    if(stringa.size()>30){
        stringa=stringa.substr(0,30);
    }
    
    for(int i =0 ;i<stringa.size();i++){
        c=stringa[i];
        if(isupper(c)){
            stringa[i]=tolower(c);
        }else if(islower(c)){
            stringa[i]= (c- 'a'+2)%26+'a';
        }else if(isdigit(c)){
            stringa[i]= 'P' +(c- '0') ;
            
        }

    }

    cout<<stringa;
    

    return 0;
}