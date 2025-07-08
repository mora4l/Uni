/*
Otto sensori trasmettono dati ad un server attraverso una connessione di rete. Per trasmettere i dati, i sensori utilizzano
tre diversi tipi di messaggi, rappresentati con stringhe di sei caratteri ed organizzati come segue:

- Messaggio di inizio trasmissione: ST<<numero identificativo del sensore>>000. Il numero identificativo del
sensore assume valori da 0 (per il primo sensore) a 7 (per l’ottavo sensore). Ad esempio, il secondo sensore
segnalerà l’inizio della trasmissione inviando il messaggio “ST1000”.

- Messaggio di trasmissione dati: DT<<numero identificativo del sensore>><<dati: valore intero di 3 cifre>>. Ad
esempio, per mandare al server il valore 358, il quinto sensore invierà il seguente messaggio: “DT4358”.


- Messaggio di fine trasmissione: ET<<numero identificativo del sensore>>000. Ad esempio, il quarto sensore
segnalerà la fine della trasmissione inviando il messaggio “ET3000”.

Allo scopo di elaborare sul server i messaggi inviati dai sensori, si sviluppi quanto segue in linguaggio C++:


*/

#include <iostream>
#include <fstream>
using namespace std;

int all(int A[], int n)
{
    /*
    1. La funzione all che riceva come parametro un array di numeri interi a e la sua dimensione n e restituisca come
    valore di ritorno un numero intero. La funzione restituirà 1 se tutti gli elementi di a sono diversi da zero e 0 se
    almeno un elemento di a vale zero.
    */

    int values = 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i] == 0)
        {
            break;
        }
        else
        {
            values = 1;
        }
    }

    return values;
}

/*
2. La funzione converti che riceva come parametro una stringa s di 3 caratteri numerici (più il carattere nullo) e,
dopo aver verificato che la stringa sia interamente costituita da caratteri numerici (a parte il carattere nullo),
restituisca come valore di ritorno il corrispondente numero intero. Ad esempio, se la funzione riceve in ingresso la
stringa “369”, restituirà come valore di ritorno il numero intero 369. Nel caso in cui la stringa s contenga almeno
un carattere non valido (ovvero s contenga almeno un carattere non numerico), la funzione restituirà -1.
*/

int converti(string s)
{

    int n = 0, numerico = 0;
    char c;
    for (int i = 0; i < s.size() - 1; i++)
    {
        c = s[i];
        if (isdigit(c))
        {
            n = n * 10 + (c - '0');
        }
        else
        {
            n = -1;
            break;
        }
    }
    return n;
}


int elabora(string msg, int &ns, int &val)
/*
3. La funzione elabora che riceva come parametro in ingresso una stringa msg di 6 caratteri (più il carattere nullo)
contenente un messaggio inviato da un sensore e come parametri di uscita due numeri interi ns e val e restituisca
come valore di ritorno un numero intero. Dopo aver identificato il tipo di messaggio dai primi due caratteri della
stringa msg, la funzione opererà come segue:
in caso si tratti di un messaggio di inizio trasmissione, la funzione
assegnerà il numero identificativo del sensore al parametro ns, il valore -1 al parametro val e restituirà 1 come
valore di ritorno;

in caso si tratti di un messaggio di trasmissione dati, la funzione assegnerà il numero identificativo del sensore al parametro ns, il valore del dato,
calcolato usando la funzione converti di cui al punto
2, al parametro val e restituirà 2 come valore di ritorno;

in caso si tratti di un messaggio di fine trasmissione, la
funzione assegnerà il numero identificativo del sensore al parametro ns, il valore -1 al parametro val e restituirà 3
come valore di ritorno; nel caso in cui il tipo di messaggio non sia valido la funzione assegnerà il valore -1 ad
entrambi i parametri di uscita e restituirà 0 come valore di ritorno.
*/
{
    int n = 0, scelta = 0;

    if ((msg[0] == 'S') && (msg[1] == 'T'))
    {
        scelta = 1;
    }
    else if ((msg[0] == 'D') && (msg[1] == 'T'))
    {
        scelta = 2;
    }
    else if ((msg[0] == 'E') && (msg[1] == 'T'))
    {
        scelta = 3;
    }

    switch (scelta)
    {
    case 1:

        cout << " Il messaggio è di inizio trasmissione" << endl;
        ns = msg[2] - '0';
        cout << "Il valore identificativo del sensore è " << ns << endl;
        val = -1;
        n = 1;
        break;

    case 2:

        cout << " Il messaggio è di trasmissione dati" << endl;

        ns = msg[2] - '0';
        cout << "Il valore identificativo del sensore è " << ns << endl;

        val = converti(msg);
        n = 2;
        break;

    case 3:
        cout << " Il messaggio è di fine trasmissione" << endl;

        ns = msg[2] - '0';
        cout << "Il valore identificativo del sensore è " << ns << endl;

        val = -1;
        n = 3;
        break;

    default:
        cout << " Il messaggio non è valido" << endl;

        n = 0;
        val = -1;
        ns = -1;
    }

    return n;
}

int main()
{
    /*
    4. La funzione main che operi come segue: dichiari un array dt di otto numeri interi e inizializzi tutti i suoi elementi
    a zero; apra in lettura il file Messaggi.txt contenente per ciascuna riga un messaggio pervenuto da un sensore (il
    numero di righe di cui è composto il file non è noto al programmatore); legga il file Messaggi.txt e per ciascun
    messaggio chiami la funzione elabora di cui al punto 3;

     in caso si tratti di un messaggio di trasmissione dati,
    sommi il valore trasmesso al corrispondente elemento dell’array dt (ad esempio, se il terzo sensore ha trasmesso il
    valore 193, tale valore sarà sommato al terzo elemento dell’array dt); prima di terminare, verifichi se tutti i
    sensori hanno trasmesso dati chiamando la funzione all di cui al punto 1 e stampandone a video il risultato.
    */
    int n = 8;
    int dt[n] = {0}, ns = 0, val = 0;
    string message;
    fstream filelettura;

    filelettura.open("MessaggiSensori.txt", ios::in);
    if (!filelettura)
    {
        return -1;
    }
    int i = 0;
    while (!filelettura.eof())
    {
        cout << "leggo messaggio " << i << endl
             << endl
             << endl;
        getline(filelettura, message);
        int trasmission = elabora(message, ns, val);
        if (trasmission == 2)
        {
            dt[ns] += val;
        }
        i++;
    }

    int ris = all(dt, n);

    return 0;
}