#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <iostream>
#include <string>


/*
Versione con FILE CONDIVISO e read/write:


- Padre scrive nel file con write().
- Figlio legge dal file con read().
- Quando scrivono a schermo usano cout.
- Quando acquisiscono input da tastiera usano cin.
*/


int main() {
	// Creazione di un nuovo processo tramite fork
	pid_t pid=fork();
	int fd;
	if (pid < 0) {
	// Controllo errore fork
		perror("fork error");
		exit(1);
	}


	// ----------------------
	// FIGLIO
	// ----------------------
	int n; 
	if (pid == 0) {
		// Apre lo stesso file del padre, solo in lettura
		fd=open("file.txt",O_RDONLY);
		// buffer per leggere dal file
		char buffer[10];
		// variabile per memorizzare il numero di byte letti
		int numbyte=0;
while(1){
		while((n=read(fd,buffer,sizeof(buffer)))>0){
                buffer[n] = '\0';
			printf("figlio sta leggendo");
			// Il figlio legge tutto ciò che trova nel file
				// SCRITTURA SU SCHERMO con cout
                std::cout << std::endl << "[FIGLIO legge]: " << buffer << std::endl;
				// Controlla se la stringa letta è "0" per terminare
				if(strcmp(buffer,"0")==0)
				break;
		}
			
	}
		// Messaggio di terminazione del figlio
			printf("figlio ha finito\n");
	
		// chiusura file
			close(fd);
		return 0;
}


	// ----------------------
	// PADRE
	// ----------------------
	else {
		// Padre apre il file in scrittura (lo crea/azzera)
		fd=open("file.txt",O_CREAT|O_WRONLY|O_TRUNC,0644);
		// buffer per leggere stringa da cin e scriverla su file
		char frase[256];
		
		while (true) {
		// INPUT DA UTENTE con cin
		printf("Inserisci la frase\n");
		scanf("%s",frase);
			// Scrive la frase nel file con write
			write(fd,frase,strlen(frase));
			// Se l'utente inserisce "0" termina il ciclo
			if(strcmp(frase,"0")==0) break;
		}
		// Messaggio di terminazione del padre
		printf("padre ha finito	\n");
		// chiusura file
		close(fd);
		return 0;
	}
}
