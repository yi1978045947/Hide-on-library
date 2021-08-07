#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
using namespace std;

void* thread_run(void* arg)
{
  //  while(1)
   // {
        cout<<(char*)arg<<pthread_self()<<" pid:"<<getpid()<<endl;
        sleep(1);
        return (void*)10;
   // }
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

   // while(1)
   // {
        cout<<"i am main:"<<pthread_self()<<" pid:"<<getpid()<<endl;
        sleep(2);
   // }
   void* tmp=NULL;
   pthread_join(tid,&tmp);
   cout<<"thread eixt code:"<<(long long) tmp<<endl;
    return 0;
}
