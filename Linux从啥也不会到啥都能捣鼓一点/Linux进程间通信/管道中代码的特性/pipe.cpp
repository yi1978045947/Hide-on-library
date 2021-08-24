#include<iostream>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<stdlib.h>
int main()
{
    int pipefd[2]={0};
    pipe(pipefd);
    pid_t pid=fork();
    if(pid<0)
    {
        std::cout<<"fork error!"<<std::endl;
    }
    else if(pid==0)
    {
        //child write fd[1]
        close(pipefd[0]);
        const char* str="I am child\n";
        int count=0;
        while(1)
        {
            write(pipefd[1],str,strlen(str));
            std::cout<<"child:"<<(count++)<<std::endl;
            if(count==13)
            {
                close(pipefd[1]);
                break;
            }
        }
        exit(1);
    }
    else 
    {
        //father read fd[0]
        close(pipefd[1]);
       // close(pipefd[0]);
        char buffer[64];
        int count=0;
        while(1)
        {
           ssize_t s=read(pipefd[0],buffer,sizeof(buffer)-1); 
           if(s<0)
           {
               std::cout<<"读取失败!"<<std::endl;
           }
           else if(s>0)
           {
               buffer[s]=0;
               std::cout<<"father get message:"<<buffer<<std::endl;
               sleep(1);
           }
           if((count++)==2)
           {
               close(pipefd[0]);
               break;
           }
           int status=0;
           waitpid(pid,&status,0);
           std::cout<<"child exit signal:"<<(status&0x7F)<<std::endl;
        }
    }
    return 0;
}
