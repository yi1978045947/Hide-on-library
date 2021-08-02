#include<stdio.h>
#include<unistd.h>
int main()
{
    int ret=fork();
    if(ret<0)
    {
        printf("fork error!\n");
    }
    else if(ret==0)
    {
        printf("i am child:%d ,父进程号:%d,ret=%d\n",getpid(),getppid(),ret);
    }
    else
    {
        printf("i am parent:%d,父进程号:%d, ret=%d\n",getpid(),getppid(),ret);
    }
    return 0;
}
