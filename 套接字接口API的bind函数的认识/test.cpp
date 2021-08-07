#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
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
        sleep(1);
    }
    return 0;
}
