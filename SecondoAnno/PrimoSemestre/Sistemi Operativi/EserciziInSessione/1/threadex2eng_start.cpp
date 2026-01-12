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

// initialize the mutex

// these variables are used to create a race condition
int counter = 0;
int temp;

int main()
{
    int rc1, rc2;
   
    // declare the IDs of thread 1 and thread 2

    // create two independent threads, each of which will execute the incrementCounter function

    // wait until the threads are completed before main continues 

    return 0; 
}
 
void* incrementCounter(void *)
{
    for (int i=0; i < 100; i++)
    {
        // lock the mutex (try to see how the behavior changes if the mutex is present or absent)

	// update temp and increment it by one
        temp = counter; 
        temp = temp + 1;
   	
        // introduce here a one-second delay to increase the probability of a preemption 
        // occurring between the update of temp and the subsequent update of counter

        counter = temp;

        // print the value of the counter

        // unlock the mutex (try to see how the behavior changes if the mutex is present or absent)
    }
    return NULL;
}  
