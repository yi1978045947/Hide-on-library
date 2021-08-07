#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace std;

int g_bowl=1;
pthread_mutex_t g_lock;

void* EatStart(void* arg)
{
    (void)arg;

    while(1)
    {
        pthread_mutex_lock(&g_lock);
        g_bowl--;
        cout<<"i am:"<<pthread_self()<<" i eat:"<<g_bowl<<endl;
        pthread_mutex_unlock(&g_lock);
    }
    return NULL;
}
void *MakeStart(void* arg)
{
    (void)arg;
    while(1)
    {
        pthread_mutex_lock(&g_lock);
        g_bowl++;
        cout<<"i am:"<<pthread_self()<<" i make:"<<g_bowl<<endl;
        pthread_mutex_unlock(&g_lock);
    }
    return NULL;
}
int main()
{
    pthread_mutex_init(&g_lock,NULL);

        pthread_t tid_eat;
        pthread_t tid_make;
        int ret=pthread_create(&tid_eat,NULL,EatStart,NULL);
        if(ret<0)
        {
            cout<<"线程创建失败!"<<endl;
        }

        ret=pthread_create(&tid_make,NULL,MakeStart,NULL);
        {
            if(ret<0)
            {
                cout<<"线程创建失败!\n"<<endl;
            }
        }

    while(1)
    {
        sleep(1);
    }


    pthread_mutex_destroy(&g_lock);
    return 0;
}
