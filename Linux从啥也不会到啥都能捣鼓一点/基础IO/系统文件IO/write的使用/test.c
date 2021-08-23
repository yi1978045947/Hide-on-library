#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{
   int fd=open("myfile",O_WRONLY|O_CREAT,0644);
   if(fd<0)
   {
       printf("文件打开失败!\n");
       exit(1);
   }
   char* arr="bit education!";
   write(fd,arr,strlen(arr)-1);
   close(fd);
   return 0;
}
