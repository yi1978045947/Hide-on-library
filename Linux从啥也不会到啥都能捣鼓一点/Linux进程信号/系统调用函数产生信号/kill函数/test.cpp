#include<iostream>
#include<stdlib.h>
#include<signal.h>


int main(int argc,char* argv[])
{
    if(argc==3)
    {
        kill(atoi(argv[1]),atoi(argv[2]));
    }
    return 0;
}
