// code for problem 1 assignment 3
// Author: Tao Li
// Email: eroicacmcs@gmail.com
// Date: Jun 20, 2014

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
	int value;
	char string[128];
} thread_parm_t;

void *threadfunc(void *parm)
{
	thread_parm_t *p = (thread_parm_t *) parm;
	if (p -> value == 5) {
		printf("thread 1 is sleeping\n");
		sleep(2);
		printf("thread 1 is awaked\n");
	}
	printf("%s, parm = %d\n", p -> string, p -> value);
	free(p);
	return NULL;
}

int main(int argc, char **argv)
{
	pthread_t thread1, thread2;
	int rc = 0, status;
	thread_parm_t *parm = NULL;
	printf("Create a thread attributes objects\n");
	
	// first thread
	parm = malloc(sizeof(thread_parm_t));
	parm -> value = 5;
	strcpy(parm -> string, "Inside first thread");
	rc = pthread_create(&thread1, NULL, threadfunc, (void *) parm);

	// second thread
	parm = malloc(sizeof(thread_parm_t));
	parm -> value = 77;
	strcpy(parm -> string, "Inside Second thread");
	rc = pthread_create(&thread2, NULL, threadfunc, (void *) parm);
	
	pthread_join(thread1, (void *) &status);	// wait first thread
	pthread_join(thread2, (void *) &status);	// wait second thread

	printf("Main completed\n");
	return 0;
}