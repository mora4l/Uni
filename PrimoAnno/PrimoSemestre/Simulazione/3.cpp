/*
Una società di consulenza fornisce consulenze in ambito tecnico, amministrativo e finanziario. 
Per ciascun mese, i dati relativi alle consulenze effettuate nel mese sono contenuti in un file 
le cui righe contengono 
l’identificatore del consulente che ha fornito la consulenza (un numero intero), 
il tipo di consulenza (un carattere alfanumerico che potrà assumere i valori ‘t’, ‘a’ o ‘f’) e 
l’importo in Euro della consulenza (un numero reale). 

Al fine di calcolare i ricavi della società si sviluppi quanto segue in linguaggio C++:

Un programma che, finché l’utente lo desidera, operi come segue: 
chieda all’utente di immettere da tastiera il nome del file che desidera elaborare (una stringa contenente al massimo 31 caratteri) 
e la tipologia di consulenze per le quali desidera calcolare il ricavo totale (un carattere alfanumerico), 
chiami la funzione calcola_ricavi passando le menzionate informazioni come parametri attuali e, infine, 
stampi a video il ricavo totale calcolato dalla funzione oppure un messaggio di errore nel caso in cui la funzione restituisca -1.0 oppure -2.0.

Esempio: se l’utente decide di ottenere il ricavo totale delle consulenze in ambito finanziario contenute nel seguente file dati.txt:

1          f           10000.0
1          f           8000.0
2          t           9000.0
3          a          8000.0
1          f           10000.0

la funzione calcolerà e stamperà a video un ricavo totale pari a 28000 Euro.

ATTENZIONE: è possibile inserire il codice qui sotto OPPURE inviare un file di testo contenente il codice sorgente.
*/
#include <iostream>
#include <fstream>

using namespace std;
double calcola_ricavi(char nomefile[32],char tipologia){
/*
La funzione calcola_ricavi che riceva come parametri 
la stringa di caratteri nomefile e il carattere alfanumerico tipologia 
e restituisca come valore di ritorno un numero reale. 
La funzione apre il file il cui percorso è contenuto nella stringa nomefile, lo scandisce riga per riga (il numero di righe non è noto al programmatore), 
calcola e restituisce come valore di ritorno il ricavo totale delle consulenze la cui tipologia è quella riportata nel carattere tipologia. 
Ad esempio, se il carattere tipologia vale ‘f’, la funzione restituirà il ricavo totale delle consulenze in ambito finanziario. 
Nel caso in cui il file non esista o il carattere tipologia assuma un valore non valido, la funzione restituirà un codice di errore: 
-1.0 in caso di file non esistente, 
-2.0 in caso di valore non valido del carattere tipologia. 
Per semplicità, si assuma che il file, qualora esista, non sia vuoto e contenga sempre valori validi.

*/

    double n=0,costo=0;
    char consulenza;
    int id=0 ; 

    fstream fileapertura;

    fileapertura.open(nomefile,ios::in);
    if(!fileapertura){
        cout<<"File inesistente"<<endl;
        return -1;
    }else if((tipologia!='f'&&(tipologia!='a')&&(tipologia!='t'))){
        return -2;
    }

    fileapertura>>id>>consulenza>>costo;
    
    while(!fileapertura.eof()){
    if(consulenza==tipologia){
        n+=costo;
    }
    fileapertura>>id>>consulenza>>costo;
    }

    return n;
}
int main(){
/*

Un programma che, finché l’utente lo desidera, operi come segue: 
chieda all’utente di immettere da tastiera il nome del file che desidera elaborare (una stringa contenente al massimo 31 caratteri) 
e la tipologia di consulenze per le quali desidera calcolare il ricavo totale (un carattere alfanumerico), 
chiami la funzione calcola_ricavi passando le menzionate informazioni come parametri attuali e, infine, 
stampi a video il ricavo totale calcolato dalla funzione oppure un messaggio di errore nel caso in cui la funzione restituisca -1.0 oppure -2.0.

*/
char nomef[32];
char tipo;
cout<<"Inserisci il nome del file (max 31 char)"<<endl;
cin>>nomef;
cout<<"Inserisci la tipologia di consulenza (t/a / f)"<<endl;
cin>>tipo;
double result=calcola_ricavi(nomef,tipo);

if((result!=2)&&(result!=-1)){

cout<<"il totale della tipologia "<<tipo<<" è "<<result<<endl;
}else if((result == -1) || (result ==-2)){
cout<<"eerore"<<endl;
}

    return 0;
}