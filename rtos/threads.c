#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

pthread_mutex_t lock;


void *thread_routine(void* message);

#define MAX_THREADS 5

int main()
{
	pthread_t thread_id[MAX_THREADS];
	if (pthread_mutex_init(&lock, NULL) != 0)
	{
		printf("\n mutex init has failed\n");
		return -1;
	}

	//char *message = "Hi To thread";
	int number_of_threads = MAX_THREADS;
	int count = 0;
	int ret=-1;
	/* create thread, pass message to thread */
	for(count = 0; count < MAX_THREADS; count++)
	{
		ret = pthread_create(&thread_id[count],NULL,thread_routine,(void *)&count);
		if(ret != 0)
			printf("ERROR: %d, pthread_create failed\n",ret);
	}

	/* wait for thread to join back before exiting main process */
	for(count = 0; count < MAX_THREADS; count++)
	{
		pthread_join(thread_id[count],NULL);
	}
	pthread_mutex_destroy(&lock);
	return 0;
}

void *thread_routine(void * in_message)
{
	pthread_mutex_lock(&lock);
	int thread_number = *(int *)in_message;
	printf("@%s, pid: %ld, Message received is: %d\n",__FUNCTION__,pthread_self(),thread_number);
	pthread_mutex_unlock(&lock);
}