#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid[2];
int counter = 0;
pthread_mutex_t lock;

void* threadFunc(void *arg)
{
	pthread_mutex_lock(&lock);

	unsigned long i = 0;
	counter += 1;
	printf("\nJob %d started\n", counter);

	for(i = 0; i < (0xffffffff); i++);	//variable counter is shared among both the threads,

	printf("\nJob %d finished\n", counter);//if before finishing thread 1, if thread 2 starts executing 

	pthread_mutex_unlock(&lock);	      //then 'counter' variable will be incremented before job 1 gets
					      // finished
	return NULL;
}

int main(void)
{
	int i = 0;
	int err;

	if (pthread_mutex_init(&lock, NULL) != 0)
	{
		printf("Mutex init failed\n");
		return 1;
	}

	while (i<2)
	{
		err = pthread_create(&(tid[i]), NULL, &threadFunc, NULL );
		if (err != 0)
		{
			printf("Cann't create thread : [%s]", strerror(err));
		}
		i++;
	}

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_mutex_destroy(&lock);
	
	return 0;
}	
