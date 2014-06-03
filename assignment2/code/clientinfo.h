/* clientinfo.h */
#ifndef _CLIENTINFO_H
#define _CLIENTINFO_H

typedef struct
{
	char myfifo[1000];	// client's info name
	char msg[1000];		// message to deliver
	int leftarg;		// left argument of calculation
	int rightarg;		// right argument of calculation
	char op;			// operation: + - * /
} CLIENTINFO, *CLIENTINFOPTR;

#endif