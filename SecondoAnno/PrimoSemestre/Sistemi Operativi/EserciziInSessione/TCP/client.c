#include <stdio.h>           // printf()
#include <assert.h>          // assert()
#include <unistd.h>          // close()
#include <sys/types.h>
#include <sys/socket.h>      // connect()
#include <netinet/in.h>
#include "tcp.h"

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    // -----------------------------------------------------------------------
    // Apre una socket TCP locale e la associa alla porta 20000
    // (scelta arbitraria; il client può usare anche porta 0 = porta casuale)
    // -----------------------------------------------------------------------
    int sd = TCP_Open(20000);
    assert(sd > -1);

    struct sockaddr_in addrSnd;

    // -----------------------------------------------------------------------
    // Prepara il sockaddr_in del server: localhost, porta 10000.
    // TCP_FillSockAddr risolve "localhost" → 127.0.0.1 via DNS.
    // -----------------------------------------------------------------------
    int rc = TCP_FillSockAddr(&addrSnd, "localhost", 10000);
    assert(rc == 0);

    // -----------------------------------------------------------------------
    // connect() inizia la procedura di handshake TCP a 3 vie:
    // 1. SYN → server
    // 2. SYN-ACK ← server
    // 3. ACK → server
    //
    // Se connect ritorna 0, la connessione è stabilita.
    // -----------------------------------------------------------------------
    rc = connect(sd, (struct sockaddr *)&addrSnd, sizeof(addrSnd));
    assert(rc == 0);

    // Prepara un messaggio di testo
    char message[BUFFER_SIZE];
    sprintf(message, "hello world");

    // -----------------------------------------------------------------------
    // TCP_Write invia i dati sulla connessione appena stabilita.
    // -----------------------------------------------------------------------
    TCP_Write(sd, message, BUFFER_SIZE);

    // -----------------------------------------------------------------------
    // Attende la risposta del server.
    // -----------------------------------------------------------------------
    rc = TCP_Read(sd, message, BUFFER_SIZE);

    if (rc > 0) {
        message[(rc < BUFFER_SIZE ? rc : BUFFER_SIZE - 1)] = '\0';
        printf("client: ricevuto → %s\n", message);
    }

    // -----------------------------------------------------------------------
    // Chiude la connessione TCP.
    // Questo invia al server un FIN e avvia la chiusura TCP ordinata.
    // -----------------------------------------------------------------------
    close(sd);

    return 0;
}

