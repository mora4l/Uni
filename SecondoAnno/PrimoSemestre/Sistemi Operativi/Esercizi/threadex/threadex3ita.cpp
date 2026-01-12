/*
compila con:
    g++ threadex3.cpp -lpthread -o thread3
   
esegui con:
    ./thread3
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Inizializza il mutex utilizzato per proteggere la condizione e la variabile count
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
// Inizializza la variabile di condizione
pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;

// Dichiara le funzioni dei thread: functionCount1 e functionCount2
void* functionCount1(void*);
void* functionCount2(void*);

int count = 0;
int go = 0;
#define COUNT_DONE 10

int main()
{
    // Dichiara gli ID dei thread 1 e 2
    pthread_t thread1, thread2;
    int rc1, rc2;

    // Crea due thread indipendenti, uno esegue functionCount1 e l'altro functionCount2
    if ((rc1 = pthread_create(&thread1, NULL, functionCount1, NULL)) != 0)
    {
        printf("Creazione del thread fallita: %d\n", rc1);
        exit(EXIT_FAILURE);
    }
    if ((rc2 = pthread_create(&thread2, NULL, functionCount2, NULL)) != 0)
    {
        printf("Creazione del thread fallita: %d\n", rc2);
        exit(EXIT_FAILURE);
    }

    // Attende che i thread siano completati prima che main continui
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Valore finale del contatore: %d\n", count);
    return 0;
}

void* functionCount1(void*)
{
    // Continua solo fino al raggiungimento del limite
    while (count < COUNT_DONE)
    {
        // Blocca il mutex 
        pthread_mutex_lock(&count_mutex);

        // Finché la variabile go è 0, aspetta sulla condizione. Questo previene 
        // che segnali spurie facciano eseguire il thread in modo scorretto
        while (go == 0)
        {
            // Attende il segnale
            pthread_cond_wait(&condition_var, &count_mutex);
        }

        // Imposta la variabile go a 0
        go = 0;
        
        // Incrementa count
        count++;
        printf("Valore del contatore functionCount1: %d\n", count);
        
        // Sblocca il mutex 
        pthread_mutex_unlock(&count_mutex);
    }
    
    // Esci
    pthread_exit(NULL);
}

void* functionCount2(void*)
{
    // Continua solo fino al raggiungimento del limite
    while (count < COUNT_DONE)
    {
        // Blocca il mutex 
        pthread_mutex_lock(&count_mutex);

        // Incrementa e stampa count
        count++;
        printf("Valore del contatore functionCount2: %d\n", count);

        // Imposta la variabile go a 1
        go = 1;
        
        // Segnala all'altro thread
        pthread_cond_signal(&condition_var);

        // Sblocca il mutex
        pthread_mutex_unlock(&count_mutex);

        // Dorme 1 secondo
        sleep(1);
    }

    // Assicura che il thread in attesa possa uscire se sta ancora aspettando
    pthread_cond_signal(&condition_var);

    // Esci
    pthread_exit(NULL);
}

