#include<iostream>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
int main()
{
    close(0);
   // close(2);
    int fd=open("myfile",O_RDONLY|O_CREAT,0664);
    if(fd<0)
    {
        std::cout<<"文件打开失败!"<<std::endl;
        return 1;
    }
    std::cout<<"fd:"<<fd<<std::endl;
    close(fd);
    return 0;
}
