// distinction between fork() and vfork().
// example 3  on page 47 of note.
#include <unistd.h>
#include <stdio.h>

int main(){
	pid_t pid;
	int count = 0;
	
	pid = vfork();
	if (pid == 0){
		count ++;
		printf("count = %d, pid = %d, ppid = %d\n", count, getpid(), getppid());
		_exit(0);
	} else {
		count ++;
		printf("count = %d, pid = %d, ppid = %d\n", count, getpid(), getppid());
	}

	return 0;
}