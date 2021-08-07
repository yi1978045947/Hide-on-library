#pragma once 

#include<iostream>
#include<unistd.h>
#include<vector>
#include<semaphore.h>

#include<stdlib.h>
#define NUM 10

class RingQueue
{
    private:
        std::vector<int> v;
        int _cap;           //容量
        sem_t sem_blank;   //生产者
        sem_t sem_data;        //消费者
        
        int c_index;      //消费者索引
        int p_index;      //生产者索引

    public:
        RingQueue(int cap=NUM)
            :_cap(cap)
            ,v(cap)
        {
            sem_init(&sem_blank,0,cap);
            sem_init(&sem_data,0,0);
            c_index=0;
            p_index=0;
        }
        ~RingQueue()
        {
            sem_destroy(&sem_blank);
            sem_destroy(&sem_data);
        }

        void Get(int& out)
        {
            sem_wait(&sem_data);
            //消费
            out=v[c_index];
            c_index++;
            c_index=c_index%NUM; //防止越界，构成环形队列
            sem_post(&sem_blank);
        }
        void Put(const int& in)
        {
            sem_wait(&sem_blank);
            //生产
            v[p_index]=in;
            p_index++;
            p_index=p_index%NUM;
            sem_post(&sem_data);
        }
};
