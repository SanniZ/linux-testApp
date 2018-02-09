
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
	fd_set rdfds;
	struct timeval tv;
	int rc;
	
	FD_ZERO(&rdfds);
	FD_SET(0, &rdfds);

	tv.tv_sec = 5;
	tv.tv_usec = 500;

	rc = select(1, &rdfds, NULL, NULL, &tv);
	if (rc < 0)
		printf("select.\n");
	else
		printf("rc=%d\n", rc);		

	return rc;
}

