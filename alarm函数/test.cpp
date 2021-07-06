#include<iostream>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
int count=0;
void handler(int signo)
{
    std::cout<<"count:"<<count<<std::endl;
    exit(1);
}
int main(int argc,char* argv[])
{
    signal(14,handler);
    alarm(1);
    while(1)
    {
        count++;
    }
    return 0;
}
