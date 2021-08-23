#include<iostream>
#include<unistd.h>
#include<signal.h>
using namespace std;
 volatile int quit=0;

void handler(int sig)
{

    quit=1;
    cout<<"catch a sig"<<sig<<endl;
}
int main()
{
    signal(2,handler);
    while(!quit)
    {
        sleep(1);
       cout<<"end a process"<<endl;
    }
   
    return 0;
}
