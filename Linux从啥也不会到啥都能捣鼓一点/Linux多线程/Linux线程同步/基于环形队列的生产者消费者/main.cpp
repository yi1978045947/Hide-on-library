#include"RingQueue.h"
using namespace std;


void* Consumer(void* arg)
{
    RingQueue *bq=(RingQueue*)arg;
    int data;
    while(1)
    {
        bq->Get(data);
        cout<<"i am:"<<pthread_self()<<" i consumer:"<<data<<endl;
    }
}
void* Product(void* arg)
{
    RingQueue* bq=(RingQueue*)arg;
    srand((unsigned int)time(NULL));
    while(1)
    {
        int data=rand()%100;
        bq->Put(data);
        cout<<"i am:"<<pthread_self()<<" i product:"<<data<<endl;
        sleep(1);
    }
}
int main()
{
    RingQueue* pq=new RingQueue();
    pthread_t c;
    pthread_t p;
    pthread_create(&c,NULL,Consumer,(void*)pq);
    pthread_create(&p,NULL,Product,(void*)pq);

    pthread_join(c,NULL);
    pthread_join(p,NULL);
    return 0;
}
