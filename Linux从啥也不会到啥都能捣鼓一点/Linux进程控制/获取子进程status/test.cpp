#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
    pid_t pid=fork();
    if(pid<0)
    {
        std::cout<<"fork error!"<<std::endl;
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
    else 
    {
        //father
        std::cout<<"father wait before"<<std::endl;
        int st=0;
        pid_t ret=waitpid(pid,&st,0);
        if(ret>0)
        {
            std::cout<<"wait success!"<<std::endl;
            std::cout<<"st="<<st<<std::endl;
            std::cout<<"child exit signal="<<(st&0x7f)<<std::endl;
            std::cout<<"child exit code="<<((st>>8)&0xff)<<std::endl;
        }
        if((st&0x7F))
        {
            std::cout<<"child run error!"<<std::endl;
        }
        else 
        {
            int code=((st>>8)&0xff);
            if(code)
            {
                std::cout<<"child run success,but result is not right:code="<<code<<std::endl;
            }
            else 
            {
                std::cout<<"child run success,and resunlt is right:code="<<code<<std::endl;
            }
        }
    }
    std::cout<<"wait after!"<<std::endl;
    return 0;
}
