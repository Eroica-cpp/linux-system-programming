// reference: C programming on Linux, Chpt 8, p206-p207
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void run(void){
	printf("Function run is running in thread %lu\n", pthread_self());
}

void* thread1(void* arg){
	pthread_t thid = pthread_self();
	printf("Current thread's id is %lu\n", thid);
	pthread_once(&once, run);
	printf("thread1 end\n");
}

void* thread2(void* arg){
	pthread_t thid = pthread_self();
	printf("Current thread's id is %lu\n", thid);
	pthread_once(&once, run);
	printf("thread2 end\n");
}

int main(){
	pthread_t thid1, thid2;

	pthread_create(&thid1, NULL, thread1, NULL);
	pthread_create(&thid2, NULL, thread2, NULL);
	sleep(3);
	printf("main thread exit!\n");
	exit(0);
}