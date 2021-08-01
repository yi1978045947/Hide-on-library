#include<iostream>
#include<math.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<queue>

#define NUM 5
class Task 
{
    private:
        int _b;
    public:
        Task()
        {
            
        }
        Task(int b)
            :_b(b)
        {
            
        }
        ~Task()
        {

        }
        void Run()
        {
            std::cout<<"i am:"<<pthread_self()<<" Task run.... :base# "<<_b<<" pow is "<<pow(_b,2)<<std::endl;
        }
};
class ThreadPool
{
    private:
        std::queue<Task*> q;
        int _max_num;        //线程总数

        pthread_mutex_t lock;
        pthread_cond_t cond;   //只能让消费者操作

    private:
        void LockQueue()
        {
            pthread_mutex_lock(&lock);
        }
        void UnLockQueue()
        {
            pthread_mutex_unlock(&lock);
        }

        bool IsEmpty()
        {
            return q.size()==0;
        }
        bool IsFull()
        {
            return q.size()==_max_num;
        }

        void ThreadWait()
        {
            pthread_cond_wait(&cond,&lock);   //等待条件变量满足
        }

        void ThreadWakeUp()
        {
            pthread_cond_signal(&cond);
        }
    public:
        ThreadPool(int max_num=NUM )
            :_max_num(max_num)
        {

        }

        static void* Routine(void* arg)
        {
            while(1)
            {
                ThreadPool *tp=(ThreadPool*)arg;
                while(tp->IsEmpty())
                {
                    tp->LockQueue();  //静态成员方法不能访问非静态成员方法,所以传(void*)this传过去
                    tp->ThreadWait();  //为空挂起等待
                }
                    
                Task t;
                tp->Get(t);   //获取这个任务
                tp->UnLockQueue();
                t.Run(); //拿到这个任务运行
            }
        }

        void ThreadPoolInit()
        {
            pthread_mutex_init(&lock,NULL);
            pthread_cond_init(&cond,NULL);

            int i=0;
            pthread_t t;
            for(i=0;i<_max_num;i++)
            {
                pthread_create(&t,NULL,Routine,(void*)this);
            }
        }
        ~ThreadPool()
        {
            pthread_mutex_destroy(&lock);
            pthread_cond_destroy(&cond);
        }

        //server  放数据
        void Put(Task& in)
        {
            LockQueue();

            q.push(&in);

            UnLockQueue();
            
            ThreadWakeUp();
        }
        //ThreadPool 取数据
        void Get(Task& out)
        {
            //线程池里面直接拿不用加锁
            Task* t=q.front();
            q.pop();
            out=*t;
        }
};

