#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
    int fd=open("./pipe",O_RDONLY);
    if(fd<0)
    {
        std::cout<<"打开管道文件失败!"<<std::endl;
        return 1;
    }
    char buf[64]={0};
    read(fd,buf,sizeof(buf));
    std::cout<<buf<<std::endl;
    return 0;
}
