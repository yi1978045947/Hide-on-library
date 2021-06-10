#include<stdio.h>
#include<unistd.h>
int main()
{
    fork();
    sleep(1);
    printf("hello:pid:%d,ppid:%d",getpid(),getppid());
    printf("\n");
    return 0;
}
