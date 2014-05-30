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
	} else {
		printf("I am a parent process %d with child %d\n", getpid(), pid);
	}

	if ((pid = wait(&status)) == -1){
		perror("wait failed\n");
		exit(2);
	}

	// Q: what following code means? A: note p30
	if (exit_status = WIFEXITED(status)){
		printf("exit status from %d was %d, and the actual status was %d\n", pid, exit_status, WEXISTATUS(status));
	} 
	exit(0);

	return 0;
}