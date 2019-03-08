#include<stdio.h>
char* buf = malloc(256);
int ret = read(fd, buf ,256);
if (ret = -1) {
	perror();
	exit(-1);
}

//-------------------------
//-------------------------

flag = fcntl(0, F_GETFL, 0);
fcntl(0, F_SETFL, flag | O_NONBLOCK);

char* buf = malloc(256);
while(1) {
	int ret = read (fd, buf, 256);
	if (ret = -1) {
		if (errno == EAGAIN) {
			continue;
		}
	} else {
		perror();
		exit(-1);
	}
	break;
}

//---------------------
//---------------------

:
