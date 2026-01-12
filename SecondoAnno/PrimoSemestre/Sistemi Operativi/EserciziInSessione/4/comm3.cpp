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
    DIR *dir;

    // Struttura che rappresenta una singola entry (file o directory) trovata
    struct dirent *entry;

    // Apriamo la directory corrente "."
    dir = opendir(".");

    // Verifichiamo che l'apertura sia andata a buon fine
    if (!dir) {
        // In caso di errore, stampa un messaggio automatico
        perror("opendir");
        return 1;  // Esce con codice di errore
    }

    // Ciclo per leggere ogni entry della directory
    // readdir() restituisce un puntatore alla entry successiva o NULL a fine directory
    while ((entry = readdir(dir)) != NULL) {

        // Struttura che conterrà i dati ottenuti da stat()
        struct stat st;

        // Chiamiamo stat() sul nome del file per ottenerne le proprietà
        // stat() restituisce -1 in caso di errore
        if (stat(entry->d_name, &st) == -1) {
            perror("stat");  // Stampa un messaggio di errore
            continue;        // Salta alla prossima entry
        }

        // Filtriamo solo file regolari e directory
        // Ignoriamo link simbolici, socket, device, pipe...
        if (!S_ISREG(st.st_mode) && !S_ISDIR(st.st_mode))
            continue;

        // Stampa del nome della entry
        std::cout << "Nome: " << entry->d_name << "\n";

        // Determiniamo il tipo grazie ai macro di stat
        if (S_ISREG(st.st_mode))
            std::cout << "Tipo: File\n";
        else if (S_ISDIR(st.st_mode))
            std::cout << "Tipo: Directory\n";

        // Stampa della dimensione in byte
        std::cout << "Dimensione: " << st.st_size << " byte\n";

        // Separatore visivo
        std::cout << "----------------------------------------\n";
    }

    // Chiudiamo la directory dopo aver finito
    closedir(dir);

    // Fine del programma
    return 0;
}
