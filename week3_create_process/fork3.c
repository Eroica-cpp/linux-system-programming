#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
	int remaining = 4;
	int child_pid;
	child_pid = fork();	
	// printf("%d\n", child_pid);
	while (remaining > 0){
		child_pid = fork();
		if (child_pid == 0){
			break;
		}
		remaining --;
	}
	printf("pid: %lu, ppid: %lu, remaining: %d\n", (long)getpid(), (long)getppid(), remaining);
	return 0;

}