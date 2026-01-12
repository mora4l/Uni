// Libreria standard per I/O (printf, perror, ecc.)
#include <stdio.h>
// Per la funzione close() usata per chiudere le socket
#include <unistd.h>
// Per funzioni di manipolazione stringhe (memset, memcpy, ecc.)
#include <string.h>
// Per bzero(), alternativa a memset
#include <strings.h>
// Tipi base usati da socket (es. size_t, ecc.)
#include <sys/types.h>
// API di comunicazione: socket(), bind(), sendto(), recvfrom(), ecc.
#include <sys/socket.h>
// Per gethostbyname(), strutture hostent (risoluzione DNS)
#include <netdb.h>
// Strutture e costanti del protocollo Internet (sockaddr_in, INADDR_ANY, ecc.)
#include <netinet/in.h>
// Header con le dichiarazioni delle nostre funzioni UDP
#include "udp.h"

// ============================================================================
// UDP_Open: crea una socket UDP e la associa a una porta locale.
// ============================================================================
int UDP_Open(int port) {
    int sd;

    // Crea la socket:
    //  - AF_INET: IPv4
    //  - SOCK_DGRAM: datagram, quindi UDP
    //  - protocollo 0: lascia scegliere al sistema (per AF_INET + SOCK_DGRAM → UDP)

    // Struttura che conterrà i dati dell'indirizzo locale (porta + IP)
    struct sockaddr_in myaddr;

    // Azzera tutti i campi della struct per evitare valori spazzatura
    bzero(&myaddr, sizeof(myaddr));

    // Specifica che usiamo indirizzi IPv4

    // Imposta la porta locale:
    //  - htons(): converte da host byte order a network byte order (big-endian)

    // Imposta l'indirizzo locale della socket
    //  - INADDR_ANY: accetta datagram su qualsiasi interfaccia locale

    // Associa l'indirizzo (porta + IP) alla socket appena creata

    // Tutto ok: restituiamo il descrittore di socket
    return sd;
}

// ============================================================================
// UDP_FillSockAddr: riempie una struct sockaddr_in con hostname e porta.
// ============================================================================
int UDP_FillSockAddr(struct sockaddr_in *addr, char *hostname, int port) {
    // Azzera la struct sockaddr_in puntata da addr
    bzero(addr, sizeof(struct sockaddr_in));

    // Indica che stiamo usando un indirizzo IPv4

    // Imposta la porta remota, convertendola in network byte order

    // Puntatore dove salveremo l'indirizzo IP risultante
    struct in_addr *in_addr;

    // Struttura usata per la risoluzione DNS dell'hostname
    struct hostent *host_entry;

    // gethostbyname() risolve hostname in un indirizzo IP
    // Se non trova nulla, restituisce NULL

    // Estrae il primo indirizzo IP dalla lista di indirizzi restituiti

    // Copia l'indirizzo IP nella struttura sockaddr_in

    // Tutto ok
    return 0;
}

// ============================================================================
// UDP_Write: invia un datagram UDP verso un indirizzo specifico.
// ============================================================================
int UDP_Write(int sd, struct sockaddr_in *addr, char *buffer, int n) {
    // Calcola la dimensione in byte della struttura sockaddr_in

    // sendto():
    //  - sd: descrittore della socket
    //  - buffer: puntatore ai dati da inviare
    //  - n: numero di byte da inviare
    //  - flag 0: nessuna opzione speciale
    //  - (struct sockaddr *) addr: indirizzo del destinatario
    //  - addr_len: dimensione della struct indirizzo
    //
    // Restituisce il numero di byte realmente inviati oppure -1 in caso di errore.
}

// ============================================================================
// UDP_Read: riceve un datagram UDP e restituisce il mittente in 'addr'.
// ============================================================================
int UDP_Read(int sd, struct sockaddr_in *addr, char *buffer, int n) {
    // len conterrà la dimensione della struttura indirizzo del mittente

    // recvfrom():
    //  - sd: descrittore della socket
    //  - buffer: dove memorizzare i dati ricevuti
    //  - n: massimo numero di byte da ricevere
    //  - flag 0: nessuna opzione speciale
    //  - (struct sockaddr *) addr: dove scrivere l'indirizzo sorgente
    //  - (socklen_t *) &len: variabile che contiene e riceve la dimensione di addr
    //
    // Restituisce il numero di byte ricevuti o -1 in caso di errore.
}


