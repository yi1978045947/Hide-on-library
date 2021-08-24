#include<iostream>
#include<unistd.h>
int fun()
{
    int i=2/0;
}
int main()
{
    std::cout<<"Hello Linux"<<std::endl;
    sleep(1);
    int ret=fun();
    return 0;
}
