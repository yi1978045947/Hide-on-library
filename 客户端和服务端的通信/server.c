#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>

#define FIFO_FILE "./fifo"
int main()
{
    umask(0); 
    if(mkfifo(FIFO_FILE,0666)==-1)
    {
        printf("创建管道失败!\n");
        return 1;
    }//创建管道


    int fd=open(FIFO_FILE,O_RDONLY);// 
    if(fd<0)
    {
        printf("打开管道失败!\n");
        return 1;
    }
    else if(fd >=0)
    {
        char buf[64];
        while(1)
        {
            printf("please wait!\n");
            ssize_t s=read(fd,buf,sizeof(buf)-1);//减一是预留\0位置
            if(s>0)
            {
                buf[s]=0;
                printf("client# %s",buf);
            }
            else if(s==0)
            {
                printf("cilent exit!\n");
                break;
            }
            else 
            {
                printf("文件读取失败!\n");
                break;
            }
        }
    }
    return 0;
}
