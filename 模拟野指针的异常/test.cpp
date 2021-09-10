#include<iostream>
#include<signal.h>
#include<unistd.h>
void handler(int signo)
{
    std::cout<<"catch a signal:"<<signo<<std::endl;
}
int main()
{
    signal(11,handler);//捕捉2号信号
    sleep(1);
    int* p=NULL;
    *p=100;
    while(1);
    sleep(1);
    return 0;
}
