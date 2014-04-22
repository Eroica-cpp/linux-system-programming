#include <sys/types.h>
#include <unistd.h>

int main(){
	printf("process id: %ld\n", (long)getpid());
	printf("parent id: %ld\n", (long)getppid());
	return 0;
}
