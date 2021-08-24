#include<iostream>
#include<unistd.h>
#include<pthread.h>
using namespace std;

struct ThreadId
{
    int thread_id;
};
void* MyThreadStrat(void* arg)
{
    struct ThreadId* tid=(struct ThreadId*)arg;
    while(1)
    {
        cout<<"MyThreadStrat:"<<tid->thread_id<<endl;
        sleep(1);
    }
    delete tid;
}
int main()
{
    pthread_t tid;
    int i=0;
    for( i=0;i<4;i++)
    {
        struct ThreadId* id=new ThreadId();
        id->thread_id=i;
        int ret=pthread_create(&tid,NULL,MyThreadStrat,(void*)id);
        if(ret!=0)
        {
            cout<<"线程创建失败!"<<endl;
            return 0;
        }
    }
    while(1)
    {
        sleep(1);
        cout<<"i am main thread"<<endl;
    }
    return 0;
}
