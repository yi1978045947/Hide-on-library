#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
int main()
{
    int fd=open("myfile.txt",O_RDONLY);
    if(fd<0)
    {
        printf("文件打开失败!\n");
        exit(1);
    }
    char* arr="hello bit!";
    char buff[100];
    read(fd,buff,strlen(arr)-1);
    printf("%s\n",buff);
    close(fd);
    return 0;
}
