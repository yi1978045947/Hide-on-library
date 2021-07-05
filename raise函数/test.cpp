#include<iostream>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
void handler(int signo)
{
    std::cout<<"catch a signal:"<<signo<<std::endl;
}
int main(int argc,char* argv[])
{
    signal(2,handler);//捕捉信号
    while(1)
    {
        sleep(1);
        raise(2);
    }
    return 0;
}
