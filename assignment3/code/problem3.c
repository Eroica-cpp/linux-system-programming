// code for problem 2 assignment 3
// Author: Tao Li
// Email: eroicacmcs@gmail.com
// Date: Jun 20, 2014

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define NLOOP 5000

int counter = 0;	// incremented by threads
pthread_mutex_t work_mutex;
void *increase(void *vptr);

int main(int argc, char ** argv)
{
	pthread_t thread_A, thread_B;

	pthread_create(&thread_A, NULL, &increase, NULL);
	pthread_create(&thread_B, NULL, &increase, NULL);

	// wait for both threads to terminate
	pthread_join(thread_A, NULL);
	pthread_join(thread_B, NULL);

	return 0;
}

void *increase(void *vptr){

	int i, val;

	for (i = 0; i < NLOOP; i++){
		
		if (pthread_mutex_lock(&work_mutex) != 0){
			perror("Lock failed\n");
			exit(1);
		} else {
			printf("%x lock.\n", (unsigned int) pthread_self());
		}	

		val = counter;
		printf("%x: %d\n", (unsigned int) pthread_self(), val + 1);
		counter = val + 1;
	
		if (pthread_mutex_unlock(&work_mutex) != 0){
			perror("Unlock failed\n");
			exit(1);
		} else {
			printf("%x unlock.\n", (unsigned int) pthread_self());
		}		

	}

	return NULL;
}