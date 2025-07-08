/*
• Scrivi un programma che gestisce informazioni relative a due film, utilizzando strutture
(struct) e puntatori.
• Il programma deve consentire all'utente di inserire i dati di due e determinare quale dei due
film è il più recente.
• Se entrambi i film hanno lo stesso anno di uscita, il programma deve notificare l'utente di
questa situazione.
▫ Il programma deve utilizzare i puntatori per gestire e manipolare le strutture dei film. I puntatori
vengono utilizzati per passare le strutture alla funzione e per accedere ai campi.

▫ Creare una funzione che accetta i puntatori a due strutture film e confronta gli anni di uscita dei
due film, restituendo il puntatore al film più recente.

▫ Il programma in main() deve chiedere all'utente di inserire i dati di due film (titolo, durata e anno)
e usare questi dati per confrontare i film.

▫ Il programma deve stampare il titolo del film più recente, oppure indicare che i due film hanno lo
stesso anno di uscita
*/

#include <iostream>
using namespace std;
struct Film{
    char titolo[20];
    double durata;
    int anno;
};

Film* confronta(Film* p1,Film* p2){
if((p2->anno)>(p1->anno)){
return p2;
}else{
    return p1;
}
if((p2->anno)==(p1->anno)){
return nullptr;
}

}


int main(){

Film film1;
Film film2;
Film *p1;
Film *p2;


cout<<"inserisci il titolo 1:"<<endl;
cin>>film1.titolo;
cout<<"inserisci la durata [min]"<<endl;
cin>>film1.durata;
cout<<"inserisci anno"<<endl;
cin>>film1.durata;
p1=&film1;
cout<<"inserisci il titolo 2:"<<endl;
cin>>film2.titolo;
cout<<"inserisci la durata [min]"<<endl;
cin>>film2.durata;
cout<<"inserisci anno"<<endl;
cin>>film2.durata;
p2=&film2;

Film* prest= confronta(p1,p2);
if(prest!=nullptr){
cout<<"il film piu vecchio è il film : "<<prest->titolo<<endl;
}else{
    cout<<"le date sono uguali"<<endl;
}
    return 0; 
}