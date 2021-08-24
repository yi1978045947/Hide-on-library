#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>

using namespace std;
int main()
{
    int SockFd=socket(AF_INET,SOCK_STREAM,0);
    if(SockFd<0)
    {
        cout<<"套接字创建失败!"<<endl;
    }
    cout<<"SockFd:"<<SockFd<<endl;
    while(1)
    {
        sleep(1);
    }
    return 0;
}
