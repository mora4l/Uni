// Libreria standard per I/O
#include <stdio.h>
// assert() per controlli di validazione
#include <assert.h>
// close() per chiudere socket
#include <unistd.h>
// Header con le funzioni UDP_* e struct sockaddr_in
#include "udp.h"

// Dimensione del buffer per invio/ricezione messaggi
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // -----------------------------------------------------------------------
    // Crea una socket UDP e la associa alla porta 20000.
    // Il client userà questa porta come "sorgente" dei datagram inviati.
    // -----------------------------------------------------------------------

    // Controlla che la creazione e il bind siano andati a buon fine
    assert(sd > -1);

    // Strutture per gli indirizzi:
    //  - addrSnd: indirizzo del server a cui inviare i datagram
    //  - addrRcv: indirizzo del mittente da cui riceviamo (in questo caso il server)
    struct sockaddr_in addrSnd, addrRcv;

    // -----------------------------------------------------------------------
    // Inizializza addrSnd con l'indirizzo del server:
    //  - hostname: "localhost"
    //  - porta: 10000
    // -----------------------------------------------------------------------
    
    // Verifica che la risoluzione dell'hostname sia riuscita
    assert(rc == 0);

    // Buffer per il messaggio da inviare e per ricevere la risposta
    char message[BUFFER_SIZE];

    // Scrive nel buffer una stringa "hello world"
    sprintf(message, "hello world");

    // -----------------------------------------------------------------------
    // Invia un datagram al server:
    //  - sd: socket del client
    //  - addrSnd: indirizzo del server (IP + porta)
    //  - message: dati da spedire
    // -----------------------------------------------------------------------

    // Se l'invio è andato a buon fine (rc > 0), procediamo a leggere la risposta
    if (rc > 0) {
        // -------------------------------------------------------------------
        // Legge un datagram in arrivo:
        //  - addrRcv conterrà l'indirizzo di chi ci ha risposto (il server)
        //  - message conterrà i dati ricevuti
        // -------------------------------------------------------------------

        if (rc > 0) {
            // Aggiunge il terminatore di stringa in modo sicuro
            message[rc < BUFFER_SIZE ? rc : BUFFER_SIZE - 1] = '\0';

            // Stampa la risposta del server
            printf("client received: %s\n", message);
        } else if (rc < 0) {
            // Errore nella ricezione
            perror("UDP_Read");
        }
    } else if (rc < 0) {
        // Errore nell'invio del datagram
        perror("UDP_Write");
    }

    // Chiude la socket UDP del client
    return 0;
}

