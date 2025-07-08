/*
Scrivere un programma in C++ per gestire un inventario di macchine in un magazzino. L'utente deve poter inserire i dati di un numero
prefissato di macchine (ad esempio, n=3) e il programma dovrà memorizzare e stampare questi dati.
*/
/*
Si definisce
• una struttura Macchina che contiene informazioni relative a ciascun veicolo, come:
Tipo (stringa di caratteri): Tipo di macchina (es. SUV, berlina, ecc.)
Marca (stringa di caratteri): Marca della macchina (es. Fiat, BMW, ecc.)
Targa (stringa di caratteri di lunghezza 7): Targa della macchina.
Anno (intero): Anno di fabbricazione della macchina.
*/
#include <iostream>
#include <cstring>
using namespace std;
struct Macchina
{
    char tipo[20];
    char marca[20];
    char targa[8];
    int anno;
};
/*

• Funzione inseriscidati: Permette all'utente di inserire i dati relativi a ciascuna macchina (marca, tipo, targa, anno). I dati vengono
memorizzati in una struttura di tipo Macchina, il cui indirizzo viene passato come parametro.
*/

void inseriscidati(Macchina *macchine[], int numcar)
{

    cout << "inserimento dati della macchina:" << endl;

    for (int i = 0; i < numcar; i++)
    {
        macchine[i] = new Macchina;
        cout << "macchina n°" << i << endl;
        cout << "tipologia :" << endl;
        cin >> macchine[i]->tipo;

        cout << "marca:" << endl;
        cin >> macchine[i]->marca;
        cout << "targa (7 char):" << endl;
        cin >> macchine[i]->targa;
        cout << "anno:" << endl;
        cin >> macchine[i]->anno;
    }
}
/*
• Funzione stampa: Stampa i dati di ciascuna macchina contenuti nell'inventario. Mostra le informazioni come la marca, il tipo, la
targa e l'anno della macchina. La funzione prende come parametro l'indirizzo della struttura.
*/
void stampa(Macchina *macchine[], int numcar)
{

    cout << endl
         << endl
         << "stampa dati delle macchine:" << endl;
    for (int i = 0; i < numcar; i++)
    {
        cout << "macchina n°" << i << endl;
        cout << "tipo:";
        cout << macchine[i]->tipo << endl;
        cout << "marca:" << endl;
        cout << macchine[i]->marca << endl;
        cout << "targa:";
        cout << macchine[i]->targa << endl;
        cout << "anno:";
        cout << macchine[i]->anno << endl;
    }
}

void aggiungi(Macchina *macchine[], int numcar, int carplus)
{

    Macchina *nuovecar[numcar + carplus];
    // copio i dati 1
    for (int i = 0; i < numcar; i++)
    {
        nuovecar[i] = new Macchina;

        strcpy(nuovecar[i]->tipo, macchine[i]->tipo);
        strcpy(nuovecar[i]->marca, macchine[i]->marca);
        strcpy(nuovecar[i]->targa, macchine[i]->targa);
        nuovecar[i]->anno = macchine[i]->anno;
    }
    cout << "inserimento dati della macchina:" << endl;
    for (int i = numcar; i < numcar + carplus; i++)
    {
        nuovecar[i] = new Macchina;

        cout << "macchina n°" << i << endl;

        cout << "tipologia :" << endl;
        cin >> nuovecar[i]->tipo;

        cout << "marca:" << endl;
        cin >> nuovecar[i]->marca;

        cout << "targa (7 char):" << endl;
        cin >> nuovecar[i]->targa;

        cout << "anno:" << endl;
        cin >> nuovecar[i]->anno;
    }

    cout << endl
         << endl
         << "stampa dati delle macchine nuove:" << endl;

    for (int i = 0; i < carplus + numcar; i++)
    {
        cout << "macchina n°" << i << endl;
        cout << "tipo:";
        cout << nuovecar[i]->tipo << endl;
        cout << "marca:";
        cout << nuovecar[i]->marca << endl;
        cout << "targa:";
        cout << nuovecar[i]->targa << endl;
        cout << "anno:";
        cout << nuovecar[i]->anno << endl;
    }
}

void rimuovi(Macchina *macchine[], int numcar, char targadel[])
{
    int pos = 0;
    for (int i = 0; i < numcar; i++)
    {
        if (strcmp(macchine[i]->targa, targadel) == 0)
        {
            pos = i;
        }
    }

    delete macchine[pos];

    for (int i = pos; i < numcar - 1; i++)
    {
        macchine[i] = macchine[i + 1];
    }

    numcar--; // Riduce il numero totale di macchine

    cout << endl
         << endl
         << "stampa dati delle macchine senza quella eliminata:" << endl;
    for (int i = numcar; i < numcar - 1; i++)
    {
        cout << "macchina n°" << i << endl;
        cout << "tipo:";
        cout << macchine[i]->tipo << endl;
        cout << "marca:" << endl;
        cout << macchine[i]->marca << endl;
        cout << "targa:";
        cout << macchine[i]->targa << endl;
        cout << "anno:";
        cout << macchine[i]->anno << endl;
    }
}
/*
Utilizzando la memoria dinamica, viene allocato un array di puntatori a Macchina. Ogni puntatore dell'array viene utilizzato per
memorizzare una macchina, in modo che i dati possano essere gestiti in modo flessibile. Dopo che tutte le macchine sono state
inserite, il programma stampa l'inventario.
*/

int main()
{
    cout << "quante macchine vuoi memorizzare?" << endl;
    int numcar = 0;
    cin >> numcar;

    Macchina *macchine[numcar];

    inseriscidati(macchine, numcar);
    stampa(macchine, numcar);
    /*
    Dopo aver fatto inserire un numero iniziale di macchine, date la possibilità
    all'utente di aggiungere ulteriori macchine nell'inventario oppure di
    rimuoverle, scegliendo la targa della macchina.

    • Per fare ciò, sarà necessario riallocare la memoria (creare una nuova
    struttura dati più grande o più piccola, copiando i dati dal precedente
    array e facendo inserire i nuovi dati dall'utente).
    */

    cout << "vuoi rimuovere[1] o aggiungere[0] altre macchine? " << endl;

    int scelta = 0;

    cin >> scelta;
    if (scelta == 0)
    {
        cout << "quante macchine in più devi aggiungere?" << endl;
        int carplus = 0;
        cin >> carplus;
        aggiungi(macchine, numcar, carplus);
    }
    else
    {
        cout << "inserisci la targa dell'auto che vuoi eliminare" << endl;
        char targadel[8];

        cin >> targadel;
        rimuovi(macchine, numcar, targadel);
    }
    return 0;
}