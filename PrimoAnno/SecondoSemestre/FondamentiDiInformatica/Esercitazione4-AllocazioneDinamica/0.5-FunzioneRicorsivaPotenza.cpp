/*
Si scriva in C++ una funzione ricorsiva che, dati due numeri interi M ed N ricevuti come parametri,
verifichi che N sia nullo (se N è nullo, la funzione termina restituendo 1), calcoli e restituisca come valore
di ritorno la potenza MN (un numero intero).
• Si scriva quindi un programma C++ per verificare il corretto funzionamento della funzione.
• Il programma chiederà all’utente di inserire una tastiera due numeri interi, chiamerà la funzione e
stamperà a video il suo valore di ritorno. Le operazioni si ripeteranno finché l’utente lo desidera.
Per fare di piu: Estendere la funzione in modo che possa ricevere un esponente negativo.
In tal caso, la funzione restituirà il valore M(-N) = 1 / MN.
*/

#include <iostream>
using namespace std;
int ricorsiva(int M, int N)
{
    int ret = 0;
    if (N == 0)
    {
        return 1;
    }

    return M * ricorsiva(M, N - 1);
}
int main()
{
    int scelta = 1;

    do
    {
        cout << "inserisci valore 1" << endl;
        int val1 = 0;
        cin >> val1;

        cout << "inserisci valore 2" << endl;
        int val2 = 0;
        cin >> val2;

        int risultato = ricorsiva(val1, val2);

        cout << "Il risultato è:" << risultato << endl;

        cout << "per terminare digita 0 " << endl;
        cin >> scelta;
    } while (scelta != 0);

    return 0;
}