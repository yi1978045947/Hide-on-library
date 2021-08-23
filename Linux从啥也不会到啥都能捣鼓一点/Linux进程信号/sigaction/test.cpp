#include<iostream>

#include<signal.h>
#include<unistd.h>
using namespace std;
void handler(int sig)
{
    cout<<"catch a sig"<<sig<<endl;
}
int main()
{

    struct sigaction act,oact;
    act.sa_handler=handler;
    act.sa_flags=0;
    sigemptyset(&act.sa_mask);
    sigaction(2,&act,&oact);

    while(1)
    {
        ;
    }
    return 0;
}
