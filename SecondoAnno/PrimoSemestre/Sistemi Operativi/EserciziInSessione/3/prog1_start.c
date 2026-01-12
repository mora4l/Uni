#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>      // per open()
#include <unistd.h>     // per read(), write(), close()
#include <string.h>     // per strlen()

int main() {
    int fd;
    char buffer[5];

    // --- INPUT DALL'UTENTE ---
    // fgets legge una riga dallo standard input e la inserisce in buffer.
    printf("Inserisci una frase: ");
    fgets(buffer, sizeof(buffer), stdin);

    // --- APERTURA FILE IN SCRITTURA ---
    // O_WRONLY = solo scrittura
    // O_CREAT  = crea il file se non esiste
    // O_TRUNC  = se il file esiste lo svuota
    fd=open("file.txt",O_CREAT|O_WRONLY|O_TRUNC,0644);
    printf("ho aperto in lettura un file\n");
    // --- SCRITTURA SU FILE ---
    // Scriviamo tutta la frase presa da input nel file con write.
    write(fd,buffer,strlen(buffer));
    // Chiudiamo il file dopo aver scritto.
    close(fd);

    // --- APERTURA FILE IN LETTURA ---
fd=open("file.txt",O_RDONLY);
    // --- LETTURA UN BYTE ALLA VOLTA ---
    char ch;

    while(read(fd,&ch,1)==1){
    putchar(ch);
    }
    
    // read(fd, &ch, 1) legge un singolo byte da file
    // Restituisce 1 se un byte è stato letto correttamente
    // Restituisce 0 se siamo arrivati alla fine del file (EOF)

    // Chiudo il file dopo la lettura
    close(fd);

    return 0;
}