#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace std;
int ticket=1000;

pthread_mutex_t g_lock; //全局变量的互斥锁

void* get_ticket(void* arg)
{
    while(1)//1位置加锁还是在2位置加锁
    {
        pthread_mutex_lock(&g_lock);
        //pos1
        if(ticket>0)
        {
            usleep(1);
            cout<<"i am "<<pthread_self()<<" get a ticket,no:"<<ticket<<endl;
            //pos2
            ticket--;
            pthread_mutex_unlock(&g_lock);
        }
        else 
        {
            pthread_mutex_unlock(&g_lock);
            break;
        }
    }
    return NULL;
}
int main()
{
    pthread_mutex_init(&g_lock,NULL);//初始化互斥锁
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
    pthread_mutex_destroy(&g_lock);
    return 0;
}
