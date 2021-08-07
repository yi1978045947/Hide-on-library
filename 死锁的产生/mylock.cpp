#include<iostream>
#include<unistd.h>
#include<pthread.h>
using namespace std;

pthread_mutex_t g_lock1;
pthread_mutex_t g_lock2;
void* ThreadStart1(void* args)
{
    (void)args;
    pthread_mutex_lock(&g_lock1);
    sleep(5);
    pthread_mutex_lock(&g_lock2);
    return NULL;
}
void* ThreadStart2(void* args)
{
    (void)args;
    pthread_mutex_lock(&g_lock2);
    sleep(5);
    pthread_mutex_lock(&g_lock1);
    return NULL;
}
int main()
{
    pthread_mutex_init(&g_lock1,NULL);
    pthread_mutex_init(&g_lock2,NULL);

    pthread_t tid;
    int ret=pthread_create(&tid,NULL,ThreadStart1,NULL);
    if(ret<0)
    {
        cout<<"线程创建失败!"<<endl;
        return 0;
    }

    ret=pthread_create(&tid,NULL,ThreadStart2,NULL);
    if(ret<0)
    {
        cout<<"线程创建失败!"<<endl;
        return 0;
    }

    while(1)
    {
        ;
    }
    pthread_mutex_destroy(&g_lock1);
    pthread_mutex_destroy(&g_lock2);
    return 0;
}
