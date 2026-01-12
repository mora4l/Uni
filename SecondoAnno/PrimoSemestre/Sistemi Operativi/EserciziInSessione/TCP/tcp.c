#include <stdio.h>              // Per printf(), perror()
#include <unistd.h>             // Per close()
#include <string.h>             // Per memset() / bzero()
#include <strings.h>            // Per bzero()
#include <sys/types.h>          // Tipi usati per socket()
#include <sys/socket.h>         // API socket: socket(), bind(), send(), recv()
#include <netdb.h>              // gethostbyname() per risoluzione DNS
#include <netinet/in.h>         // Strutture TCP/IP
#include "tcp.h"

// ============================================================================
// TCP_Open: crea e associa una socket TCP ad una porta locale.
// ============================================================================
int TCP_Open(int port) {
    int sd;

    // Crea una socket:
    //  - AF_INET: protocollo IPv4
    //  - SOCK_STREAM: socket di tipo "stream", quindi TCP
    //  - protocollo 0 = TCP implicito
    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        return -1;

    // Struttura per l'indirizzo locale
    struct sockaddr_in myaddr;

    // Azzera tutti i byte della struttura per evitare campi casuali
    bzero(&myaddr, sizeof(myaddr));

    // Specifica che si tratta di un indirizzo IPv4
    myaddr.sin_family = AF_INET;

    // Imposta la porta locale convertita in "network byte order"
    myaddr.sin_port = htons(port);

    // Accetta connessioni su tutte le interfacce locali della macchina (0.0.0.0)
    myaddr.sin_addr.s_addr = INADDR_ANY;

    // Associa la socket al binding dell'indirizzo e porta
    if (bind(sd, (struct sockaddr *) &myaddr, sizeof(myaddr)) == -1) {
        close(sd);             // Chiude la socket se il bind fallisce
        return -1;
    }

    // Ritorna il file descriptor della socket creata
    return sd;
}

// ============================================================================
// TCP_FillSockAddr: traduce hostname → indirizzo IP e imposta porta IPv4
// ============================================================================
int TCP_FillSockAddr(struct sockaddr_in *addr, char *hostname, int port) {

    // Azzera l'intera struttura
    bzero(addr, sizeof(struct sockaddr_in));

    // Indirizzo IPv4
    addr->sin_family = AF_INET;

    // Porta convertita in network byte order
    addr->sin_port = htons(port);

    // Risoluzione DNS
    struct hostent *host_entry = gethostbyname(hostname);

    // Se la risoluzione fallisce, host non trovato
    if (host_entry == NULL)
        return -1;

    // Ottiene l'indirizzo IP dal risultato DNS
    struct in_addr *in_addr = (struct in_addr *) host_entry->h_addr;

    // Copia l'indirizzo IPv4 nella struttura sockaddr_in
    addr->sin_addr = *in_addr;

    return 0;
}

// ============================================================================
// TCP_Write: invia dati sulla connessione TCP già stabilita.
// ============================================================================
int TCP_Write(int sd, char *buffer, int n) {

    // TCP è orientato al flusso: nessun indirizzo richiesto
    return send(sd, buffer, n, 0);
}

// ============================================================================
// TCP_Read: riceve dati dalla connessione TCP.
// Restituisce:
//  - numero di byte letti,
//  - 0 se il peer ha chiuso la connessione,
//  - -1 in caso di errore.
// ============================================================================
int TCP_Read(int sd, char *buffer, int n) {

    return recv(sd, buffer, n, 0);
}