#include<iostream>
#include<unistd.h>
#include<stdlib.h>
int g_val=10;

int main()
{
    pid_t pid=fork();
    if(pid<0)
    {
        std::cout<<"fork error"<<std::endl;
    }
    else if(pid==0)
    {
        g_val=100;
        std::cout<<"child pid="<<getpid()<<std::cout<<" g_val="<<g_val<<std::cout<<" 地址"<<&g_val<<std::endl;
    }
    else
    {
        sleep(3);
        std::cout<<"parent pid="<<getpid()<<std::cout<<" g_val="<<g_val<<std::cout<<" 地址"<<&g_val<<std::endl;
    }
    sleep(1);
    return 0;
}
