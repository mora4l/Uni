// Includi le librerie necessarie per I/O standard, manipolazione stringhe e gestione file/cartelle
#include <iostream>
#include <cstdio>
#include <cstring>
#include <sys/stat.h> // per mkdir
#include <unistd.h>   // per rmdir

int main() {
    // Array di char per memorizzare il nome della cartella

    // Variabile per memorizzare il numero di file da creare

    // Chiedi all'utente il nome della cartella

    // Leggi la stringa da input e salvala in nomeCartella

    // Chiedi all'utente quanti file creare

    // Leggi il numero di file

    // Rimuove il newline residuo nel buffer dopo la lettura del numero

    // Crea la cartella con permessi 0755

        // Stampa un messaggio di errore se la creazione della cartella fallisce

        // Termina il programma
        return 1; 

    // Ciclo per creare i file numerati all'interno della cartella

        // Array di char per costruire il nome del file

        // Combina percorso della cartella, nome base e numero del file in nomeFile

        // Crea il file in modalità scrittura

        // Controlla se la creazione del file fallisce

            // Stampa un messaggio di errore e continua con il prossimo file

        // Scrive una linea di testo nel file

        // Chiude il file per salvare i dati

    // Buffer per memorizzare il comando dell'utente per cancellare i file

    // Ciclo fino a quando l'utente scrive "cancella"

        // Chiede all'utente di scrivere "cancella" per rimuovere tutto

        // Legge il comando inserito


    // Ciclo per cancellare tutti i file creati

        // Array di char per costruire il nome del file da cancellare

        // Ricostruisce il nome del file da cancellare

        // Cancella il file

            // Segnala eventuali errori nella cancellazione del file

    // Cancella la cartella

        // Segnala eventuali errori nella cancellazione della cartella

        // Messaggio di successo

    // Termina il programma
    return 0; 
}
