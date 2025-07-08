/*
Le squadre partecipanti al campionato sono memorizzate in un array di squadrehe.
• I risultati di tutte le partite sono memorizzati in una matrice 2D di interi, dove il valore in posizione [i][j] rappresenta il numero
di gol segnati dalla squadra i contro la squadra j.
• il numero di goal sono generati casualmente nel range da 0 a 4 per ciascuna squadra.
• Il programma deve calcolare i punti di ciascuna squadra, secondo il seguente schema:

▫ 3 punti per la vittoria, 1 punto per il pareggio, 0 punti per la sconfitta.

• In base ai punti ottenuti, il programma deve determinare la squadra vincitrice del campionato, tenendo conto anche del
numero di reti fatte e subite in caso di parità di punti.

• Il programma deve stampare a schermo i risultati finali del campionato, inclusi i punti totali, il numero di reti fatte e il numero
di reti subite per ciascuna squadra. Deve anche indicare la squadra vincitrice.
Nota: Assicurarsi di utilizzare le intestazioni appropriate per utilizzare le funzioni di generazione casuale (<cstdlib> e <ctime>).
srand(time(NULL));
int a = rand();
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define N 8
int main()
{
    srand(time(NULL));
    int gol[N][N] = {{0}};

    char squadre[N][5];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            gol[i][j] = rand() % 5;
            if (i == j)
            {
                gol[i][j] = 0; // una squadra non puo giocare contro se stessa
            }
        }
    }
    cout << "inserisci nomi di 8 squadre ( max 5 char)" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> squadre[i][j];
        }
    }
    // stampa la matrice
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << gol[i][j];
        }
        cout << endl;
    }

    // assegna i punti alla classifica campionato
    int punti[N] = {0};

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {

            if (gol[i][j] > gol[j][i])
            {
                punti[i] += 3;
            }
            if (gol[j][i] > gol[i][j])
            {
                punti[j] += 3;
            }
            if (gol[i][j] == gol[j][i])
            {
                punti[i] += 1;
                punti[j] += 1;
            }
        }
    }

    // conto i gol fatti e subiti a vicenda
    int golFattiSquadre[N] = {0};
    int golSubitiSquadre[N] = {0};

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (gol[i][j] != gol[i][j])
            {
                golFattiSquadre[i] += gol[i][j];
                golSubitiSquadre[i] += gol[j][i];
            }
        }
    }
    // stampa i punti delle squadre
    /*     for(int i =0  ; i<N ; i++){
            cout<<punti[i];
        } */

    int vincitore = punti[0];

    for (int i = 0; i < N; i++)
    {
        if (punti[i] > vincitore)
        {
            vincitore = i;
        }

        if (punti[i] == vincitore)
        {
            if (golFattiSquadre[i] > golFattiSquadre[vincitore])
            {
                vincitore = i;
            }
        }
        else
        {
            break;
        }
    }

    cout << "Risutati campionato: " << endl
         << endl;

    for (int i = 0; i < N; i++)
    {

            cout << "la squadra " << squadre[i];
        
    }

    for (int i = 0; i < N; i++)
    {

        cout << " ha totalizzato " << punti[i] << " con un totale di " << golFattiSquadre[i] << " gol fatti e " << golSubitiSquadre[i] << " gol subiti, " << endl;

    }
        cout << "La squadra che ha vinto il campionato è " << squadre[vincitore] << endl;

    return 0;
}