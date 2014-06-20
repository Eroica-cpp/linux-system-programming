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
	printf("%s, parm = %d\n", p -> string, p -> value);
	free(p);
	return NULL;
}

int main(int argc, char **argv)
{
	pthread_t thread;
	int rc = 0;
	thread_parm_t *parm = NULL;
	printf("Create a thread attributes objects\n");
	parm = malloc(sizeof(thread_parm_t));
	parm -> value = 5;
	strcpy(parm -> string, "Inside first thread");
	//rc = pthread_create(&thread, NULL, threadfunc, (void *) parm);
	printf("%s, parm = %d\n", parm -> string, parm -> value);
	printf("Main completed\n");
	return 0;
}