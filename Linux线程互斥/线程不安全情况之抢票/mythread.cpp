#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace std;
int ticket=1000;

void* get_ticket(void* arg)
{
    while(1)
    {
        if(ticket>0)
        {
            cout<<"i am "<<pthread_self()<<" get a ticket,no:"<<ticket<<endl;
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
        int ret=pthread_create(&tid[i],NULL,get_ticket,NULL);
        if(ret!=0)
        {
            cout<<"线程创建失败!"<<endl;
        }

    }
    for(int i=0;i<4;i++)
    {
        pthread_join(tid[i],NULL);
    }

    cout<<"pthread_join end!"<<endl;
    return 0;
}
