#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>      // per open()
#include <unistd.h>     // per read(), write(), close(), lseek()
#include <string.h>     // per strlen()

int main() {
    int fd;
    char buffer[4];

    // --- INPUT DA STANDARD INPUT ---
    printf("Inserisci una frase: ");
    fgets(buffer, sizeof(buffer), stdin);

    // --- APERTURA FILE IN SCRITTURA ---
    fd=open("file2.txt",O_CREAT|O_WRONLY|O_TRUNC,0644);
    // Scrittura dell'intera frase dentro il file
    write(fd,buffer,strlen(buffer));
    // Chiudo il file dopo la scrittura
    close(fd);

    // --- APERTURA FILE IN LETTURA ---
    fd=open("file2.txt",O_RDONLY);
    // --- LETTURA + LSEEK ---
    char ch;

    // Ciclo infinito che interromperemo quando read() o lseek() falliscono
    while (1) {

        // Leggo un singolo byte
        int n=read(fd,&ch,1);
        // Se n == 0 siamo a EOF → fine file → esco
        if (n == 0)
            break;

        // --- STAMPA DEL CARATTERE LETTO ---
        // Questo è il carattere "dispari", perché ogni volta saltiamo quello dopo
        putchar(ch);

        // --- LSEEK ---
        // Salto un byte avanti nel file (cioè ignoro il prossimo carattere)
        if(lseek(fd,1,SEEK_CUR)==-1)
        break;
        // SEEK_CUR = spostamento relativo alla posizione attuale
    }

    // Chiudo il file alla fine
    close(fd);
    return 0;
}