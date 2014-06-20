// code for problem 2 assignment 3
// Author: Tao Li
// Email: eroicacmcs@gmail.com
// Date: Jun 20, 2014

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg);

int run_now = 1;	// shared resource
int main()
{
	int print_count1 = 0;
	pthread_t a_thread;

	if(pthread_create(&a_thread, NULL, thread_function, NULL) != 0){
		perror("Thread creation failed!\n");
		exit(1);
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
	pthread_join(a_thread, NULL);
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