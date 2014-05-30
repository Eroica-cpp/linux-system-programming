#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
	pid_t child_pid;
	pid_t mypid;

	mypid = getpid();
	child_pid = fork();
	if (child_pid == -1){
		perror("Fail to fork");
		exit(1);
	}
	if (child_pid == 0){
		printf("I am the child process with id: %lu -- %lu\n", (long)getpid(), (long)mypid);
	} else {
		printf("I am the parent process with id: %lu -- %lu\n", (long)getpid(), (long)mypid);
	}
	return 0;
}