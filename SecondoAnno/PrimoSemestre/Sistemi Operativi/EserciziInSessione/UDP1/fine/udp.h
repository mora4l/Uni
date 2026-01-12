#ifndef UDP_H
#define UDP_H

// Includiamo la definizione di struct sockaddr_in (indirizzi IPv4)
#include <netinet/in.h>

// ---------------------------------------------------------------------------
// UDP_Open
//  - Crea una socket UDP (datagram) IPv4.
//  - La associa (bind) alla porta locale specificata.
//  - Restituisce il descrittore di socket (>=0) oppure -1 in caso di errore.
// ---------------------------------------------------------------------------
int UDP_Open(int port);

// ---------------------------------------------------------------------------
// UDP_FillSockAddr
//  - Inizializza una struct sockaddr_in puntata da 'addr'.
//  - Imposta:
//      * famiglia AF_INET (IPv4),
//      * porta remota,
//      * indirizzo IP remoto (risolto da hostname).
//  - Restituisce 0 se tutto ok, -1 se la risoluzione fallisce.
// ---------------------------------------------------------------------------
int UDP_FillSockAddr(struct sockaddr_in *addr, char *hostname, int port);

// ---------------------------------------------------------------------------
// UDP_Write
//  - Invia n byte dal buffer verso l’indirizzo UDP specificato da 'addr'.
//  - Usa sendto(), tipica chiamata per socket datagram.
//  - Restituisce il numero di byte effettivamente inviati o -1 in caso di errore.
// ---------------------------------------------------------------------------
int UDP_Write(int sd, struct sockaddr_in *addr, char *buffer, int n);

// ---------------------------------------------------------------------------
// UDP_Read
//  - Riceve fino a n byte da una socket UDP, memorizzandoli in 'buffer'.
//  - L’indirizzo sorgente viene memorizzato in 'addr'.
//  - Usa recvfrom(), tipica chiamata per datagram UDP.
//  - Restituisce il numero di byte ricevuti o -1 in caso di errore.
// ---------------------------------------------------------------------------
int UDP_Read(int sd, struct sockaddr_in *addr, char *buffer, int n);

#endif

