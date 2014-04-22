#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
	pid_t pid;
	int status, exit_status;

	if ((pid = fork()) < 0)
		perror("fork failed.\n");
	if (pid == 0){
		sleep(4);
		exit(5);
	} 
	
}