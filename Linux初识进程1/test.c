#include<stdio.h>
#include<unistd.h>
int main()
{
    while(1)
    {
        printf("Hello process1\n");
        sleep(1);
    }
    return 0;
}
