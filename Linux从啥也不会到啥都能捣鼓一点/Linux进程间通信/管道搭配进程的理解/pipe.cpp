#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main()
{
   int fd[2];
   int ret=pipe(fd); 
   if(-1==ret)
   {
       std::cout<<"创建失败!"<<std::endl;
   }
   std::cout<<"fd[0]:"<<fd[0]<<std::endl<<"fd[1]:"<<fd[1]<<std::endl;
   pid_t pid=fork();
   if(pid<0)
   {
       std::cout<<"fork error!"<<std::endl;
       exit(1);
   }
   else if(pid==0)
   {
       //child read
       close(fd[1]);
       char buf[1024];
       read(fd[0],buf,sizeof(buf)-1);
       std::cout<<"one child read:"<<buf<<std::endl;
       read(fd[0],buf,sizeof(buf)-1);
       std::cout<<"two child read:"<<buf<<std::endl;
   }
   else 
   {
       //father write
       sleep(2);
       close(fd[0]);
       const char* str="bit education!";
       write(fd[1],str,strlen(str));
   }
   while(1)
   {
      ;
   }
    return 0;
}
