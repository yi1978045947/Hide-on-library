#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
    close(1);
    int fd=open("myfile",O_WRONLY|O_CREAT,0644);
    if(fd<0)
    {
        std::cout<<"文件打开失败!"<<std::endl;
        exit(1);
    }
    std::cout<<"fd:"<<fd<<std::endl;
    close(fd);
    return 0;
}
