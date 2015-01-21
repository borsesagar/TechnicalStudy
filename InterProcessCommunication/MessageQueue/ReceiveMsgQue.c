#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAXSIZE 128

struct msgBuf
{
	long msgType;
	char msgText[MAXSIZE];
};

int main(void)
{
	int msgId;
	key_t key;
	struct msgBuf rBuf;

	key = 1234;
	
	if((msgId = msgget(key, 0666)) < 0)
	{
		perror("msgsnd");
		exit(1);
	}
	//Receive an ans of message type 1.
	printf("Received Message/s is/are: \n");
	for(;;) //this never quits
	{
		if (msgrcv(msgId, &rBuf, MAXSIZE, 1, 0) < 0)
		{
			printf("%d, %d, %s, %d\n", msgId, rBuf.msgType, rBuf.msgText);
			perror("msgsnd");
			exit(1);
		}
		else
			printf(" %s\n", rBuf.msgText);
	}

	
	return 0;
}

