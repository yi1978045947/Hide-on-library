#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

int main()
{
    int SockFd=socket(AF_INET,SOCK_DGRAM,0);
    if(SockFd<0)
    {
        cout<<"套接字创建失败!"<<endl;
    }
    cout<<"SockFd:"<<SockFd<<endl;

    struct sockaddr_in addr; 

    addr.sin_port=htons(20000);
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=inet_addr("172.16.0.9");
    int ret=bind(SockFd,(struct sockaddr*)&addr,sizeof(addr));
    if(ret<0)
    {
        cout<<"绑定失败!"<<endl;
        return 0;
    }
    while(1)
    {
        char buf[1024]={0};
        struct sockaddr_in peer_addr;
        socklen_t len=sizeof(peer_addr);
        ssize_t rece_size=recvfrom(SockFd,buf,sizeof(buf)-1,0,(struct sockaddr*)&peer_addr,&len);
        if(rece_size<0)
        {
            continue;
        }
        cout<<"recv msg:"<<buf<<" from "<<inet_ntoa(peer_addr.sin_addr)<<" "<<ntohs(peer_addr.sin_port)<<endl;

        memset(buf,'\0',sizeof(buf));
        sprintf(buf,"welcome client %s:%d\n",inet_ntoa(peer_addr.sin_addr),ntohs(peer_addr.sin_port));
        sendto(SockFd,buf,strlen(buf),0,(struct sockaddr*)&peer_addr,sizeof(peer_addr));
    }
    close(SockFd);
    return 0;
}
