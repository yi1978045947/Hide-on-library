#include"Thread_Pool.h"
using namespace std;


int main()
{
    ThreadPool *tp=new ThreadPool();
    
    tp->ThreadPoolInit();

    while(true)
    {
        int x=rand()%10+1;
        Task t(x);
        tp->Put(t);
        sleep(1);
    }
    return 0; 
}
