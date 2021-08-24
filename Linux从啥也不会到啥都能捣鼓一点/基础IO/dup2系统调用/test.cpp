#include<iostream>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
    int fd=open("log.txt",O_WRONLY|O_CREAT|O_APPEND,0644);
    if(fd<0)
    {
        std::cout<<"文件打开失败!"<<std::endl;
        return 1;
    }
   //close(fd);
    dup2(fd,1);
    const char* str1="hello printf\n";
    const char* str2="hello fwrite\n";
    const char* str3="hello write\n";
    write(1,str3,strlen(str3));
    printf("%s\n",str1);
    fprintf(stdout,"%s\n",str2);
    fflush(stdout);
    close(fd);
    return 0;


}
