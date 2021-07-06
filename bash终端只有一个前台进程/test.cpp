#include<iostream>
#include<unistd.h>
int main()
{
    while(1)
    {
        std::cout<<"i am process,i am waiting signal!"<<std::endl;
        sleep(1);
    }
    return 0;
}
