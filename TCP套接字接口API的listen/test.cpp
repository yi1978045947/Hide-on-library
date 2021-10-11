#include<unistd.h>
#include<iostream>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<error.h>
#include<stdio.h>
using namespace std;

int main()
{
    int listen_sock=socket(AF_INET,SOCK_STREAM,0);

    if(listen_sock<0)
    {
        perror("socket");
        return 0;
    }
    cout<<listen_sock<<endl;

    struct sockaddr_in addr;

    addr.sin_family=AF_INET;
    addr.sin_port=htons(20000);
    addr.sin_addr.s_addr=inet_addr("172.16.0.9");
    // addr.sin_addr.s_addr=inet_addr("0.0.0.0");这个地址包含所有本地网卡地址
    int ret=bind(listen_sock,(struct sockaddr*)&addr,sizeof(addr));

    if(ret<0)
    {
        perror("bind");
        return 0;
    }

    ret=listen(listen_sock,1);
    if(ret<0)
    {
        perror("listen");
        return 0;
    }

    while(1)
    {
        sleep(1);
    }

    return 0;
}
