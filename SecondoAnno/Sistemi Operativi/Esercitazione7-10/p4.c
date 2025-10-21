#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
	printf("hello world (pid:%d)\n", (int) getpid());
	int rc = fork();


	if (rc < 0) {
		// fork failed; exit
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) { // child: redirect standard output to a file
		close(STDOUT_FILENO);
		open("./p4.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU); //poi apriamo un nuovo file . ci mettiamo un nuovo file nella cartella p4.output, il resto sono dati di accesso
		// now exec "wc"...
		printf("hello, I am child (pid:%d)\n", (int) getpid());
		char *myargs[3]; //preparo i parametri per la funzione exec
		myargs[0] = strdup("wc"); //ci scrivo il programma da eseguire
		// program: "wc" (word count)
		myargs[1] = strdup("p4.c"); //ci metto il parametro di ingresso del programma
		// argument: file to count
		myargs[2] = NULL; //system call di terminazione del programma
		// marks end of array
		execvp(myargs[0], myargs); //poi chiamiamo l'exec con gli argomenti che ci interessano 

		// runs word count

	} else {
		// parent goes down this path (main)
		int wc = wait(NULL);
		printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",rc, wc, (int) getpid());
	}

	
	int second = fork();

	if( second<0){
		printf(stderr, "fork del fork failed\n");
		exit(1); 
	}
	close(STDIN_FILENO);
	printf("hello, I am child of child (pid:%d)\n", (int) getpid());
	return 0;
}
