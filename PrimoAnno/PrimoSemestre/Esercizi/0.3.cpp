/*
Si scriva la funzione C++ converti che

riceva in ingresso un array di numeri interi b e la sua dimensione n e
restituisca come valore di ritorno un numero intero.
Gli elementi dell’array b possono valere soltanto 0 oppure 1 e sono i bit della rappresentazione binaria di un numero intero positivo.

La funzione calcolerà e restituirà come valore di ritorno la rappresentazione decimale dello stesso numero.

Si scriva quindi un programma C++ che operi come segue:

allochi una stringa str di 9 caratteri e un array num di 8 numeri interi;

chieda all’utente di inserire da tastiera un byte e lo legga nella stringa str;

copi ciascun bit contenuto nella stringa nel corrispondente elemento dell’array num,
verificando che il valore del bit sia effettivamente 0 oppure 1 (altrimenti verrà stampato a video un messaggio di errore e l’utente sarà
invitato a inserire di nuovo la stringa str);

verifichi che l’utente abbia effettivamente inserito 8 bit (altrimenti, se i bit sono meno di 8, verrà stampato a video un messaggio di errore e l’utente sarà invitato ad inserire di nuovo la stringa
str);

chiami, infine, la funzione converti e stampi a video il suo valore di ritorno.
*/

#include <iostream>
using namespace std;
int converti(int b[], int size)
{
    int dec = 0;

    for (int i = 0; i < size; i++)
    {
        dec += b[i] * (1 << (size - 1 - i));
    }

    return dec;
}
int main()
{

    string str;
    int num[8];
    bool hey = 1;

    while (hey == 1)
    {

        cout << "inserisci byte" << endl;
        cin >> str;
        if (str.length() != 8)
        {
            cout << "non sono 8 bit" << endl;
            hey = 1;
            break;
        }
        for (int i = 0; i < 8; i++)
        {

            if (str[i] == '0')
            {
                num[i] = 0;
                hey = 0;
            }
            else if (str[i] == '1')
            {
                num[i] = 1;
                hey = 0;
            }
            else
            {
                cout << "Mi servono solo 0 o 1" << endl;
                
                hey = 1;
                break;
            }
        }
    }

    int ris = converti(num, 8);

    cout << "Il risultato è : " << ris << endl;
    return 0;
}