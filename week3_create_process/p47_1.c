// distinction between fork() and vfork().
// example code on page 47 of note.
#include <unistd.h>
#include <stdio.h>

int main(){
	pid_t pid;
	int count = 0;
	pid = fork();
	//pid = vfork(); // don't do that. exit() must be called.
	count ++;
	printf("count = %d, pid = %d\n", count, getpid());
	return 0;
}

