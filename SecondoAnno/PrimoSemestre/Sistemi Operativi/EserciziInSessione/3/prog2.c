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
    fd = open("frase.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Errore apertura file in scrittura");
        exit(EXIT_FAILURE);
    }

    // Scrittura dell'intera frase dentro il file
    write(fd, buffer, strlen(buffer));

    // Chiudo il file dopo la scrittura
    close(fd);


    // --- APERTURA FILE IN LETTURA ---
    fd = open("frase.txt", O_RDONLY);
    if (fd == -1) {
        perror("Errore apertura file in lettura");
        exit(EXIT_FAILURE);
    }

    // --- LETTURA + LSEEK ---
    char ch;

    // Ciclo infinito che interromperemo quando read() o lseek() falliscono
    while (1) {

        // Leggo un singolo byte
        ssize_t n = read(fd, &ch, 1);

        // Se n == 0 siamo a EOF → fine file → esco
        if (n == 0)
            break;

        // Se n == -1 è avvenuto un errore nella lettura
        if (n == -1) {
            perror("Errore lettura");
            exit(EXIT_FAILURE);
        }

        // --- STAMPA DEL CARATTERE LETTO ---
        // Questo è il carattere "dispari", perché ogni volta saltiamo quello dopo
        putchar(ch);

        // --- LSEEK ---
        // Salto un byte avanti nel file (cioè ignoro il prossimo carattere)
        // SEEK_CUR = spostamento relativo alla posizione attuale
        if (lseek(fd, 1, SEEK_CUR) == -1) {
            // Se lseek fallisce significa che non c'è più un carattere da saltare
            // quindi abbiamo finito la lettura
            break;
        }
    }

    // Chiudo il file alla fine
    close(fd);

    return 0;
}