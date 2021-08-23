#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
    mkfifo("pipe",0664);
    return 0;
}
