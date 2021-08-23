#include<stdio.h>
#include<unistd.h>
int main()
{
    printf("replace begin!\n");
    execlp("ls","ls","-a","-l",NULL);
    printf("replace after!\n");
    return 0;
}
