#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#define SIZE 256
#define NUM 16
int main()
{

    char cmd[SIZE];
    const char* cmd_line="[[无敌的我@VM-0-9-centos]$]";
    while(1)
    {
        cmd[0]=0;
        printf("%s",cmd_line);
        fgets(cmd,SIZE,stdin);
       // printf("%s",cmd);
        cmd[strlen(cmd)-1]='\0';
        char* args[NUM];
        args[0]=strtok(cmd," ");
        int i=1;
        do 
        {
            args[i]=strtok(NULL," ");//ls -l -a -i
            if(args[i]==NULL)
            {
                break;
            }
            i++;
        }while(1);
        pid_t pid=fork();
        if(pid<0)
        {
            printf("fork error");
        }
        else if (pid==0)
        {
            execvp(args[0],args);
            exit(1);
        }
        int status=0;
        pid_t ret=waitpid(pid,&status,0);
        if(ret>0)
        {
            printf("status code:%d\n",((status>>8)&0xff));
        }
    }
    return 0;
}
