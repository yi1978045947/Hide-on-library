#include<iostream>
#include<unistd.h>
int main()
{
    std::cout<<"run begin"<<std::endl;
    extern char** environ;
    //execle("/usr/bin/pwd","/usr/bin/pwd",NULL,NULL);
    execle("/usr/bin/pwd","/usr/bin/pwd",NULL,environ);
    std::cout<<"run after"<<std::endl;
    return 0;
}
