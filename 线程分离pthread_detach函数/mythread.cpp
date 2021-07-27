#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
using namespace std;

void* thread_run(void* arg)
{
    pthread_detach(pthread_self());
    while(1)
    {
        cout<<(char*)arg<<pthread_self()<<" pid:"<<getpid()<<endl;
        sleep(1);
        break;
    }
    return (void*)10;
}
int main()
{
    pthread_t tid;
    int ret=0;
    ret= pthread_create(&tid,NULL,thread_run,(void*)"thread 1");
    if(ret!=0)
    {
        return -1;
    }   
    
    sleep(10);
    pthread_cancel(tid);
    cout<<"new thread "<<tid<<" be cancled!"<<endl;
    void* tmp=NULL;
   pthread_join(tid,&tmp);
   cout<<"thread qiut code:"<<(long long )ret<<endl;
    return 100;
}
