#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/syscall.h>
void* MyThreadStart(void* arg)//线程入口函数
{
    while (1)
    {
        printf("ppid=%d,i am MyThreadStart\n",syscall(SYS_gettid));//通过syscall获取线程ID
        sleep(1);

    }

}
int main()
{
    pthread_t thread;
    int ret = pthread_create(&thread, NULL, MyThreadStart, NULL);
    if (ret < 0)
    {
        perror("pthread_creat");
        return 0;

    }

    while (1)
    {
        printf("ppid=%d,i am main thread\n",syscall(SYS_gettid));
        sleep(1);

    }
    return 0;

}

