/*
compila con:
	g++ threadex1.cpp -lpthread -o thread1
   
esegui con:
	./thread1
*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
 
void *print_message_function( void *ptr );

int main()
{
     // Dichiara gli ID del thread 1 e del thread 2

     const char *message1 = "1";
     const char *message2 = "2";
     int  iret1, iret2;
 
 	// Crea due thread indipendenti, ognuno dei quali eseguirà la funzione 
	// print_message_function, passando una stringa diversa come quarto parametro.
	// In altre parole, il primo thread riceve message1 come quarto parametro, 
	// il secondo thread riceve message2 come quarto parametro.
 
	// Attende che i thread siano completati prima che main continui. 
	// Se non si attende, si corre il rischio di eseguire un'uscita (exit) 
	// che terminerebbe il processo e tutti i thread prima che abbiano completato la loro esecuzione.
	
	// Prova a ottenere lo stato di ritorno dei thread usando il secondo parametro di pthread_join, e stampalo.
	
	return 0;
}
 
void *print_message_function( void *ptr )
{
     for (int i=0; i < 10000; i++)
     {
	// stampa il messaggio e svuota il buffer di output sullo schermo
     }

	// quando si esce dal thread, 
	// usare pthread_exit e impostare correttamente il codice di errore, 
	// in modo che questo valore possa essere recuperato nel thread principale 
	// quando si utilizza la funzione join
}

