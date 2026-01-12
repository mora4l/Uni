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

// Initialize the condition variable

// Declare thread functions: functionCount1 and functionCount2

int count = 0;
int go = 0;
#define COUNT_DONE 10

int main()
{
    // Declare the IDs of thread 1 and thread 2

    int rc1, rc2;

    // Create two independent threads, one executing functionCount1 and the other functionCount2 

    // Wait until threads are complete before main continues

    printf("Final count: %d\n", count);
    return 0;
}

void* functionCount1(void*)
{
    // Continue only until the limit is reached
    while (count < COUNT_DONE)
    {
        // Lock mutex 

        // While the go variable is 0, wait on the condition. This prevents spurious wakeups 
        // from executing the thread incorrectly

        // Set the go variable to 0
        
        // Increment count
        count++;
        printf("Counter value functionCount1: %d\n", count);
        
        // Unlock mutex 
    }
    
    // Exit
}

void* functionCount2(void*)
{
    // Continue only until the limit is reached
    while (count < COUNT_DONE)
    {
        // Lock mutex 

        // Increment and print count
        count++;
        printf("Counter value functionCount2: %d\n", count);

        // Set the go variable to 1
        
        // Signal the other thread

        // Unlock mutex

        // Sleep 1 second
        sleep(1);
    }

    // Make sure the waiting thread can exit if it's still waiting

    // Exit
}

