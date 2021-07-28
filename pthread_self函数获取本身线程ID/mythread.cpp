#include<iostream>
#include<pthread.h>
using namespace std;
#include<sys/types.h>
#include<unistd.h>

void* thread_run(void* arg)
{
    while(1)
    {
        cout<<"i am:"<<(char*)arg<<"pid:"<<getpid()<<" "<<"my thread id is:"<<pthread_self()<<endl;
        sleep(1);
    }
}
int main()
{
    pthread_t tid;
    int ret=pthread_create(&tid,NULL,thread_run,(void*)"thread 1");
    if(ret!=0)
    {
        return -1;
    }
    while(1)
    {
        cout<<"i am main thread id:"<<pthread_self()<<" "<<"new thread:"<<tid<<" "<<"pid:"<<getpid()<<endl;
        sleep(2);
    }
    return 0;
}
