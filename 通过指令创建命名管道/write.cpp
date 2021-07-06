#include<iostream>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
int main()
{
    int fd=open("./pipe",O_WRONLY);
    if(fd<0)
    {
        std::cout<<"打开管道文件失败!"<<std::endl;
        return 1;
    }
    char str[]="bit education!";
    write(fd,str,sizeof(str)-1);
    return 0;
}

