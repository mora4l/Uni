// Includi le librerie necessarie per lavorare con pipe, fork, wait e I/O
#include <unistd.h>    
#include <sys/wait.h>  
#include <iostream>    
#include <string>      
#include <cstring>     

/*
Obiettivo: creare una comunicazione tra padre e figlio usando una pipe.
Il padre scrive sulla pipe quello che legge da tastiera.
Il figlio legge dalla pipe e stampa su schermo.
Quando il padre inserisce "0", entrambi terminano.
*/

int main() {
    // Crea un array di due interi per i file descriptor della pipe
    int fd1[2];
    // Crea una pipe e controlla eventuali errori
    pipe(fd1);

    int n;
    if(pipe(fd1)<0){
        // Stampa un messaggio di errore se la pipe non viene creata
        printf("errore\n");
        // Termina il programma se la pipe non può essere creata
        exit(1);
    }



    // Crea un nuovo processo figlio tramite fork e memorizza il pid
    pid_t pid=fork();
    int numeropid=getpid();
    // Controlla se fork ha fallito
    if(pid<0){
        // Stampa errore se fork fallisce
        printf("Errore fork\n");
        // Termina il programma se non è possibile creare il figlio
        exit(1);
    }


    // ---------------------- FIGLIO ----------------------
    // Se pid == 0 siamo nel processo figlio
if(pid==0){

    // Chiudi l'estremità di scrittura della pipe, il figlio legge solo
    close(fd1[1]);
    // Prepara un buffer per leggere i dati dalla pipe
char buffer[n];
    // Variabile per memorizzare quanti byte sono stati letti
int numbyte=0;
    // Ciclo continuo per leggere dalla pipe fino a fine dati
    printf("Sono il figlio \n");
while(1){
    while((n=read(fd1[1],buffer,strlen(buffer)))>0)
    // Aggiungi il terminatore di stringa alla fine del buffer
    buffer[n]='\0';
    // Stampa il contenuto letto dalla pipe
    printf("%s",buffer);
    // Controlla se il contenuto letto è "0" per terminare
    if(strcmp(buffer,"0")==0) break;
}



    // Stampa messaggio di terminazione del figlio
    printf("Figlio termina\n");
    // Chiudi l'estremità di lettura della pipe
    close(fd1[1]);
    // Termina il processo figlio
    return 0;         
}else{

    // ---------------------- PADRE ----------------------
    // Se pid > 0 siamo nel processo padre
    
        // Chiudi l'estremità di lettura della pipe, il padre scrive solo
        close(fd1[0]);
        // Prepara una stringa per leggere l'input dell'utente
        char frase [10]; 
        // Ciclo continuo per leggere input e scriverlo sulla pipe
    while(1){

        // Chiedi all'utente di inserire una frase
        printf("Inserisci una frase \n");
        // Leggi la riga inserita dall'utente
        scanf("%s",frase);
        // Scrivi la frase sulla pipe
        write(fd1[1],frase,strlen(frase));
        // Aggiungi un newline alla pipe
        write(fd1[1],"\n",1);
        // Se l'utente inserisce "0", esci dal ciclo
        if(frase=="0") break ;
    }
    
        // Stampa messaggio di terminazione del padre
        printf("Padre ha finito\n");
        // Chiudi l'estremità di scrittura della pipe
        close(fd1[0]);
        // Aspetta che il figlio termini
        wait(NULL);
        // Termina il processo padre
        return 0 ; 
}

}
