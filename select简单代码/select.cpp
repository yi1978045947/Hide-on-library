#include<iostream>
#include<sys/select.h>
#include<unistd.h>
#include<stdio.h>
using namespace std;
int main()
{
    fd_set readfds;

    FD_ZERO(&readfds);
    FD_SET(0,&readfds);

    while(1)
    {
       int ret=select(1,&readfds,NULL,NULL,NULL);

       if(ret<0)
       {
           perror("select");
           return 0;
       }

       char buf[1024]={0};
       read(0,buf,sizeof(buf)-1);

       cout<<buf<<endl;
    }
    return 0;
}
