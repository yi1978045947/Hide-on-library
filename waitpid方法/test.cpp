#include<iostream>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    pid_t pid=fork();
    if(pid<0)
    {
        std::cout<<"fork error!\n"<<std::endl;
    }
    else if(pid==0)
    {
        //child
        int count=0;
        while(count<5)
        {
            std::cout<<"child is running,pid="<<getpid()<<std::endl;
            sleep(1);
            count++;
        }
        exit(0);
    }
    //father
    std::cout<<"father wait before!"<<std::endl;
    pid_t ret=waitpid(pid,NULL,0);
    if(ret>0)
    {
        std::cout<<"wait success!"<<std::endl;
    }
    else 
    {
        std::cout<<"wait failed"<<std::endl;
    }
    std::cout<<"father wait after!"<<std::endl;
    return 0;
}
