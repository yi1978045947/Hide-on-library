#include<stdio.h>
#include<unistd.h>
int main()
{
    printf("fork begin!\n");
    fork();
    printf("fork end!\n");
    sleep(1);
    return 0;
}
