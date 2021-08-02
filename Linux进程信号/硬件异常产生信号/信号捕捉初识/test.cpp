#include<iostream>
#include<signal.h>
void handler(int signo)
{
    std::cout<<"catch a signal:"<<signo<<std::endl;
}
int main()
{
    signal(2,handler);//捕捉2号信号
    while(1);
    return 0;
}
