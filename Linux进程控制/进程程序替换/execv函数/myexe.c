#include<stdio.h>
#include<unistd.h>
int main()
{
    printf("replace begin!\n");
    char* arg[]={"ls","-a","-l",NULL};
    execv("/usr/bin/ls",arg);
    printf("replace after!\n");
}
