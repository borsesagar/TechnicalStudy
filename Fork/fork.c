#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	pid = fork();
	
	if (pid < 0)
	{
		fprintf(stderr, "fork failed\n");
		exit(-1);
	}
	else if (pid == 0)
	{
		//child process
		printf("This is a child process, return form fork = %d\n", pid);
	//	execlp("/bin/ps", "ps", NULL);
	}
	else
	{
		//parent process 
		printf("This is a parent process, return from fork() = %d\n", pid);
		printf("Parent exiting!!\n");
		exit(0);
	}

	return 0;
}
		
