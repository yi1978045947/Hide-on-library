#include<iostream>
#include<unistd.h>
int main()
{
    int fd[2];
    int ret=pipe(fd);
    if(ret==-1)
    {
        std::cout<<"管道创建失败!"<<std::endl;
    }
    int count=0;
    while(1)
    {
        write(fd[1],"a",1);
        std::cout<<"count="<<++count<<std::endl;
    }
    return 0;
}
