#include<iostream>
#include<stdlib.h>
int main()
{
    char* env=getenv("MYENV");
    if(env)
    {
        std::cout<<env<<std::endl;
    }
    return 0;
}
