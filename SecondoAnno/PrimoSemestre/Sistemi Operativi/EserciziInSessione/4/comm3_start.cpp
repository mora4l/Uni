// Inclusione librerie di input/output standard
#include <iostream>

// Librerie POSIX per la gestione delle directory
#include <sys/types.h>
#include <dirent.h>

// Librerie per ottenere informazioni sui file tramite stat()
#include <sys/stat.h>
#include <unistd.h>

int main() {

    // Puntatore alla directory che vogliamo aprire

    // Struttura che rappresenta una singola entry (file o directory) trovata

    // Apriamo la directory corrente "."

    // Verifichiamo che l'apertura sia andata a buon fine
        // In caso di errore, stampa un messaggio automatico

    // Ciclo per leggere ogni entry della directory
    // readdir() restituisce un puntatore alla entry successiva o NULL a fine directory

        // Struttura che conterrà i dati ottenuti da stat()

        // Chiamiamo stat() sul nome del file per ottenerne le proprietà
        // stat() restituisce -1 in caso di errore

        // Filtriamo solo file regolari e directory
        // Ignoriamo link simbolici, socket, device, pipe...

        // Stampa del nome della entry

        // Determiniamo il tipo grazie ai macro di stat

        // Stampa della dimensione in byte

        // Separatore visivo

    // Chiudiamo la directory dopo aver finito

    // Fine del programma
    return 0;
}
