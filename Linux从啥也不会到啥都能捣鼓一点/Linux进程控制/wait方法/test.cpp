#include<iostream>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    pid_t pid=fork();
    if(pid<0)
    {
        std::cout<<"fork error"<<std::endl;
    }
    else if(pid==0)
    {
        int count=0;
        while(1)
        {
            sleep(1);
            std::cout<<"i am child"<<std::endl;
            if(count==2)
            {
                break;
            }
            count++;
        }
        exit(0);
    }
    else 
    {
        int count=0;
        while(1)
        {
            sleep(1);
            std::cout<<"i am father"<<std::endl;
            while(count==5)
            {
               wait(NULL);
            }
            count++;
        }
        exit(0);
       /* std::cout<<"father before...."<<std::endl;
        wait(NULL);
        std::cout<<"father after..."<<std::endl;*/
    }
    return 0;
}
