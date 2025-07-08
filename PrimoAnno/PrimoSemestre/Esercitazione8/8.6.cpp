/*
Un’agenzia di spedizioni organizza quasi quotidianamente la movimentazione di merci tra due città collegate da una ferrovia.

La merce viene collocata su di un treno che può essere composto da un massimo di 10 vagoni.

Per rappresentare i dati relativi a tale attività nel corso di un mese, si può utilizzare una matrice T di numeri reali di 31 righe e 10 colonne,
dove le righe rappresentano i giorni di un mese e le colonne i vagoni del treno.
L’elemento Tij della matrice T rappresenta il numero di tonnellate di merce caricata su di uno specifico vagone (il j-esimo vagone) in un giorno specifico (l’i-esimo giorno).

Nel caso in cui il treno in un certo giorno fosse composto da meno di 10 vagoni, gli elementi restanti della riga corrispondente della matrice T sono impostati a zero.
Se in un certo giorno il treno non ha viaggiato, tutti gli elementi della riga corrispondente della matrice T sono impostati a zero
(nello stesso modo si gestiscono i mesi che hanno meno di 31 giorni).

*/

#include <iostream>
#include <fstream>
#define R 32
#define C 11
using namespace std;

/*

1. La funzione totaleMerce che riceva come parametro la matrice T sopra descritta e

restituisca come valore di ritorno il numero totale di tonnellate di merce movimentata nel
corso del mese (un numero reale).

La funzione calcolerà e restituirà, quindi, la somma dei valori degli elementi della matrice T.

Per semplicità si assuma che i valori assunti dagli elementi della matrice T siano sempre validi.

*/
double totaleMerce(double T[R][C])
{
    double tonnellateTotMese = 0;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {

            if (T[i][j] < 0)
            {
                cout << "C'e un vagone con peso negativo, non verra calcolato .è il vagone n°" << i << " del giorno " << j << endl;
            }

            tonnellateTotMese += T[i][j];
        }
    }

    return tonnellateTotMese;
}

/*
2. La funzione numTreni che riceva come parametro la matrice T sopra descritta e
restituisca come valore di ritorno il numero totale di treni che hanno viaggiato nel corso
del mese (un numero intero).
La funzione calcolerà e restituirà, quindi, il numero di righe della matrice T che contengono almeno un elemento diverso da zero.

Per semplicità si assuma che i valori assunti dagli elementi della matrice T siano sempre validi.

*/
int numTreni(double T[R][C])
{
    int treniMensili = 0;

    for (int i = 0; i < R; i++)
    {
        bool positive = false;
        for (int j = 0; j < C; j++)
        {
            if (T[i][j] > 0)
            {
                positive = true;
            }
        }
        if (positive == true)
        {

            treniMensili++;
        }
    }

    return treniMensili;
}
/*
3. La funzione maxTreno che riceva come parametro la matrice T sopra descritta,
abbia come parametri di uscita (ovvero per riferimento) due numeri interi v e g e restituisca come valore di ritorno un numero reale.

La funzione assegna a v il numero di vagoni del treno composto dal maggior numero di vagoni, assegna a g l’indice del giorno in cui tale treno ha viaggiato e

restituisce come valore di ritorno il numero di tonnellate di merce che tale treno ha trasportato.

Se vi è più di un treno con lo stesso numero massimo di vagoni, la funzione restituisce i dati del treno che ha viaggiato per primo (ovvero il primo che viene trovato scandendo le righe della matrice T dalla prima all’ultima).

Per semplicità si assuma che i valori assunti dagli elementi della matrice T siano sempre validi.
*/

