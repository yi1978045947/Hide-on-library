#include<stdio.h>
#include<unistd.h>
int main()
{
    while(1)
    {
        sleep(1);
        printf("Hello Linux!\n");
    }
    return 0;
}
