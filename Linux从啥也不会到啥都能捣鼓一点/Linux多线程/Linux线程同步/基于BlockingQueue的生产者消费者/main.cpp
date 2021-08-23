#include"BlockQueue.cpp"
using namespace std;
#include<stdlib.h>

pthread_mutex_t p_lock;
pthread_mutex_t c_lock;
void* Product_Run(void* arg)
{
    BlockQueue* bq=(BlockQueue*)arg;

    srand((unsigned int)time(NULL));
    while(true)
    {
        pthread_mutex_lock(&p_lock);
       // int data=rand()%10+1;
       int x=rand()%10+1;
       int y=rand()%100+1;
       Task t(x,y);
        bq->put(t);
        pthread_mutex_unlock(&p_lock);
        cout<<"product data is:"<<t.run()<<endl;
    }
}
void* Consumer_Run(void* arg)
{
    BlockQueue* bq=(BlockQueue*)arg;
    while(true)
    {
        pthread_mutex_lock(&c_lock);
       // int n=0;
        Task t;
        bq->Get(t);
        pthread_mutex_unlock(&c_lock);
        cout<<"consumer  is:"<<t._x<<"+"<<t._y<<"="<<t.run()<<endl;
        sleep(1);
    }
}
int main()
{
    BlockQueue* bq=new BlockQueue(10);
    pthread_t c,p;

    pthread_create(&c,NULL,Product_Run,(void*)bq);

    pthread_create(&p,NULL,Consumer_Run,(void*)bq);

    pthread_join(c,NULL);
    pthread_join(p,NULL);

    delete bq;
    return 0;
}