double maxTreno(double T[R][C], int &v, int &g)
{

    int nvagoniprec = 0, numvagTrenoCorrente = 0;
    double tonnellateTrenoAttuale = 0, tonnellateTrenoPiugrande = 0, tonnellateTrenoPrecedente = 0;

    for (int i = 0; i < R; i++)
    { // ciclo su ogni riga (ogni giornata)
        for (int j = 0; j < C; j++)
        { // controllo ogni vagone di quella giornata x
            if (T[i][j] > 0)
            {                          // se il vagone ha valore positivo...
                numvagTrenoCorrente++; // incrementa il numero di vagoni con merce
                tonnellateTrenoAttuale += T[i][j];
            }
        }
        if (numvagTrenoCorrente > nvagoniprec)
        {                                                      // ora ho finito di contare i vagoni di quel giorno pieni, e SE il numero di vagoni pieni è maggiore del numero di vagoni pieni del treno precedente...
            v = numvagTrenoCorrente;                           // v prende il valore del nuovo treno con più vagoni pieni di tutti fino ad ora
            g = i;                                             // g prende il giorno di quel treno con più vagoni di tutti i restanti
            nvagoniprec = numvagTrenoCorrente;                 // e per confrontare più avanti gli altri treni mi serve l'ultimo treno che aveva il numero maggiore di vagoni pieni, in questo caso visto che l'abbiamo appena trovato quello con più vagoni fino ad ora, imposto lui come tale
            tonnellateTrenoPiugrande = tonnellateTrenoAttuale; // la variabile delle tonnellate del treno più grande prende il valore del peso del treno più grande fino ad ora.
        }
        if (numvagTrenoCorrente == nvagoniprec) // se il treno attuale è uguale al treno precedente... attenzione ! voglio i dati dell'ultimo treno prima di questo...
        {
            v = nvagoniprec;                                      // quindi il numero di vagoni maggiore lo assegno a quello prima
            g = i - 1;                                            // il giorno è quello prima di questo corrente
            tonnellateTrenoPiugrande = tonnellateTrenoPrecedente; // le tonnellate del treno più grande sono le tonnellate del treno precedente , visto che gli ultimi due treni sono uguali e voglio il primo dei due uguali come risultato
        }
        numvagTrenoCorrente = 0; // resetto il contatore dei vagoni a 0 , per il conteggio dei vagoni del prossimo treno
        tonnellateTrenoAttuale = 0;
        tonnellateTrenoPrecedente = tonnellateTrenoAttuale;
    }

    return tonnellateTrenoPiugrande;
}


/*
4. Un programma che operi come segue: 

dichiari e inizializzi a zero una matrice Treni di numeri reali di 31 righe e 10 colonne organizzata come sopra descritto; 

apra in lettura il file "Dati.txt": il file è composto di 31 linee, ciascuna contenente 10 numeri reali (per semplicità si supponga che il file esista e che il suo contenuto sia sempre valido);

scandisca il file e assegni a ciascun elemento della matrice Treni il corrispondente valore contenuto nel file; chiami la funzione totaleMerce e stampi a video il suo valore di ritorno;

chiami la funzione numTreni e stampi a video il suo valore di ritorno; 
chiami la funzione maxTreno e stampi a video il suo valore di ritorno e i valori assunti dai parametri passati per riferimento dopo la chiamata della funzione.
*/
int main()
{
    /*
     righe = gorni di un mese
     colonne = vagoni del treno

     ogni valore di ogni riga sono le tonnellate per quel vagone di quel giorno
     se un giorno ci sono meno di 10 vagoni , gli elementi restanti sono = 0
     se un giorno non ci sono vagoni , tutti gli elementi sono = 0
     se un mese ha meno di 31 giorni , le restanti righe per arrivare a 31 rimangono vuote
*/
    int n = 0, v = 0;
    double T[R][C]={0};

    fstream file;

    file.open("Dati.txt",ios::in);
    if(!file){
        cout<<"Nessun file è stato trovato"<<endl;
        exit(1);
    }

    while(!file.eof()){
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){

                file>>T[i][j];

            }
        }
    }
    
    double totaleTonnellate=totaleMerce(T);
    cout<<"Il totale di tonnellate che sono state movimentate questo mese è di: "<<totaleTonnellate<<endl;

    int trenimensili=numTreni(T);
    cout<<"Il totale di treni che hanno viaggiato in questo mese è di "<<trenimensili<<" treni."<<endl;


    double TonnellateTreno=maxTreno(T,n,v);

    cout<<"Il giorno "<<v<<" del mese, il treno con "<<n<<" vagoni ha trasportato "<<TonnellateTreno<< " tonnellate."<<endl;
    return 0;
}