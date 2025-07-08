/*
Scrivere un programma in C++ che utilizzi una funzione ricorsiva per determinare se una parola inserita
dall'utente è palindroma. Una parola si dice palindroma se può essere letta nello stesso modo da
sinistra verso destra e da destra verso sinistra (ad esempio, "radar", "amoroma" sono parole
palindromi).
• La funzione ricorsiva dovrà confrontare i caratteri alle estremità della parola (primo e ultimo,
secondo e penultimo, ecc.) e, se sono uguali, proseguire il confronto per la parte centrale della
parola.
• Se la parola è palindroma, la funzione restituirà true; altrimenti, restituirà false.
• Scrivere il programma che:
▫ acquisisce una parola dall'utente,
▫ chiama la funzione ricorsiva verifica se la parola è palindroma,
▫ stampa il risultato (palindroma o non palindroma) a schermo.
*/
#include <iostream>
#include <cstring>
using namespace std;

bool palindroma(string parola, int indice, int indicecontrario, bool var)
{
    if (indice != indicecontrario)
    {
        cout << "ok non sono al centro " << endl;
        if (parola[indice] == parola[indicecontrario])
        {
            cout << "ok le due lettere sono uguali " << endl;
            indice++;
            indicecontrario--;
            palindroma(parola, indice++, indicecontrario--, var);
        }
        else
        {
            cout << "non sono al centro ma no , le lettere sono diverse. ritorno il falso " << endl;
            var = false;
            return var;
        }
    }
    cout << "è palindroma" << endl;
    var = true;
    return var;
}
int main()
{

    string parola;
    cout << "inserisci parola" << endl;
    cin >> parola;

    bool var = true;
    int indice = 0;
    int indicecontrario = parola.length() - 1;
    bool risposta = palindroma(parola, indice, indicecontrario, var);

    cout << risposta;
    return 0;
}