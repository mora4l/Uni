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
     pthread_t thread1, thread2; //dichiaro le variabili dei due thread
     const char *message1 = "1";
     const char *message2 = "2";
     int  iret1, iret2; //salvano il valore di ritorno dei thread
/*
int pthread_create(
    pthread_t *thread,           // dove salvare l’ID del nuovo thread
    const pthread_attr_t *attr,  // attributi del thread (di solito NULL)
    void *(*start_routine)(void *), // funzione che il thread deve eseguire
    void *arg                    // argomento da passare a quella funzione
);
*/


// Crea due thread indipendenti, ognuno dei quali eseguirà la funzione 
// print_message_function, passando una stringa diversa come quarto parametro.
// In altre parole, il primo thread riceve message1 come quarto parametro, 
// il secondo thread riceve message2 come quarto parametro.

iret1=pthread_create(&thread1,NULL,print_message_function,(void *)message1);
 iret2=pthread_create(&thread2,NULL,print_message_function,(void *)message2);

	if ( iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1))
	{
		printf("Creazione del thread fallita: %d\n", iret1);
	}
	if ( iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2))
	{
		printf("Creazione del thread fallita: %d\n", iret2);
	}
 
	// Attende che i thread siano completati prima che main continui. 
	// Se non si attende, si corre il rischio di eseguire un'uscita (exit) 
	// che terminerebbe il processo e tutti i thread prima che abbiano completato la loro esecuzione.

/* 	pthread_join(thread1,NULL); 
	pthread_join(thread2,NULL); */

	/*
	La pthread_join() può anche ricevere un secondo parametro (un void **) per ottenere il valore di ritorno della funzione eseguita dal thread.
Ma se non ti serve, puoi mettere NULL, che significa “non mi interessa il risultato, voglio solo aspettare la fine”.
	*/

	// Prova a ottenere lo stato di ritorno dei thread usando il secondo parametro di pthread_join, e stampalo.

	void *j1ret, *j2ret;
     	pthread_join( thread1, &j1ret);
     	pthread_join( thread2, &j2ret);

     	printf("Thread 1 restituisce: %d\n", *(int*)j1ret);
     	printf("Thread 2 restituisce: %d\n", *(int*)j2ret);
	fflush(stdout);
	
	return 0;
}
 
void *print_message_function( void *ptr )
{
     char *message;
     message = (char *) ptr;

     for (int i=0; i < 10000; i++)
     {
	// stampa il messaggio e svuota il buffer di output sullo schermo
     	printf("%s ", message);
     	fflush(stdout);
     }

	// quando si esce dal thread, 
	// usare pthread_exit e impostare correttamente il codice di errore, 
	// in modo che questo valore possa essere recuperato nel thread principale 
	// quando si utilizza la funzione join

	int *result = (int*)malloc(sizeof(int));
	*result = -1;
	pthread_exit((void*)result);
}

