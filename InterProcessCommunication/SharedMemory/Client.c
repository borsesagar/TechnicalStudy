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
	int shmId;
	key_t key;
	char *shm, *s;

	key = 1234;
	if ((shmId = shmget(key, SHMSIZE, 0666)) < 0)
	{
		perror("shmget");
		exit(1);
	}

	if ((shm = shmat(shmId, NULL, 0)) < 0)
	{
		perror("shmget");
		exit(1);
	}

	memset(shm, 0, SHMSIZE);
	s = shm;
	for(;;)
	{
		char tmp = getchar();
		getchar();
		if (tmp == 'q')
		{
			*shm = 'q';
			break;
		}
		*shm = tmp;
	}

	if (shmdt(shm) != 0)
	{
		perror("shmdt");
		exit(1);
	}
	return 0;
}
	
		
