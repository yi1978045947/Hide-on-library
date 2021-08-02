#include<iostream>
#include<unistd.h>
#include<pthread.h>
using namespace std;

void* MyThreadStrat(void* arg)
{
    int* i=(int*)arg;
    while(1)
    {
        cout<<"MyThreadStrat:"<<*i<<endl;
        sleep(1);
    }
    return NULL;
}
int main()
{
    pthread_t tid;
    int i=1;
        int ret=pthread_create(&tid,NULL,MyThreadStrat,(void*)&i);
        if(ret!=0)
        {
            cout<<"线程创建失败!"<<endl;
            return 0;
        }
    while(1)
    {
        sleep(1);
        cout<<"i am main thread"<<endl;
    }
    return 0;
}
