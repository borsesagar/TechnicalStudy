#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MSGLEN 64

int main(void)
{
	int fd[2];
	pid_t pid, pd;
	int ret;

	//creating pipe
	ret = pipe(fd);
	if (ret < 0)
	{
		//failure in creating pipe
		perror("failiure in creating pipe");
		exit(1);
	}

	//creating a child process
	pid = fork();
	if (pid < 0)
	{
		//failure in creating child process
		perror("failure in creating child process");
		exit(2);
	}
	if (pid == 0)
	{
		//child process
		char wrMsg[MSGLEN];
		
		printf("Enter a small message: ");
		scanf("%s", wrMsg);
   		//writing message to the pipe
		write(fd[1], wrMsg, strlen(wrMsg));
	}
	else
	{
		//parent process
		int status;
		pd = wait(&status);
		char rdMsg[MSGLEN];

      		//reading message from the pipe
		read(fd[0], rdMsg, sizeof(rdMsg));
		sleep(5);
		printf("Message Entered Was :: %s\n", rdMsg);
	}
	return 0;
}
