/* Si scriva un programma in linguaggio C++ che
apra in lettura il file "ciao.txt" e
generi come output due file chiamati "consonanti.txt" e "vocali.txt".
Il file "ciao.txt" contiene un testo di lunghezza non nota al programmatore che il programma leggerà carattere per carattere.
Il programma inserirà nel file "consonanti.txt" tutte e sole le consonanti presenti nel file "ciao.txt" e
nel file "vocali.txt" tutte e sole le vocali presenti nel file "ciao.txt".
Al termine della lettura del file "ciao.txt", il programma stamperà a video il numero complessivo di caratteri letti.

Esempio: se il file "ciao.txt" conƟene il testo "prova a fare l'esercizio", il file
"consonanƟ.txt" conterrà i caratteri"prvfrlsrcz" e il file "vocali.txt" i caratteri "oaaaeeeiio". */

#include <iostream>
#include <fstream>
#define M 500
using namespace std;

int main()
{

    fstream filetext;
    fstream filevoc;
    fstream filecons;
    char voc[12] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    char con[42] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z',
                    'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};

    char vocali[M];
    char consonanti[M];
    char c;
    int i = 0;

    filecons.open("consonanti.txt", ios::app);
    filevoc.open("vocali.txt", ios::app);
    filetext.open("file.txt", ios::in);

    if (!filetext || !filevoc || !filecons)
    {
        cerr << "errore nell'apertura di un file" << endl;
        return 1;
    }
    while (filetext.get(c))
    {
        for (int i = 0; i < sizeof(voc); i++)
        {
            if (c == voc[i])
            {
                vocali[i] = c;
                filevoc << vocali[i];
            }
        }
        for (int i = 0; i < sizeof(con); i++)
        {
            if (c == con[i])
            {
                consonanti[i] = c;
                filecons << consonanti[i];
            }
        }

        i++;
    }

    cout << "ho letto " << i << " caratteri" << endl;
    filecons.close();
    filevoc.close();
    filetext.close();
    return 0;
}