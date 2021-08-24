#pragma once  //防止头文件重复包含

#include<iostream>

#include<pthread.h>
#include<unistd.h>
#include<queue>
//using namespace std;

class Task
{
    public:
        int _x;
        int _y;
    public:
        Task()
        {}
        Task(int x,int y)
            :_x(x)
             ,_y(y)
    {}
        int run()
        {
            return _x+_y;
        }
        ~Task()
        {}
};
class BlockQueue
{   
    private:
   // std::queue<int> q; //设置一个队列
    std::queue<Task> q; //设置一个队列
    int _cap; //容量
    pthread_mutex_t lock;  //设置一把互斥锁

    pthread_cond_t c_cond;  //满了的话通知消费者
    pthread_cond_t p_cond; //空的话通知生产者

    private: //封装起来
    void LockQueue() //加锁
    {
        pthread_mutex_lock(&lock);
    }
    void UnLockQueue() //解锁
    {
        pthread_mutex_unlock(&lock);
    }


    bool IsEmpty() //判断队列是否为空
    {
        return q.size()==0;
    }
    bool IsFull() //判断队列是否满了
    {
        return q.size()==_cap;
    }
    
    void ProductWait() //生产者等待
    {
        pthread_cond_wait(&p_cond,&lock);
    }
    void ConsumerWait() //消费者等待
    {
        pthread_cond_wait(&c_cond,&lock);
    }

    void WakeUpProduct() //唤醒生产者
    {
        std::cout<<"wake up Product..."<<std::endl;
        pthread_cond_signal(&p_cond);
    }
    void WakeUpConsumer() //唤醒消费者
    {
        std::cout<<"wake up Consumer..."<<std::endl;
        pthread_cond_signal(&c_cond);
    }

    public:
    BlockQueue(int cap)    //构造函数初始化
    :_cap(cap)
    {
        pthread_mutex_init(&lock,NULL);
        pthread_cond_init(&c_cond,NULL);
        pthread_cond_init(&p_cond,NULL);
    }
    ~BlockQueue()        //析构函数销毁
    {
        pthread_mutex_destroy(&lock);
        pthread_cond_destroy(&c_cond);
        pthread_cond_destroy(&p_cond);
    }
    
    void put(Task in)
    {
        //Queue是临界资源,就要加锁，而且判断是否为满，把接口封装起来
        LockQueue();
        while(IsFull())
        {
                WakeUpConsumer();
                std::cout<<"queue full,notify consume data,product stop!"<<std::endl;
                ProductWait();  //生产者线程等待
        }
        q.push(in);
        
        UnLockQueue();
    }
    void Get(Task& out)
    {
        LockQueue();
        while(IsEmpty())
        {
            WakeUpProduct();
            std::cout<<"queue empty,notify product data,consumer stop"<<std::endl;
            ConsumerWait();
        }
        out=q.front();
        q.pop();

        UnLockQueue();
    }

    //线程接口函数
    /*void* Product(void* arg)
    {

    }
    void* Consumer(void* arg)
    {

    }*/

};
