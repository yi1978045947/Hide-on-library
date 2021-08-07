#include<stdio.h>
#include<unistd.h>
int main()
{
    int ret=fork(); 
    if(ret<0)
    {
        printf("fork error!\n");
    }
    else if(ret==0)
    {
        printf("child ret:%d\n",ret);
    }
    else
    {
        printf("parent ret:%d\n",ret);
    }
    return 0;
}
