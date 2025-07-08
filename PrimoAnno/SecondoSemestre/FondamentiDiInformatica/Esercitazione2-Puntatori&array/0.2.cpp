/*

Puntatori
• Dichiarare due stringhe di uguale dimensione.
• Acquisire in una stringa una sequenza di caratteri, quindi copiare, usando i puntatori, tutti i caratteri dalla
stringa acquisita all'altra, accedendo in modo indiretto a ciascuna delle locazioni delle due stringhe.
*/

#include <iostream>
using namespace std; 

int main(){

    char str[11];
    char str2[11];
    char *p=str;
    char *pp=str2; 
    cout<<"inserisci stringa (10 char)"<<endl;
    cin>>str;
    
    for(int i = 0 ; i<11; i++){
        pp=p;
    }

    cout<<pp; 
    return 0 ; 
}