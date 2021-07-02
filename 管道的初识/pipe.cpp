#include<iostream>
#include<unistd.h>
int main()
{
   int fd[2];
   int ret=pipe(fd); 
   if(-1==ret)
   {
       std::cout<<"创建失败!"<<std::endl;
   }
   std::cout<<"fd[0]:"<<fd[0]<<std::endl<<"fd[1]:"<<fd[1]<<std::endl;
    return 0;
}
