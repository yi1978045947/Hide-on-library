#include<iostream>
#include<stdio.h>
#include<poll.h>
#include<unistd.h>

using namespace std;
int main()
{
     struct pollfd pf;

     pf.fd=0;
     pf.events=POLLIN;

     while(1)
     {
         int ret=poll(&pf,1,-1);
         if(ret<0)
         {
             perror("poll");
         }
         else if(ret==0)
         {
             cout<<"TimeOut!"<<endl;
             sleep(1);
             continue;
         }
         char buf[1024]={0};
         read(0,buf,sizeof(buf)-1);
         cout<<buf<<endl;

     }
     return 0;
}
