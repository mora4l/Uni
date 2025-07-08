/*
Il file "dati.txt" contiene le età in anni dei membri di un certo numero di gruppi di lavoro operanti all’interno di un’azienda.

Ciascuna riga del file contiene le seguenti informazioni:

un codice identificativo del gruppo (una stringa consistente di una sola parola contenente al massimo 16 caratteri),
il numero di membri del gruppo (un numero intero),
le età in anni di ciascun membro del gruppo (un numero intero per ciascun membro).

Il numero di righe di cui il file si compone non è noto al programmatore.

Si scriva un programma in linguaggio C++ che apra in lettura il file "dati.txt",
lo scandisca e stampi a video l’identificativo di ciascun gruppo seguito dall’età media dei suoi componenti.

Si supponga, per semplicità, che i valori contenuti nel file siano validi.
*/
#include <iostream>
#include <fstream>
using namespace std;
int main()
{

    std::fstream file;

    file.open("dati.txt", std::ios::in);
    if (!file)
    {
        cout << "c'e stato un errore";
        exit(1);
    }

    char nomi[16] = "";
    int numeropersone = 0;

    file >> nomi >> numeropersone;

    while (!file.eof())
    {
        int valore = 0, eta = 0;

        for (int i = 1; i <= numeropersone; i++)
        {
            file >> valore;
            eta += valore;
        }

        double media = double(eta) / numeropersone;

        std::cout << " il gruppo: " << nomi << " ha l'eta media di " << media << " anni" << endl;

        file >> nomi >> numeropersone;
    }

    file.close();
    return 0;
}