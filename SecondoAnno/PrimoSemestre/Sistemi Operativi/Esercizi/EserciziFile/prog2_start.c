#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>      // per open()
#include <unistd.h>     // per read(), write(), close(), lseek()
#include <string.h>     // per strlen()

int main() {
    int fd;
    char buffer[256];

    // --- INPUT DA STANDARD INPUT ---
    printf("Inserisci una frase: ");
    fgets(buffer, sizeof(buffer), stdin);

    // --- APERTURA FILE IN SCRITTURA ---

    // Scrittura dell'intera frase dentro il file

    // Chiudo il file dopo la scrittura


    // --- APERTURA FILE IN LETTURA ---

    // --- LETTURA + LSEEK ---
    char ch;

    // Ciclo infinito che interromperemo quando read() o lseek() falliscono
    while (1) {

        // Leggo un singolo byte

        // Se n == 0 siamo a EOF → fine file → esco
        if (n == 0)
            break;

        // --- STAMPA DEL CARATTERE LETTO ---
        // Questo è il carattere "dispari", perché ogni volta saltiamo quello dopo
        putchar(ch);

        // --- LSEEK ---
        // Salto un byte avanti nel file (cioè ignoro il prossimo carattere)
        // SEEK_CUR = spostamento relativo alla posizione attuale
    }

    // Chiudo il file alla fine

    return 0;
}