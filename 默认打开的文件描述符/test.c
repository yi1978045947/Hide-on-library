#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    char buff[100];
    int fd=read(0,buff,sizeof(buff));
    write(1,buff,strlen(buff)-1);
    write(2,buff,strlen(buff)-1);
    return 0;
}
