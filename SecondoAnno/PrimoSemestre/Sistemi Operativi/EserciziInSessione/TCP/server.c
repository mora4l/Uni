#include <stdio.h>              // Per printf()
#include <assert.h>             // Per assert()
#include <unistd.h>             // Per close()
#include <sys/types.h>          // Necessario per socket()
#include <sys/socket.h>         // accept(), listen()
#include <netinet/in.h>         // Strutture TCP/IP
#include "tcp.h"                // Funzioni TCP implementate da noi

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    // -----------------------------------------------------------------------
    // Crea una socket TCP e la associa alla porta 10000.
    // Questa socket NON è ancora pronta ad accettare connessioni.
    // -----------------------------------------------------------------------
    int sd = TCP_Open(10000);
    assert(sd > -1);

    // -----------------------------------------------------------------------
    // listen() trasforma la socket in stato PASSIVO:
    // il kernel accoda le richieste TCP in arrivo fino a 5 connessioni.
    // La socket sd non comunicherà direttamente: farà solo accept().
    // -----------------------------------------------------------------------
    int rc = listen(sd, 5);
    assert(rc == 0);

    // -----------------------------------------------------------------------
    // Ciclo infinito: il server rimane sempre attivo.
    // -----------------------------------------------------------------------
    while (1) {

        struct sockaddr_in addr;          // Informazioni sul client remoto
        socklen_t addr_len = sizeof(addr);

        // -------------------------------------------------------------------
        // accept() crea una NUOVA socket (newsd):
        //  - sd resta la socket "che ascolta"
        //  - newsd è la connessione TCP con il client
        //
        // Il kernel sospende il processo finché non arriva un SYN
        // da parte di un client.
        // -------------------------------------------------------------------
        int newsd = accept(sd, (struct sockaddr *)&addr, &addr_len);

        if (newsd < 0) {
            perror("accept");
            continue;
        }

        // Buffer di ricezione
        char message[BUFFER_SIZE];

        // -------------------------------------------------------------------
        // Riceve i dati inviati dal client tramite la connessione TCP.
        // TCP_Read è bloccante: attende finché non arriva qualcosa.
        // -------------------------------------------------------------------
        rc = TCP_Read(newsd, message, BUFFER_SIZE);

        if (rc > 0) {
            // Inserisce terminatore di stringa per sicurezza
            message[(rc < BUFFER_SIZE ? rc : BUFFER_SIZE - 1)] = '\0';

            printf("server: ricevuto → %s\n", message);

            // Prepara risposta
            char reply[BUFFER_SIZE];
            sprintf(reply, "goodbye world");

            // ----------------------------------------------------------------
            // Invia la risposta al client sulla connessione TCP aperta (newsd)
            // ----------------------------------------------------------------
            TCP_Write(newsd, reply, BUFFER_SIZE);
        }

        // -------------------------------------------------------------------
        // Chiude la connessione con questo client
        // La socket sd resta invece aperta e continua ad accettare altri client
        // -------------------------------------------------------------------
        close(newsd);
    }

    // Non verrà mai raggiunta, ma è buona pratica chiudere la socket
    close(sd);
    return 0;
}

