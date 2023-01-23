#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_THREADS 10
#define COUNT_DONE  10
#define COUNT_HALT1  3
#define COUNT_HALT2  6
/* define pthread murex and conditional variables  */
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  condition_var   = PTHREAD_COND_INITIALIZER;

/* thread rountine for muthi thread with mutex  */
void *thread_routine(void *message);

/* conditional threads  */
void *thread_fun1();
void *thread_fun2();
/* global variable to be used as critical section  */
static int counter = 0;
static int value = 0;

int main()
{
	pthread_t thread_id[MAX_THREADS];
	pthread_t cond_thread1,cond_thread2;

	if (pthread_mutex_init(&lock, NULL) != 0)
	{
		printf("\n mutex init has failed\n");
		return -1;
	}

	int number_of_threads = MAX_THREADS;
	long int count = 0;
	int ret=-1;
	/* create thread, pass message to thread */
	for(count = 0; count < MAX_THREADS; count++)
	{
		ret = pthread_create(&thread_id[count],NULL,thread_routine,(void *)count);
		if(ret != 0)
			printf("ERROR: %d, pthread_create failed\n",ret);
	}

	/* wait for thread to join back before exiting main process */
	for(count = 0; count < MAX_THREADS; count++)
	{
		pthread_join(thread_id[count],NULL);
		//printf("thread_id[%ld]:%ld joined\n",count,thread_id[count]);
	}
	printf("all threads joined, counter: %d\n",counter);

	printf("\n****test pthread conditions with mutex****\n");

	/* create 2 threads for conditional wait implimentaion  */
	ret = pthread_create(&cond_thread1,NULL,thread_fun1,NULL);
	ret = pthread_create(&cond_thread2,NULL,thread_fun2,NULL);
	/* wait for threads to join  */
	pthread_join(cond_thread1,NULL);
	pthread_join(cond_thread2,NULL);

	printf("cond threads joined, value: %d\n",value);

	/* destroy the mutex */
	pthread_mutex_destroy(&lock);
	return 0;
}

void *thread_routine(void *in_message)
{
	/* lock and access/update the critical job */
	pthread_mutex_lock(&lock);
	long thread_number = (long )in_message;
//	sleep(1);
	printf("@%s, thread id %ld, thread_number is: %ld, counter: %d\n",__FUNCTION__,pthread_self(),thread_number,++counter);
	pthread_mutex_unlock(&lock);
}


/* print numbers permitted by thread_fun2 */
void *thread_fun1()
{
	while(1)
	{
		pthread_mutex_lock(&lock);
		//wait untill other thread (thread_fun2) signals
		//increment the count
		pthread_cond_wait(&condition_var,&lock);
		value++;
		printf("@%s: value: %d\n",__FUNCTION__,value);
		pthread_mutex_unlock(&lock);

		if(value >= COUNT_DONE)
			return(NULL);
	}
}

/* print 4-7  */
void *thread_fun2()
{
	while(1)
	{
		if(value < COUNT_HALT1 || value > COUNT_HALT2 )
		{
			// Condition of if statement has been met.
			// Signal to free waiting thread by freeing the mutex.
			// Note: functionCount1() is now permitted to modify "value"
			pthread_cond_signal(&condition_var);
		}
		else
		{
			value++;
			printf("@%s: value: %d\n",__FUNCTION__,value);
		}
		if(value >= COUNT_DONE)
			return (NULL);
	}
}
