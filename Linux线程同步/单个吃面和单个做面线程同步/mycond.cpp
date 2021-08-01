#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace std;

int g_bowl=1;
pthread_mutex_t g_lock;

pthread_cond_t g_eat_cond;
pthread_cond_t g_make_cond;

//吃面
void* EatStart(void* arg)
{
    (void)arg;

    while(1)
    {
        pthread_mutex_lock(&g_lock);
        if(g_bowl<=0)
        {
            pthread_cond_wait(&g_eat_cond,&g_lock);//传递互斥锁是后面要解锁
        }
        g_bowl--;
        cout<<"i am:"<<pthread_self()<<" i eat:"<<g_bowl<<endl;
        pthread_mutex_unlock(&g_lock);

        pthread_cond_signal(&g_make_cond);//通知做面的人来做面
    }
    return NULL;
}

//做面
void *MakeStart(void* arg)
{
    (void)arg;
    while(1)
    {
        pthread_mutex_lock(&g_lock);
        if(g_bowl>0)
        {
            pthread_cond_wait(&g_make_cond,&g_lock);
        }
        g_bowl++;

        cout<<"i am:"<<pthread_self()<<" i make:"<<g_bowl<<endl;
        pthread_mutex_unlock(&g_lock);

        pthread_cond_signal(&g_eat_cond);//通知吃面的人来吃面
    }
    return NULL;
}
int main()
{
    //初始化互斥锁
    pthread_mutex_init(&g_lock,NULL);
    
    //初始化条件变量
    pthread_cond_init(&g_eat_cond,NULL);
    pthread_cond_init(&g_make_cond,NULL);

    int i=0;
    for(i=0;i<1;i++)
    {
        pthread_t tid;
        int ret=pthread_create(&tid,NULL,EatStart,NULL);
        if(ret<0)
        {
            cout<<"线程创建失败!"<<endl;
        }

        ret=pthread_create(&tid,NULL,MakeStart,NULL);
        {
            if(ret<0)
            {
                cout<<"线程创建失败!\n"<<endl;
            }
        }
    }

    while(1)
    {
        sleep(1);
    }

    //销毁互斥锁
    pthread_mutex_destroy(&g_lock);

    //销毁条件变量
    pthread_cond_destroy(&g_eat_cond);
    pthread_cond_destroy(&g_make_cond);
    return 0;
}
