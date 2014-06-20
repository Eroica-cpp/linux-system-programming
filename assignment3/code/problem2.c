// code for problem 2 assignment 3
// Author: Tao Li
// Email: eroicacmcs@gmail.com
// Date: Jun 20, 2014

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg);
pthread_mutex_t work_mutex;

int run_now = 1;	// shared resource
int main()
{
	int print_count1 = 0;
	pthread_t a_thread;

	if (pthread_mutex_init(&work_mutex, NULL) != 0){
		perror("Mutex init failed\n");
		exit(1);
	}

	if (pthread_create(&a_thread, NULL, thread_function, NULL) != 0){
		perror("Thread creation failed!\n");
		exit(1);
	}

	if (pthread_mutex_lock(&work_mutex) != 0){
		perror("Lock failed\n");
		exit(1);
	} else {
		printf("Main lock.\n");
	}

	while (print_count1++ <= 5) {
		if (run_now == 1){
			printf("Main thread is running\n");
			run_now = 2;
		} else {
			printf("Main thread is sleeping\n");
			sleep(1);
		}
	}

	if (pthread_mutex_unlock(&work_mutex) != 0){
		perror("Unlock failed\n");
		exit(1);
	} else {
		printf("Main unlock.\n");
	}	

	pthread_join(a_thread, NULL);
	pthread_mutex_destroy(&work_mutex);
	exit(0);

}

void *thread_function(void *arg){
	
	int print_count2 = 0;

	while (print_count2 ++ <= 5) {
		if (run_now == 2){
			printf("function thread is runing\n");
			run_now = 1;
		} else {
			printf("function thread is sleeping\n");
			sleep(1);
		}
	}

	pthread_exit(NULL);
}