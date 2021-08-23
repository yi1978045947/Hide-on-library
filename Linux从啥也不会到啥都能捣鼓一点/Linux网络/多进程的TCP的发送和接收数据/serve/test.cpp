#include<iostream>
#include<errno.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/wait.h>
#include<stdio.h>
using namespace std;

void signalcallback(int signo)
{
    //当前的wait是进程等待的阻塞接口， 但是应用的场景一定是子进程退出之后，
    //父进程收到了SIGCHLD信号之后， 才会回调sigcallback函数， 才会调用wait
    cout<<"recv signo:"<<signo<<endl;
    wait(NULL);
}
int main()
{
    signal(SIGCHLD,signalcallback);
    int listen_sock=socket(AF_INET,SOCK_STREAM,0);
    if(listen_sock<0)
    {
        perror("socket");
        return 0;
    }

    struct sockaddr_in addr;

    addr.sin_family=AF_INET;
    addr.sin_port=htons(20000);
    addr.sin_addr.s_addr=inet_addr("172.16.0.9");

    int ret=bind(listen_sock,(struct sockaddr*)&addr,sizeof(addr));
    if(ret<0)
    {
        perror("bind");
        return 0;
    }


    ret=listen(listen_sock,5);
    if(ret<0)
    {
        perror("listen");
        return 0;
    }

    while(1)
    {
        int new_sock=accept(listen_sock,NULL,NULL); //客服端的地址和端口号，这么传NULL,不关心客服端的端口号
        if(new_sock<0)
        {
            continue;
        }

        //创建子进程
        int pid=fork();
        if(pid<0)
        {
            //创建子进程失败,但是接收新链接成功
            close(new_sock);
            continue;
        }
        else if(pid==0)
        {
            //child
            close(listen_sock);

            while(1)
            {
                //recv  and send

                char buf[1024]={0};

                ssize_t recv_size=recv(new_sock,buf,sizeof(buf)-1,0);
                if(recv_size<0)
                {
                    perror("recv");
                    continue;
                }
                else if(recv_size==0)
                {
                    cout<<"peer shutdown!"<<endl;
                    close(new_sock);

                    //子进程故障
                    //exit(1);

                }

                cout<<"client say:"<<buf<<endl;

                memset(buf,'\0',sizeof(buf));
                strcpy(buf,"i am serve");
                send(new_sock,buf,strlen(buf),0);
            }
        }
        else 
        {
            close(new_sock);
        }
    }
    return 0;
}
