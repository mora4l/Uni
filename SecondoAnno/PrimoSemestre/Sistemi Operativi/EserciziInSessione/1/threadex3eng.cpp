/*
compile with:
    g++ threadex3.cpp -lpthread -o thread3
   
run with:
    ./thread3
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Initialize the mutex used to protect the condition and the variable count
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
// Initialize the condition variable
pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;

// Declare thread functions: functionCount1 and functionCount2
void* functionCount1(void*);
void* functionCount2(void*);

int count = 0;
int go = 0;
#define COUNT_DONE 10

int main()
{
    // Declare the IDs of thread 1 and thread 2
    pthread_t thread1, thread2;
    int rc1, rc2;

    // Create two independent threads, one executing functionCount1 and the other functionCount2 
    if ((rc1 = pthread_create(&thread1, NULL, functionCount1, NULL)) != 0)
    {
        printf("Thread creation failed: %d\n", rc1);
        exit(EXIT_FAILURE);
    }
    if ((rc2 = pthread_create(&thread2, NULL, functionCount2, NULL)) != 0)
    {
        printf("Thread creation failed: %d\n", rc2);
        exit(EXIT_FAILURE);
    }

    // Wait until threads are complete before main continues
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final count: %d\n", count);
    return 0;
}

void* functionCount1(void*)
{
    // Continue only until the limit is reached
    while (count < COUNT_DONE)
    {
        // Lock mutex 
        pthread_mutex_lock(&count_mutex);

        // While the go variable is 0, wait on the condition. This prevents spurious wakeups 
        // from executing the thread incorrectly
        while (go == 0)
        {
            // Wait for the signal
            pthread_cond_wait(&condition_var, &count_mutex);
        }

        // Set the go variable to 0
        go = 0;
        
        // Increment count
        count++;
        printf("Counter value functionCount1: %d\n", count);
        
        // Unlock mutex 
        pthread_mutex_unlock(&count_mutex);
    }
    
    // Exit
    pthread_exit(NULL);
}

void* functionCount2(void*)
{
    // Continue only until the limit is reached
    while (count < COUNT_DONE)
    {
        // Lock mutex 
        pthread_mutex_lock(&count_mutex);

        // Increment and print count
        count++;
        printf("Counter value functionCount2: %d\n", count);

        // Set the go variable to 1
        go = 1;
        
        // Signal the other thread
        pthread_cond_signal(&condition_var);

        // Unlock mutex
        pthread_mutex_unlock(&count_mutex);

        // Sleep 1 second
        sleep(1);
    }

    // Make sure the waiting thread can exit if it's still waiting
    pthread_cond_signal(&condition_var);

    // Exit
    pthread_exit(NULL);
}

