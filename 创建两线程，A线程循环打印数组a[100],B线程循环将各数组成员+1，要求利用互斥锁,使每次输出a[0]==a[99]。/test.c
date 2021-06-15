#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>

pthread_t thread[2];
pthread_mutex_t mut;
int a[100];
void thread1() 
{
	printf("这是第一个线程\n");
	for (int i = 0; i <= 50; i++)
	{
		printf("线程1：pid=%d,a[i]=%d\n", getpid(), i);
		pthread_mutex_lock(&mut);
		pthread_mutex_unlock(&mut);
		sleep(1);
	}
}

void thread2() 
{
	printf("这是第二个线程\n");
	for (int i = 0; i <= 50; i++)
	{
		printf("线程2：pid=%d,a[i]=%d\n", getpid(), 99-i);
		pthread_mutex_lock(&mut);
		pthread_mutex_unlock(&mut);
		sleep(1);
	}
}

int main(void) 
{
	int i, ret1,ret2;
	ret1 = pthread_create(&thread[0], NULL, (void *)thread1, NULL);
	if (ret1 != 0) 
	{
		printf("Create pthread1 error!\n");
		exit(1);
	}
	ret2 = pthread_create(&thread[1], NULL, (void *)thread2, NULL);
	if (ret2 != 0) 
	{
		printf("Create pthread2 error!\n");
		exit(1);
	}

	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);
	return 0;
}


