/* calcserver.c */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include "clientinfo.h"

//#define FIFO_NAME "/tmp/server_info"
#define FIFO_NAME "/media/disk/Dropbox/courseMaterials/semester6/linuxSystemProgramming_yuhongFeng/assignment2/code/litao2011190026/chat_app/data/server_info"
#define BUFF_SZ 100

void handler(int sig){
	unlink(FIFO_NAME);
	exit(1);
}

int calc(CLIENTINFOPTR info){
	switch(info -> op){
		case '+': return info -> leftarg + info -> rightarg;
		case '-': return info -> leftarg - info -> rightarg;
		case '*': return info -> leftarg * info -> rightarg;
		case '/': return info -> leftarg / info -> rightarg;
	}

	return 0;
}

int main(){
	int res;
	int i;
	int fifo_fd, fd1, fd2;
	CLIENTINFO info1, info2;
	char buffer[BUFF_SZ];

	/* handle some signals */
	signal(SIGKILL, handler);
	signal(SIGINT, handler);
	signal(SIGTERM, handler);

	/* create FIFO if necessary*/
	if (access(FIFO_NAME, F_OK) == -1){
		res = mkfifo(FIFO_NAME, 0777);
		if (res != 0){
			printf("FIFO %s was not created\n", FIFO_NAME);
			exit(EXIT_FAILURE);
		}
	}	

	/* open fifo for reading */
	fifo_fd = open(FIFO_NAME, O_RDONLY);
	if (fifo_fd == -1){
		printf("Could not open %s for read only access.\n", FIFO_NAME);
		exit(EXIT_FAILURE);
	}

	printf("\nServer is raring to go!\n");

	while(1) {
		// for client 1
		res = read(fifo_fd, &info1, sizeof(CLIENTINFO));
		if (res != 0){
			sprintf(buffer, "From %s:\n %s\n\n", info1.myfifo, info1.msg);
			fd2 = open(info2.myfifo, O_WRONLY | O_NONBLOCK);
			write(fd2, buffer, strlen(buffer) + 1);
			close(fd2);			
		}

		// for client 2
		res = read(fifo_fd, &info2, sizeof(CLIENTINFO));
		if (res != 0){
			sprintf(buffer, "From %s:\n %s\n\n", info2.myfifo, info2.msg);
			fd1 = open(info1.myfifo, O_WRONLY | O_NONBLOCK);
			write(fd1, buffer, strlen(buffer) + 1);
			close(fd1);			
		}		
	}

	exit(0);
}