#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

#define SHMSIZE 1024

int main(void)
{
	char c, tmp;
	int shmId;
	key_t key;
	char *shm, *s;

	key = 1234;
	
	if ((shmId = shmget(key, SHMSIZE, IPC_CREAT | 0666)) < 0) // create a segment and set permissions
	{
		perror("shmget");
		exit(1);
	}
	
	if ((shm = shmat(shmId, NULL, 0)) == (char*) -1) //attach the segment to program's data space
	{
		perror("shmat");
		exit(1);
	}

	memset(shm, 0, SHMSIZE);
	s = shm;

	while(*shm != 'q')
	{
		sleep(1);
		if (tmp == *shm)
			continue;
		
		fprintf(stdout, "%c \n", *shm);
		tmp = *shm;
	}

	if (shmdt(shm) != 0)
	{
		fprintf(stderr, "Could not close memory segment.\n");
	}

	return 0;
}

