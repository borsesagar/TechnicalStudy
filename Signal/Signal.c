#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sigHandler(int sig)
{
	char c = '\0';
	signal(sig, SIG_IGN); //ignore the signal
	printf("\nCtrl-C pressed!!\n");
	printf("Do you really want to quite [y/n]?\n");
	c = getchar();

	if (c =='y' || c == 'Y')
		exit(0);
	else
		signal(SIGINT, sigHandler); //reinstall the signal handler
}

int main(void)
{
	if (signal(SIGINT, SIG_IGN) != SIG_IGN)
		signal(SIGINT, sigHandler);

	while(1);
		sleep(1);
	return 0;
}


