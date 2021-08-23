#include<iostream>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
   int fd=open("myfile",O_RDONLY|O_CREAT);
   if(fd<0)
   {
       std::cout<<"文件打开失败!"<<std::endl;
   }
   std::cout<<fd<<std::endl;
   close(fd);
   return 0;
}
