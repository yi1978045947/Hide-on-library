#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
using namespace std;

int a=10;
void* thread_run(void* arg)
{
    while(1)
    {
        cout<<(char*)arg<<pthread_self()<<" pid:"<<getpid()<<endl;
        cout<<(char*)arg<<" global-variable:"<<a<<" &a:"<<&a<<endl;
        sleep(1);
    }
    return (void*)10;
}
int main()
{
    pthread_t tid;
    pthread_t tid1;
    pthread_create(&tid,NULL,thread_run,(void*)"thread 1");
    pthread_create(&tid1,NULL,thread_run,(void*)"thread 1");
    cout<<"main:"<<pthread_self()<<" pid:"<<getpid()<<endl;
    
    cout<<"before:"<<main<<" global-variable:"<<a<<" %p:"<<&a<<endl;
    sleep(5);
    a=100;
    cout<<"after:"<<main<<" globa-variable:"<<a<<" %p:"<<&a<<endl;

    pthread_cancel(tid);
    void* tmp=NULL;
   pthread_join(tid,&tmp);
   cout<<"thread qiut code:"<<(long long )tmp<<endl;
    return 100;
}
