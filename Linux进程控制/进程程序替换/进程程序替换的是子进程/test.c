#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    pid_t pid=fork();
    if(pid<0)
    {
        printf("fork error!\n");
        exit(1);
    }
    else if(pid==0)
    {
        //child
        sleep(2);
        execl("/usr/bin/ls","/usr/bin/ls","-a","-l",NULL);
    }
    pid_t ret=waitpid(pid,NULL,0);
    if(ret>0)
    {
        printf("cmd run done!\n");
    }
    return 0;
}
