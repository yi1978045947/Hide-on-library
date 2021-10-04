#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<sys/epoll.h>

using namespace std;
int main()
{
    int epfd=epoll_create(3);
    if(epfd<0)
    {
        perror("epoll_create");
        return 0;
    }

    struct epoll_event ee;
    ee.events=EPOLLIN;
    ee.data.fd=0;
    epoll_ctl(epfd,EPOLL_CTL_ADD,0,&ee);

    while(1)
    {
        struct epoll_event arr[2];
        int ret=epoll_wait(epfd,arr,sizeof(arr)/sizeof(arr[0]),-1);
        if(ret<0)
        {
            perror("epoll_wait");
            continue;
        }
        
        for(int i=0;i<ret;i++)
        {
            if(arr[i].events==EPOLLIN)
            {
                char buf[1024]={0};

                read(arr[i].data.fd,buf,sizeof(buf)-1);
                cout<<buf<<endl;
            }
        }
    }
    return 0;
}
