// Libreria standard per I/O: printf(), perror(), ecc.
#include <stdio.h>
// assert() per verificare condizioni a runtime in modo semplice
#include <assert.h>
// close() per chiudere il descrittore di socket
#include <unistd.h>
// Importa le dichiarazioni delle funzioni UDP_* e struct sockaddr_in
#include "udp.h"

// Definiamo la dimensione massima del buffer per i messaggi
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // -----------------------------------------------------------------------
    // Crea una socket UDP e la associa alla porta 10000 sulla macchina locale.
    // Il server attenderà datagram su questa porta.
    // -----------------------------------------------------------------------
    int sd = UDP_Open(10000);

    // Verifichiamo che la socket sia stata creata correttamente
    assert(sd > -1);

    // -----------------------------------------------------------------------
    // Ciclo infinito: il server rimane sempre in ascolto.
    // Ogni iterazione gestisce un singolo datagram in arrivo.
    // -----------------------------------------------------------------------
    while (1) {
        // Struttura che conterrà l'indirizzo del client mittente
        struct sockaddr_in addr;

        // Buffer per memorizzare il messaggio ricevuto
        char message[BUFFER_SIZE];

        // -------------------------------------------------------------------
        // UDP_Read:
        //  - attende (bloccante) la ricezione di un datagram sulla socket sd
        //  - scrive i dati in 'message'
        //  - scrive l'indirizzo sorgente in 'addr'
        // -------------------------------------------------------------------
        int rc = UDP_Read(sd, &addr, message, BUFFER_SIZE);

        // Se rc > 0, abbiamo ricevuto effettivamente dei byte
        if (rc > 0) {
            // Aggiunge un terminatore di stringa in modo sicuro
            // Se rc < BUFFER_SIZE, lo mettiamo a message[rc]
            // Altrimenti evitiamo overflow mettendolo a BUFFER_SIZE - 1
            message[rc < BUFFER_SIZE ? rc : BUFFER_SIZE - 1] = '\0';

            // Stampa sullo standard output il messaggio ricevuto
            printf("server received: %s\n", message);

            // Prepariamo una risposta da inviare al client
            char reply[BUFFER_SIZE];
            sprintf(reply, "goodbye world");

            // ----------------------------------------------------------------
            // UDP_Write:
            //  - invia il contenuto di 'reply' all'indirizzo del client
            //    (addr) che abbiamo ottenuto con UDP_Read
            // ----------------------------------------------------------------
            rc = UDP_Write(sd, &addr, reply, BUFFER_SIZE);

            // Se rc < 0, c'è stato un errore nella sendto()
            if (rc < 0) {
                perror("UDP_Write");
            }

        // In caso di errore nella ricezione (rc < 0), stampiamo un messaggio
        } else if (rc < 0) {
            perror("UDP_Read");
        }
    }

    // Questo punto in realtà non viene mai raggiunto a causa del while(1),
    // ma in un server "pulito" chiuderemmo la socket prima di uscire.
    close(sd);
    return 0;
}

