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
	struct msgBuf sBuf;
	size_t bufLen;

	key = 1234;

	if ((msgId = msgget(key, IPC_CREAT | 0666)) < 0) //Get the message Queue
	{
		perror("msgget");
		exit(1);
	}
	sBuf.msgType = 1;
	
	printf("Please write your message\n");
	while (fgets(sBuf.msgText, sizeof(sBuf.msgText), stdin) != NULL)
	{
		bufLen = strlen(sBuf.msgText) + 1;
		if (msgsnd(msgId, &sBuf, bufLen, IPC_NOWAIT) < 0) //Send the message
		{
			printf("%d, %d, %s, %d\n", msgId, sBuf.msgType, sBuf.msgText);
			perror("msgsnd");
			exit(1);
		}
	else
		printf("Message Sent!!\n");
	}

	if (msgctl(msgId, IPC_RMID, NULL) < 0) //Destroy msg queue
	{
		perror("msgctl");
		exit(1);
	}
	return 0;
}


	
