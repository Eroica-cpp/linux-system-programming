#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/fcntl.h>

main(){
	int fd, j;
	char *myc = "This is my first program!\n";
	char *myf = "myfile";

	if ( ( fd = open(myf, O_RDWR|O_CREAT|O_APPEND,0644) ) == -1 ){
		perror(myf);
		exit(errno);
	}

	if ( write(fd, myc, strlen(myc)) != strlen(myc) ){
		perror(myc);
		close(fd);
		exit(errno);
	}
	else {
		char cmd[30] = "cat ";
		//system( strcat("cat ", myf) ) // mistake!
		system( strcat(cmd, myf) );
	}
	
	close(fd);
}