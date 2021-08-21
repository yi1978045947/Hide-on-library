#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
sem_t blank_number,product_number;
void *outA(void *arg)
{
	while(1){
		sem_wait(&blank_number);
		printf("%c\n",65);
		sem_post(&product_number);
		sleep(rand()%5);
	}
}
void *outB(void *arg)
{
	while(1){
		sem_wait(&product_number);
		printf("%c\n",66);
		sem_post(&blank_number);
		sleep(rand()%5);
	}
}
int main(int argc,char *argv[])
{
	pthread_t pid,cid;
	sem_init(&blank_number,0,1);
	sem_init(&product_number,0,0);
	pthread_create(&pid,NULL,outA,NULL);
	pthread_create(&cid,NULL,outB,NULL);
	pthread_join(pid,NULL);
	pthread_join(cid,NULL);
	sem_destroy(&blank_number);
	sem_destroy(&product_number);
	exit(1);
	return 0;
}

