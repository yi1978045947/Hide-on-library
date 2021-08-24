#include<stdio.h>
#include<unistd.h>
int main()
{
    printf("replace begin!\n");
    execl("/usr/bin/ls","ls","-a","-l",NULL);
    printf("replace after!\n");
    return 0;
}
