/*
compila con:
	g++ threadex2.cpp -lpthread -o thread2
   
esegui con:
	./thread2
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

// dichiara la funzione incrementCounter
void* incrementCounter(void*);

// inizializza il mutex
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

// queste variabili servono per creare una race condition
int counter = 0;
int temp;

int main()
{
    int rc1, rc2;
   
    // dichiara gli ID del thread 1 e del thread 2
    pthread_t thread1, thread2;

    // crea due thread indipendenti, ognuno dei quali eseguirà la funzione incrementCounter
    if ((rc1 = pthread_create(&thread1, NULL, incrementCounter, NULL)))
    {
        printf("Creazione del thread fallita: %d\n", rc1);
    }
    if ((rc2 = pthread_create(&thread2, NULL, incrementCounter, NULL)))
    {
        printf("Creazione del thread fallita: %d\n", rc2);
    }

    // attende che i thread siano completati prima che main continui 
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0; 
}
 
void* incrementCounter(void *)
{
    for (int i=0; i < 100; i++)
    {
        // blocca il mutex (prova a vedere come cambia il comportamento se il mutex è presente o assente)
        pthread_mutex_lock(&mutex1);

	// aggiorno temp e lo incremento di uno
        temp = counter; 
        temp = temp + 1;
   	
        // introduco in questo punto un ritardo di un secondo per aumentare la probabilità che avvenga una preemption
        // tra l'aggiornamento di temp e il conseguente aggiornamento di counter
        
        sleep(1);
        counter = temp;

        // stampo il valore del contatore
        printf("Counter value: %d\n", counter);
        fflush(stdout);

        // sblocco il mutex (prova a vedere come cambia il comportamento se il mutex è presente o assente)
        pthread_mutex_unlock(&mutex1);
    }
    return NULL;
}  
