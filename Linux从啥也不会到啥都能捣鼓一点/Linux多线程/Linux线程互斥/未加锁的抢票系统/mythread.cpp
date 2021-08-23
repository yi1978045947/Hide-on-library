#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace std;
int ticket=100;


void* get_ticket(void* arg)
{
    int* num=(int*)arg;
    while(1)
    {
        if(ticket>0)
        {
            sleep(1); 
            cout<<"thread "<<num<<" get a ticket,no:"<<ticket<<endl;
            ticket--;
        }
        else 
        {
            break;
        }
    }
    return NULL;
}
int main()
{
    pthread_t tid[4];
    for(int i=0;i<4;i++)
    {
        pthread_create(tid+1,NULL,get_ticket,(void*)i);

    }
    for(int i=0;i<4;i++)
    {
        pthread_join(tid[i],NULL);
    }
    return 0;
}
