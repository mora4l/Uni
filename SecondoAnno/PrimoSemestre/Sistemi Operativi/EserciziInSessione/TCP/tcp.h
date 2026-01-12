#ifndef TCP_H
#define TCP_H

#include <netinet/in.h>

// ---------------------------------------------------------------------------
// TCP_Open
// Apre una socket TCP (stream) e la associa a una porta locale.
// Questo permette al processo di ascoltare connessioni in ingresso o, nel caso
// del client, di usare una porta locale specifica per creare una connessione TCP.
// ---------------------------------------------------------------------------
int TCP_Open(int port);

// ---------------------------------------------------------------------------
// TCP_FillSockAddr
// Riempie una struttura sockaddr_in con:
//  - tipo di indirizzo (IPv4),
//  - porta (convertita in network byte order),
//  - indirizzo IP ottenuto tramite risoluzione DNS.
// Serve per identificare un endpoint TCP (server o client).
// ---------------------------------------------------------------------------
int TCP_FillSockAddr(struct sockaddr_in *addr, char *hostname, int port);

// ---------------------------------------------------------------------------
// TCP_Write
// Scrive n byte sul socket TCP. Essendo TCP orientato alla connessione,
// non dobbiamo specificare indirizzi come con UDP: il flusso è già stabilito.
// ---------------------------------------------------------------------------
int TCP_Write(int sd, char *buffer, int n);

// ---------------------------------------------------------------------------
// TCP_Read
// Riceve dati dal socket TCP. La socket deve essere connessa.
// Restituisce il numero di byte letti o 0 se la connessione è chiusa.
// ---------------------------------------------------------------------------
int TCP_Read(int sd, char *buffer, int n);

#endif

