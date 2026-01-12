/*
compile with:
	g++ threadex2.cpp -lpthread -o thread2
   
run with:
	./thread2
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

// declare the incrementCounter function
void* incrementCounter(void*);

// initialize the mutex
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

// these variables are used to create a race condition
int counter = 0;
int temp;

int main()
{
    int rc1, rc2;
   
    // declare the IDs of thread 1 and thread 2
    pthread_t thread1, thread2;

    // create two independent threads, each of which will execute the incrementCounter function
    if ((rc1 = pthread_create(&thread1, NULL, incrementCounter, NULL)))
    {
        printf("Thread creation failed: %d\n", rc1);
    }
    if ((rc2 = pthread_create(&thread2, NULL, incrementCounter, NULL)))
    {
        printf("Thread creation failed: %d\n", rc2);
    }

    // wait until the threads are completed before main continues 
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0; 
}
 
void* incrementCounter(void *)
{
    for (int i=0; i < 100; i++)
    {
        // lock the mutex (try to see how the behavior changes if the mutex is present or absent)
        pthread_mutex_lock(&mutex1);

	// update temp and increment it by one
        temp = counter; 
        temp = temp + 1;
   	
        // introduce here a one-second delay to increase the probability of a preemption 
        // occurring between the update of temp and the subsequent update of counter
        
        sleep(1);
        counter = temp;

        // print the value of the counter
        printf("Counter value: %d\n", counter);
        fflush(stdout);

        // unlock the mutex (try to see how the behavior changes if the mutex is present or absent)
        pthread_mutex_unlock(&mutex1);
    }
    return NULL;
}  
