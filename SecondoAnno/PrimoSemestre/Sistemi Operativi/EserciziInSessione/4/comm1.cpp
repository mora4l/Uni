// Includi le librerie necessarie per lavorare con pipe, fork, wait e I/O
#include <unistd.h>    
#include <sys/wait.h>  
#include <iostream>    
#include <string>      
#include <cstring>     

/*
Obiettivo: creare una comunicazione tra padre e figlio usando una pipe.
Il padre scrive sulla pipe quello che legge da tastiera.
Il figlio legge dalla pipe e stampa su schermo.
Quando il padre inserisce "0", entrambi terminano.
*/

int main() {
    // Crea un array di due interi per i file descriptor della pipe
    int pipefd[2]; 

    // Crea una pipe e controlla eventuali errori
    if (pipe(pipefd) < 0) {  
        // Stampa un messaggio di errore se la pipe non viene creata
        perror("pipe error"); 
        // Termina il programma se la pipe non può essere creata
        exit(1);             
    }

    // Crea un nuovo processo figlio tramite fork e memorizza il pid
    pid_t pid = fork();
    // Controlla se fork ha fallito
    if (pid < 0) { 
        // Stampa errore se fork fallisce
        perror("fork error"); 
        // Termina il programma se non è possibile creare il figlio
        exit(1);              
    }

    // ---------------------- FIGLIO ----------------------
    // Se pid == 0 siamo nel processo figlio
    if (pid == 0) { 
        // Chiudi l'estremità di scrittura della pipe, il figlio legge solo
        close(pipefd[1]); 

        // Prepara un buffer per leggere i dati dalla pipe
        char buffer[256]; 
        // Variabile per memorizzare quanti byte sono stati letti
        ssize_t n;        

        // Ciclo continuo per leggere dalla pipe fino a fine dati
        while ((n = read(pipefd[0], buffer, sizeof(buffer)-1)) > 0) {
            // Aggiungi il terminatore di stringa alla fine del buffer
            buffer[n] = '\0'; 
            // Stampa il contenuto letto dalla pipe
            std::cout << "[FIGLIO legge]: " << buffer << std::endl; 
            // Controlla se il contenuto letto è "0" per terminare
            if (strcmp(buffer, "0\n") == 0 || strcmp(buffer, "0") == 0)
                break; 
        }

        // Stampa messaggio di terminazione del figlio
        std::cout << "Esce figlio" << std::endl; 
        // Chiudi l'estremità di lettura della pipe
        close(pipefd[0]); 
        // Termina il processo figlio
        return 0;         
    } 
    // ---------------------- PADRE ----------------------
    // Se pid > 0 siamo nel processo padre
    else { 
        // Chiudi l'estremità di lettura della pipe, il padre scrive solo
        close(pipefd[0]); 

        // Prepara una stringa per leggere l'input dell'utente
        std::string frase;
        // Ciclo continuo per leggere input e scriverlo sulla pipe
        while (true) {
            // Chiedi all'utente di inserire una frase
            std::cout << "Inserisci frase (0 per uscire): ";
            // Leggi la riga inserita dall'utente
            std::getline(std::cin, frase);

            // Scrivi la frase sulla pipe
            write(pipefd[1], frase.c_str(), frase.size());
            // Aggiungi un newline alla pipe
            write(pipefd[1], "\n", 1); 

            // Se l'utente inserisce "0", esci dal ciclo
            if (frase == "0") break;
        }

        // Stampa messaggio di terminazione del padre
        std::cout << "Esce padre" << std::endl; 
        // Chiudi l'estremità di scrittura della pipe
        close(pipefd[1]);
        // Aspetta che il figlio termini
        wait(NULL);
        // Termina il processo padre
        return 0;
    }
}
