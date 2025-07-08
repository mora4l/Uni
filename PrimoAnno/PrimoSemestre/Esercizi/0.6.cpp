/*
Un ristorante serve ai suoi clienti sei diversi tipi di pasta, associabili a cinque diversi condimenti.
Per elaborare le informazioni riguardanti i piatti serviti dal ristorante e i ricavi ottenuti, si sviluppi quanto segue in linguaggio C++:
*/

#include <iostream>
#include <fstream>
#define R 6
#define C 5
using namespace std;

int totale_piatti(int P[R][C])
{
    /*
    1. La funzione totale_piatti che riceva in ingresso, ovvero come parametro, una matrice di numeri interi P di sei
    righe e cinque colonne e restituisca come valore di ritorno un numero intero. Ciascuna riga della matrice P
    corrisponde a un tipo di pasta e ciascuna colonna a un condimento; ciascun elemento della matrice P contiene il
    numero di piatti serviti con un dato tipo di pasta e un dato condimento. La funzione calcolerà e restituirà come
    valore di ritorno il numero totale di piatti serviti (ovvero la somma degli elementi della matrice P).
    */
    int totpiattiserviti = 0;

    for (int i = 0; i < R; i++)
    {
        for (int k = 0; k < C; k++)
        {//ciclo su tutta la matrice e se ce un valore diverso da zero lo accumulo
            if (P[i][k] != 0)
            {

                totpiattiserviti++;
            }
        }
    }

    return totpiattiserviti;
}

double totale_ricavi(int P[R][C], double CC[R][C])
{
    /*
    2. La funzione totale_ricavi che riceva in ingresso, ovvero come parametro, una matrice di numeri interi P di sei
    righe e cinque colonne definita come nel punto 1 e una seconda matrice di numeri reali C di sei righe e cinque
    colonne e restituisca come valore di ritorno un numero reale. Gli elementi della matrice C rappresentano il prezzo
    di un piatto composto con un dato tipo di pasta e un dato condimento. La funzione calcolerà e restituirà come
    valore di ritorno il ricavo totale ottenuto dal ristorante. Nota: il ricavo totale può essere ottenuto calcolando la
    somma dei prodotti di ciascun elemento della matrice P (numero di piatti serviti) per il corrispondente elemento
    della matrice C (costo del piatto).
    */
    double ricavitotali = 0;

    for (int i = 0; i < R; i++)
    {
        for (int k = 0; k < C; k++)
        {//ogni valore di p è il numero di volte che quel piatto è stato ordinato . moltiplico quel valore per il suo relativo costo cad
            ricavitotali += P[i][k] * CC[i][k];
        }
    }

    return ricavitotali;
}

int elabora(int P[R][C], char s, int k)
{
/* 3. La funzione elabora che riceva in ingresso, ovvero come parametro, una matrice di numeri interi P di sei righe e
cinque colonne definita come nel punto 1, un carattere s e un numero intero k e restituisca come valore di ritorno
un numero intero.
La funzione opererà come segue: se il carattere s vale ‘r’ la funzione verificherà che il valore di
k sia compreso tra 0 e 5, quindi calcolerà e restituirà come valore di ritorno il numero totale di piatti serviti con il
k-esimo tipo di pasta (ovvero la somma degli elementi della k-esima riga della matrice P); se il carattere s vale ‘c’
la funzione verificherà che il valore di k sia compreso tra 0 e 4, quindi calcolerà e restituirà come valore di ritorno
il numero totale di piatti serviti con il k-esimo condimento (ovvero la somma degli elementi della k-esima colonna
della matrice P). In caso di errore (ovvero se k o s assumono valori non validi) la funzione restituirà -1.
*/

    int n = 0, check = 0;
    ;

    if (s == 'r')
    {
        if ((k >= 0) && (k <= R))
        {

            for (int i = 0; i < C; i++)
            {
                n =+P[k][i];
            }
        }
    }
    else if (s == 'c')
    {
        if ((k >= 0) && (k <= C))
        {

            for (int i = 0; i < R; i++)
            {
                n =+P[i][k];
            }
        }
    }
    else
    {
        return -1;
    }


return n;
}


int main()
{

    /*
    4. La funzione main che operi come segue: dichiari una matrice di numeri interi PT di sei righe e cinque colonne e
    una matrice di numeri reali PZ di sei righe e cinque colonne; apra in lettura il file Piatti.txt contenente una matrice
    di numeri interi di sei righe e cinque colonne e la copi nella matrice PT;
    apra in lettura il file Prezzi.txt contenente una matrice di numeri reali di sei righe e cinque colonne e la copi nella matrice PZ; chiami la funzione
    totale_ricavi di cui al punto 2 e ne stampi a video il risultato.
    */

    int PT[R][C] = {0};
    double PZ[R][C] = {0};

    fstream fileletturaPiatti;
    fstream fileletturaPrezzi;

    fileletturaPiatti.open("Piatti.txt", ios::in);
    fileletturaPrezzi.open("Prezzi.txt", ios::in);

    if (!fileletturaPiatti || !fileletturaPrezzi)
    {
        cout << "Uno dei due file non esiste!" << endl;
        return 1;
    }

    for (int i = 0; i < R; i++)
    {
        for (int k = 0; k < C; k++)
        {
            fileletturaPiatti >> PT[i][k];
            fileletturaPrezzi >> PZ[i][k];
        }
    }
    double ris=totale_ricavi(PT,PZ);

    cout<<" i ricavi totali sono : "<<ris<<endl;
    fileletturaPiatti.close();
    return 0;
}