#include<unistd.h>
#include<string.h>
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
    int sockfd=socket(AF_INET,SOCK_STREAM,0);

    if(sockfd<0)
    {
        perror("socket");
        return 0;
    }
    cout<<sockfd<<endl;

    struct sockaddr_in addr;

    addr.sin_family=AF_INET;
    addr.sin_port=htons(20000);
    addr.sin_addr.s_addr=inet_addr("1.14.165.138");
    // addr.sin_addr.s_addr=inet_addr("0.0.0.0");这个地址包含所有本地网卡地址
    int ret=connect(sockfd,(struct sockaddr*)&addr,sizeof(addr));

    if(ret<0)
    {
        perror("connect");
        return 0;
    }

    if(ret<0)
    {
        perror("connect");
        return 0;
    }

    
    while(1)
    {
        char buf[1024]="i am client!";

        send(sockfd,buf,strlen(buf),0);
        memset(buf,'\0',sizeof(buf));
        //接收
        ssize_t recv_size=recv(sockfd,buf,sizeof(buf)-1,0);
        if(recv_size<0)
        {
            perror("recv");
            return 0;
        }
        else if(recv_size==0)
        {
            cout<<"close peer connect"<<endl;
            close(sockfd);
            continue;
        }

        cout<<"buf:"<<buf<<endl;




        sleep(1);
    }

    return 0;
}
