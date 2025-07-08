/*
Si scriva la funzione C++ cerca che riceva come parametri il puntatore al primo elemento di una stringa str1 e il
puntatore al primo elemento di una seconda stringa str2.
• Utilizzando l’aritmetica dei puntatori, la funzione dovrà scandire la stringa str1 e restituire, come valore di
ritorno, il puntatore alla prima occorrenza della sottostringa str2 in str1. Nel caso in cui la sottostringa str2 non
occorra in str1, la funzione restituirà NULL.


• Si scriva quindi un programma C++ per verificare il corretto funzionamento della funzione. Il programma
chiederà all’utente di immettere da tastiera due stringhe, chiamerà la funzione cerca per verificare se la seconda
stringa occorre all’interno della prima e stamperà a video, in caso di esito positivo, la stringa str1 a partire dal
carattere puntato dal puntatore restituito dalla funzione cerca e fino al suo termine.
• In caso di esito negativo della verifica, il programma stamperà a video un opportuno messaggio.
*/

#include <iostream>

using namespace std;

char* cerca(char *p, char *p2){

char *res=p; 

for(char *res=p ; *res!='\0'; res++){
     if(*res==*p2){
        return res;
    }


}
cout<<p<<endl;
return nullptr; 


}

int main(){

    char string[11];
    char string2[11];

    cout<<"inserisci stringa 1"<<endl;
    cin>>string;

    cout<<"inserisci stringa 2"<<endl;
    cin>>string2;

    char *i=string; 
    char *i2=string2; 

   cerca(i,i2);
/*  
     if(ris!=nullptr){
        cout<<"eccolo: "<<*ris<<endl;
    }else{
        cout<<"errore"<<endl;
    }  */
    return 0; 
}