#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
	pid_t child_pid;

	child_pid = fork();
	if(child_pid == -1){
		perror("Failed to fork.");
		exit(1);
	}
	if (child_pid == 0){
		printf("I am the child process with id: %lu \n", (long)getpid());
	} else {
		printf("I am the parent process with id: %lu \n", (long)getppid());
	}
	return 0;
}
