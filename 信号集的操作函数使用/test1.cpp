#include<iostream>
#include<unistd.h>
#include<signal.h>
using namespace std;

void show_pending(sigset_t* pending)
{
    for(size_t sig=1;sig<31;sig++)
    {
        if(sigismember(pending,sig))
        {
            cout<<"1";
        }
        else 
        {
            cout<<"0";
        }
    }
    cout<<endl;
}
void handler(int sig)
{
    cout<<"catch a sig:"<<sig<<endl;
}
int main()
{
    signal(2,handler);

    sigset_t pending;
    sigset_t block,oblock;


    sigemptyset(&block);
    sigemptyset(&oblock);
    
    sigaddset(&block,2);
  
    sigprocmask(SIG_SETMASK,&block,&oblock);

    int count=1;
    while(1)
    {
        sigemptyset(&pending);

        sigpending(&pending);
        show_pending(&pending);
        sleep(1);
        count++;
        if(count==20)
        {
            cout<<"recover sig mask!"<<endl;
            sigprocmask(SIG_SETMASK,&oblock,NULL);
        }
    }

    return 0;

    

}
