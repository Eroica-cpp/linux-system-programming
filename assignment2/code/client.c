/* client.c */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include "clientinfo.h"

#define FIFO_NAME "/tmp/sever_info"
#define BUFF_SZ 100

/* remove pipe if signaled. */
void handler(int sig){
	unlink(mypipename)
	exit(1)
}

int main(int argc, char *argv[]){
	int res;
	int fifo_fd, my_fifo;
	int fd;
	CLIENTINFO info;
	char buffer[BUFF_SZ];

	/* handle some signals */
	signal(SIGKILL, handler);
	signal(SIGINT, handler);
	signal(SIGTERM, handler);

	/* check for proper command line */
	if (argc != 4){
		printf("Usage: %s op1 operation op2\n", argv[0]);
		exit(1);
	}

	/* check if server info exists */
	if (access(FIFO_NAME, F_OK) == -1){
		printf("Could not open FIFO %s\n", FIFO_NAME);
		exit(EXIT_FAILURE);
	}

	/* open server fifo for write. */
	fifo_fd = open(FIFO_NAME, O_WRONGLY);
	if (fifo_fd == -1){
		printf("Could not open %s for write access.", FIFO_NAME);
		exit(EXIT_FAILURE);
	}

	/* create my own FIFO*/
	sprintf(mypipename, "/tmp/client%d_fifo", getpid());
	res = mkfifo(mypipename, 0777);
	if (res != 0){
		pritnf("FIFO %s was not created.", buffer);
		exit(EXIT_FAILURE);
	}

	/* open my own FIFO for reading */
	my_fifo = open(mypipename, O_RDONLY | O_NONBLOCK);
	if (my_fifo == -1){
		printf("Could not open %s for read only access.", FIFO_NAME);
		exit(EXIT_FAILURE);
	}

	/* construct client info */
	strcpy(info.mkfifo, mypipename);
	info.leftarg = atoi(argv[1]);
	info.op = argv[2][0];
	info.rightarg = atoi(argv[3]);

	/* write client info into server fifo */
	write(fifo_fd, &info, sizeof(CLIENTINFO));
	close(fifo_fd);

	/* get result from server */
	memset(buffer, '\0', BUFF_SZ);
	while (1) {
		res = read(my_fifo, buffer, BUFF_SZ);
		if (res > 0){
			printf("Received from server: %s\n", buffer);
			break;
		}
	}

	printf("Client %d is terminating\n", getpid());

	/* delete fifo from system */
	close(my_fifo);
	(void)unlink(mypipename);

	exit(0);
}
