// Includi le librerie necessarie per I/O standard, manipolazione stringhe e gestione file/cartelle
#include <iostream>
#include <cstdio>
#include <cstring>
#include <sys/stat.h> // per mkdir
#include <unistd.h>   // per rmdir

int main() {
    // Array di char per memorizzare il nome della cartella
    char nomeCartella[256]; 
    // Variabile per memorizzare il numero di file da creare
    int numeroFile;         

    // Chiedi all'utente il nome della cartella
    std::cout << "Inserisci il nome della cartella: ";
    // Leggi la stringa da input e salvala in nomeCartella
    std::cin.getline(nomeCartella, sizeof(nomeCartella)); 

    // Chiedi all'utente quanti file creare
    std::cout << "Inserisci il numero di file da creare: ";
    // Leggi il numero di file
    std::cin >> numeroFile;
    // Rimuove il newline residuo nel buffer dopo la lettura del numero
    std::cin.ignore(); 

    // Crea la cartella con permessi 0755
    if (mkdir(nomeCartella, 0755) != 0) {
        // Stampa un messaggio di errore se la creazione della cartella fallisce
        perror("Errore nella creazione della cartella");
        // Termina il programma
        return 1; 
    }

    // Ciclo per creare i file numerati all'interno della cartella
    for (int i = 1; i <= numeroFile; ++i) {
        // Array di char per costruire il nome del file
        char nomeFile[512]; 
        // Combina percorso della cartella, nome base e numero del file in nomeFile
        snprintf(nomeFile, sizeof(nomeFile), "%s/%s%d.txt", nomeCartella, nomeCartella, i);

        // Crea il file in modalità scrittura
        FILE* f = fopen(nomeFile, "w");
        // Controlla se la creazione del file fallisce
        if (f == nullptr) {
            // Stampa un messaggio di errore e continua con il prossimo file
            perror("Errore nella creazione del file");
            continue;
        }

        // Scrive una linea di testo nel file
        fprintf(f, "Questo è il file numero %d\n", i);

        // Chiude il file per salvare i dati
        fclose(f);
    }

    // Buffer per memorizzare il comando dell'utente per cancellare i file
    char comando[256]; 
    // Ciclo fino a quando l'utente scrive "cancella"
    do {
        // Chiede all'utente di scrivere "cancella" per rimuovere tutto
        std::cout << "Scrivi 'cancella' per rimuovere tutti i file e la cartella: ";
        // Legge il comando inserito
        std::cin.getline(comando, sizeof(comando)); 
    } while (strcmp(comando, "cancella") != 0); 

    // Ciclo per cancellare tutti i file creati
    for (int i = 1; i <= numeroFile; ++i) {
        // Array di char per costruire il nome del file da cancellare
        char nomeFile[512]; 
        // Ricostruisce il nome del file da cancellare
        snprintf(nomeFile, sizeof(nomeFile), "%s/%s%d.txt", nomeCartella, nomeCartella, i);

        // Cancella il file
        if (remove(nomeFile) != 0) {
            // Segnala eventuali errori nella cancellazione del file
            perror("Errore nella cancellazione del file"); 
        }
    }

    // Cancella la cartella
    if (rmdir(nomeCartella) != 0) {
        // Segnala eventuali errori nella cancellazione della cartella
        perror("Errore nella cancellazione della cartella"); 
    } else {
        // Messaggio di successo
        std::cout << "Tutti i file e la cartella sono stati rimossi con successo.\n";
    }

    // Termina il programma
    return 0; 
}
