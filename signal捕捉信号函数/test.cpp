#include<iostream>
#include<signal.h>
#include<unistd.h>
using namespace std;
void hander(int sig)
{
    cout<<"catch a sig"<<sig<<endl;
}
int main()
{
    signal(2,hander);
    while(1)
    {
        sleep(1);
    }
    return 0;
}
