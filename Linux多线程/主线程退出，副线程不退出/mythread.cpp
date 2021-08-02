#include<iostream>
#include<pthread.h>
using namespace std;
#include<unistd.h>

void* thread_run(void* arg)
{
    while(1)
    {
        cout<<"i am "<<(char*)arg<<endl;
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
    return 0;
}
