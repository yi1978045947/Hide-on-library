#include<stdio.h>
#include<unistd.h>
int main()
{
    fork();
    printf("hello:pid:%d,ppid:%d",getpid(),getppid());
    printf("\n");
    return 0;
}
