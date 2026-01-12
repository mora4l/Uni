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
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
// Inizializza la variabile di condizione
pthread_cond_t done=PTHREAD_COND_INITIALIZER;
// Dichiara le funzioni dei thread: functionCount1 e functionCount2
void* functionCount1(void*);
void* functionCount2(void*);

int count = 0;
int go = 0;

#define COUNT_DONE 10

int main()
{
    // Dichiara gli ID dei thread 1 e 2
    pthread_t thread1,thread2;
    int rc1, rc2;

    // Crea due thread indipendenti, uno esegue functionCount1 e l'altro functionCount2
    pthread_create(&thread1,NULL,functionCount1,NULL);
    pthread_create(&thread2,NULL,functionCount2,NULL);
    // Attende che i thread siano completati prima che main continui
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL); 
    printf("Valore finale del contatore: %d\n", count);
    return 0;
}

void* functionCount1(void*)
{
    // Continua solo fino al raggiungimento del limite
    while (count < COUNT_DONE)
    {
        // Blocca il mutex 
        pthread_mutex_lock(&mutex1);

        // Finché la variabile go è 0, aspetta sulla condizione. Questo previene 
        // che segnali spurie facciano eseguire il thread in modo scorretto
        pthread_t tid = pthread_self();//la aggiungo io 
        while(go==0){
            printf("thread %lu blocked, mi metto in wait \n",(unsigned long)tid);
            pthread_cond_wait(&done,&mutex1);
        }
    
        // Imposta la variabile go a 0
        go=0 ; 
        // Incrementa count
        count++;
        printf("Valore del contatore functionCount1: %d\n", count);
        
        // Sblocca il mutex 
        pthread_mutex_unlock(&mutex1);
    }
    int* ret=(int*)malloc(sizeof(int));
    *ret=0;
    // Esci
    pthread_exit((void*)ret);
}

void* functionCount2(void*)
{
    // Continua solo fino al raggiungimento del limite
    while (count < COUNT_DONE)
    {
        // Blocca il mutex 
        pthread_mutex_lock(&mutex1);
        // Incrementa e stampa count
        count++;
        printf("Valore del contatore functionCount2: %d\n", count);

        // Imposta la variabile go a 1
        go=1;
        // Segnala all'altro thread
        printf("mando un segnale che go ora è 1\n\n");
        pthread_cond_signal(&done);
        // Sblocca il mutex
        pthread_mutex_unlock(&mutex1);

        // Dorme 1 secondo
        sleep(1);
    }

    // Assicura che il thread in attesa possa uscire se sta ancora aspettando

    // Esci
    int* ret2=(int*)malloc(sizeof(int));
    *ret2=0;
    pthread_exit((void*)ret2);
}

