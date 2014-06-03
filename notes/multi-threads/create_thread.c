// reference: C programming on Linux, Chpt 8, p206
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int* thread(void* arg){
	pthread_t newthread;

	newthread = pthread_self();
	printf("This is a new thread, thread id = %u\n", newthread);

	return NULL;
}

int main(void){
	
	pthread_t thread_id;

	printf("main thread, id = %u\n", pthread_self());
	if (pthread_create(&thread_id, NULL, (void *)thread, NULL) != 0){
		printf("thread creation failed.\n");
		exit(1);
	}
	sleep(1);
	exit(0);
}
