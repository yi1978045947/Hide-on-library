#include<stdio.h>
#define FIFO_FILE "./fifo"
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    int fd=open(FIFO_FILE,O_WRONLY);
    if(fd<0)
    {
        printf("文件打开失败!\n");
        return 1;
    }
    else if (fd>=0)
    {
        char buf[64];
        while(1)
        {
            printf("please Enter message# ");
            fflush(stdout);
            ssize_t s =read(0,buf,sizeof(buf)-1);
            if(s>0)
            {
                buf[s]=0;
                write(fd,buf,s);
            }
        }
    }
    return 0;
}
