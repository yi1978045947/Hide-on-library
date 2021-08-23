#include<unistd.h>
#include<iostream>
#include<stdlib.h>
int main()
{
    pid_t pid=fork();
    if(pid<0)
    {
        std::cout<<"fork error"<<std::endl;
    }
    else if(pid==0)
    {
        while(1)
        {
            sleep(1);
            std::cout<<"I am child"<<std::endl;
            break;
        }
        exit(0);
    }
    else 
    {
        while(1)
        {
            sleep(1);
            std::cout<<"I am father"<<std::endl;
            break;
        }
    }
    std::cout<<"haha"<<std::endl;
    return 0;
}
