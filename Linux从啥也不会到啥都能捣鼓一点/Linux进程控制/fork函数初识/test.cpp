#include<iostream>
#include<unistd.h>
int main()
{
    std::cout<<"I am a process:"<<getpid()<<std::endl;
    pid_t ret=fork();
    if(ret<0)
    {
        std::cout<<"fork error"<<std::endl;
    }
    else if(ret==0)
    {
        std::cout<<"I am child,my pid is:"<<getpid()<<" my return:"<<ret<<std::endl;
        sleep(2);
    }
    else 
    {
        std::cout<<"I am father,my pid is:"<<getpid()<<" my return is:"<<ret<<std::endl;
        sleep(2);
    }
    return 0;
}    

    
