#include<stdio.h>
#include<unistd.h>
int main()
{
    pid_t pid=fork();
    if(pid<0)
    {
        printf("fork error!\n");
    }
    else if(pid==0)
    {
        printf("i am child:pid=%d,ppid=%d\n",getpid(),getppid());
        //子进程
    }
    else 
    {
        while(1)
        {
            printf("i am father:pid=%d,ppid=%d\n",getpid(),getppid());
            sleep(1);
        }
        //父进程
    }
    return 0;
}
