#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <iostream>
#include <string>

/* Versione con FILE CONDIVISO e read/write:

- Padre scrive nel file con write().
- Figlio legge dal file con read().
- Quando scrivono a schermo usano cout.
- Quando acquisiscono input da tastiera usano cin.
*/

int main() {
    // Creazione di un nuovo processo tramite fork
    pid_t pid = fork();

    if (pid < 0) {
        // Controllo errore fork
        perror("fork error");
        exit(1);
    }

    // ----------------------
    // FIGLIO
    // ----------------------
    if (pid == 0) {
        // Apre lo stesso file del padre, solo in lettura
        int fd = open("comune.txt", O_RDONLY);
        if (fd < 0) {
            perror("open child error");
            exit(1);
        }

        // buffer per leggere dal file
        char buffer[256];
        // variabile per memorizzare il numero di byte letti
        ssize_t n;

        while(1){
            // Il figlio legge tutto ciò che trova nel file
            while ((n = read(fd, buffer, sizeof(buffer)-1)) > 0) {
                buffer[n] = '\0';
                // SCRITTURA SU SCHERMO con cout
                std::cout << std::endl << "[FIGLIO legge]: " << buffer << std::endl;
                // Controlla se la stringa letta è "0" per terminare
                if (strcmp(buffer, "0")==0)
                    break;
            }
        }

        // Messaggio di terminazione del figlio
        std::cout << "Esce figlio" << std::endl;
        // chiusura file
        close(fd);
        return 0;
    }

    // ----------------------
    // PADRE
    // ----------------------
    else {
        // Padre apre il file in scrittura (lo crea/azzera)
        int fd = open("comune.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd < 0) {
            // Controllo apertura file padre
            perror("open parent error");
            exit(1);
        }

        char frase[256];
        while (true) {
            // INPUT DA UTENTE con cin
            std::cout << "Inserisci frase (0 per uscire): ";
            std::cin.getline(frase, sizeof(frase));

            // Scrive la frase nel file con write
            write(fd, frase, strlen(frase));

            // Se l'utente inserisce "0" termina il ciclo
            if (strcmp(frase, "0") == 0)
                break;
        }

        // Messaggio di terminazione del padre
        std::cout << "Esce padre" << std::endl;
        // chiusura file
        close(fd);
        return 0;
    }
}
