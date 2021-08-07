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
    return 0;
}
