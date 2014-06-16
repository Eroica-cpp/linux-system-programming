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
	printf("%s, pram = %d\n", p -> string, p -> value);
	free(p);
	return NULL;
}

int main(int argc, char **argv)
{
	return 0;
}