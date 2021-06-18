#include<stdio.h>
#include<unistd.h>
int main()
{
    printf("running before!\n");
    char* env[]={"myenv=Hello Linux!",NULL};
    execle("./mycmd","./mycmd",NULL,env);
    printf("running after!\n");
    return 0;
}
