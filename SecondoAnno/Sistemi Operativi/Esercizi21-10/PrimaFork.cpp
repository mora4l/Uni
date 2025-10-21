#include <iostream>
#include <unistd.h>   //per la fork
#include <sys/wait.h> //per la wait

using namespace std;

int main()
{

    int x = 100;

    cout << "prima della fork, x vale " << x << endl;

    pid_t pid = fork(); // la fork restituisce un tipo pid_t

    // ora ho due processi identici con due pid diversi
    // vado a controllare il pid per capire se è padre o figlio . non faccio controlli sugli errori , anche se dovrei

    if (pid == 0)
    {
        cout << "sono il figlio " << endl;

        x += 50;

        cout << "Figlio PID: " << getpid() << "x: " << x << endl;

        sleep(1000) ;//aggiungo un attesa
    }
    else
    {
        cout << "sono il padre " << endl;

        x -= 50;

        cout << "Padre PID: " << getpid() << "x: " << x << endl;

        //poi il genitore fa una wait che permette di passare lo stato del processo figlio

        sleep(1000) ; //aggiungo un attesa anche qua

        wait(NULL) ; 
    }

    return 0;
}