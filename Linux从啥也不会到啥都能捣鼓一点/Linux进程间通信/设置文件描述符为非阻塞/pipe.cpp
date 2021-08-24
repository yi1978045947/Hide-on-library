#include<iostream>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    int fd[2];
    int ret=pipe(fd);
    if(ret==-1)
    {
        std::cout<<"管道文件创建失败!"<<std::endl;
    }
    int flag=fcntl(fd[1],F_GETFL);
    std::cout<<"fd[1]:"<<flag<<std::endl;

    flag=fcntl(fd[0],F_GETFL);
    std::cout<<"fd[0]:"<<flag<<std::endl;

    fcntl(fd[0],F_SETFL,flag|O_NONBLOCK);
    flag=fcntl(fd[0],F_GETFL);
    std::cout<<"2fd[0]:"<<flag<<std::endl;

    fcntl(fd[1],F_SETFL,flag|O_NONBLOCK);
    flag=fcntl(fd[1],F_GETFL);
    std::cout<<"2fd[1]:"<<flag<<std::endl;
    return 0;
}
