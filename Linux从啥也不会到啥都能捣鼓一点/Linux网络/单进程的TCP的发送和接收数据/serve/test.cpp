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

    struct sockaddr_in cli_addr;
    socklen_t cli_addrlen=sizeof(cli_addr);
    int newsockfd=accept(listen_sock,(struct sockaddr*)&cli_addr,&cli_addrlen);
    if(newsockfd<0)
    {
        perror("accept");
        return 0;
    }
    
    cout<<"i accept new connect form client:"<<inet_ntoa(cli_addr.sin_addr)<<" :"<<ntohs(cli_addr.sin_port)<<endl;
    while(1)
    {
        char buf[1024]={0};

        ssize_t recv_size=recv(newsockfd,buf,sizeof(buf)-1,0);
        if(recv_size<0)
        {
            perror("recv");
            return 0;
        }
        else if(recv_size==0)
        {
            cout<<"close peer connect"<<endl;
    //      close(newsockfd);
            continue;
        }

        cout<<"buf:"<<buf<<endl;

        memset(buf,'\0',sizeof(buf));
        strcpy(buf,"i am serve!!!");
        send(newsockfd,buf,strlen(buf),0);



        sleep(1);
    }

    return 0;
}
