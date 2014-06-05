// reference: C programming on Linux, Chpt 8, p209
// example for join and exit of threads
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void assist_thread(void* arg){
	printf("I am assist_thread!\n");
	sleep(3);
	pthread_exit(0);
}

int main(void){
	
	pthread_t assist_thid;
	int status;

	pthread_create(&assist_thid, NULL, (void *) assist_thread, NULL);
	pthread_join(assist_thid, (void *) & status);
	printf("assist_thread is exit with status num %d\n", status);

	return 0;
}