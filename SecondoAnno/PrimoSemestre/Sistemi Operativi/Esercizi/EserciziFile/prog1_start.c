#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  // per open()
#include <unistd.h> // per read(), write(), close()
#include <string.h> // per strlen()

#define SIZE 2
int main()
{
    int fd;
    char buffer[SIZE];

    // --- INPUT DALL'UTENTE ---
    // fgets legge una riga dallo standard input e la inserisce in buffer.
    printf("Inserisci una lettera: ");
    fgets(buffer, sizeof(buffer), stdin);

    // --- APERTURA FILE IN SCRITTURA ---
    // O_WRONLY = solo scrittura
    // O_CREAT  = crea il file se non esiste
    // O_TRUNC  = se il file esiste lo svuota

    fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 666);

    // --- SCRITTURA SU FILE ---
    // Scriviamo tutta la frase presa da input nel file con write.
    write(fd, buffer, SIZE);
    printf("Ho scritto nel file \n");

    // Chiudiamo il file dopo aver scritto.
    close(fd);

    // --- APERTURA FILE IN LETTURA ---

        fd = open("file.txt", O_RDONLY) ;
    
    // --- LETTURA UN BYTE ALLA VOLTA ---
    char ch;
    int res=2  ;




    do{
        res = read(fd,&ch,1) ;
        putchar(ch) ;
        printf("Ho letto il byte n° %d \n",ch) ;
    }while(res==1);
    // read(fd, &ch, 1) legge un singolo byte da file

    // Restituisce 1 se un byte è stato letto correttamente
    // Restituisce 0 se siamo arrivati alla fine del file (EOF)

    // Chiudo il file dopo la lettura
    close(fd);

    return 0;
}