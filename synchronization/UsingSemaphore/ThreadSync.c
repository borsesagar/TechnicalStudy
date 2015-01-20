#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t smp;
int counter = 0;

void* ThreadFunc(void* value)
{
	printf("%s is now entering the thread function. \n", (char*)value);
	sem_wait(&smp);
	counter++;
	sleep(2);
	sem_post(&smp);
	printf("%s is now leaving the thread function. \n", (char*)value);
	printf("Value of counter is : %d\n", counter);
	pthread_exit(value);
}

int main(void)
{
	int res;
	pthread_t th[2];

	sem_init(&smp, 0, 1); //smp: semaphore variable, 0 : for thread context, 1: value of semaphore variable
	
	res = pthread_create(&th[0], NULL, ThreadFunc, "Thread 1");
	if (res != 0)
	{
		perror("Creation of thread failed");
		exit(EXIT_FAILURE);
	}

	res = pthread_create(&th[1], NULL, ThreadFunc, "Thread 2");
	if (res != 0)
	{
		perror("Creation of thread failed");
		exit(EXIT_FAILURE);
	}

	res = pthread_join(th[0], NULL);
	if (res != 0)
	{
		perror("joining of thread failed");
		exit(EXIT_FAILURE);
	}


	res = pthread_join(th[1], NULL);
	if (res != 0)
	{
		perror("joining of thread failed");
		exit(EXIT_FAILURE);
	}

	sem_destroy(&smp);
}
