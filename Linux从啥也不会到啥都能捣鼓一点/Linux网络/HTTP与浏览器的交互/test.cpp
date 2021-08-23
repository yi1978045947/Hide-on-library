#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<errno.h>
#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sstream>
using namespace std;

int main()
{
    int sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0)
    {
        perror("socket");
        return 0;
    }

    struct sockaddr_in addr;
    addr.sin_port=htons(20000);
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=inet_addr("172.16.0.9");

    int ret=bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
    if(ret<0)
    {
        perror("bind");
        return 0;
    }

    ret=listen(sockfd,1);
    if(ret<0)
    {
        perror("listen");
        return 0;
    }

    struct sockaddr_in cli_addr; //客户端的协议栈
    socklen_t cli_addrlen=sizeof(cli_addr);
    int newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&cli_addrlen);
    if(newsockfd<0)
    {
        perror("accept");
        return 0;
    }
    cout<<"accept new connect form client:"<<inet_ntoa(cli_addr.sin_addr)<<" "<<ntohs(cli_addr.sin_port);

    while(1)
    {
        char buf[1024]={0};
        ssize_t recv_size=recv(newsockfd,buf,sizeof(buf)-1,0);
        if(recv_size<0)
        {
            perror("recv");
            continue;
        }
        else if(recv_size==0)
        {
            cout<<"peer close connect!"<<endl;
            close(newsockfd);
            return 0;
        }

        cout<<"buf:"<<buf<<endl;
        memset(buf,'\0',sizeof(buf));

        string body="<html><h1>hello world</h1></html>";
        stringstream ss;
       // ss<<"HTTP/1.1 200 OK\r\n";
       // ss<<"Content-Type: text/html\r\n";
       // ss<<"Content-length: "<<body.size()<<"\r\n";
     
        ss<<"HTTP/1.1 302 Found\r\n";
        ss<<"Location: https://www.baidu.com/\r\n";
        ss<<"\r\n";

        send(newsockfd,ss.str().c_str(),ss.str().size(),0);
        send(newsockfd,body.c_str(),body.size(),0);

    }
    close(sockfd);
    return 0;
}
