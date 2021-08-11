#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    char cmd[100];
    while(1)
    {
        printf("输入指令 > ");
        gets(cmd);
        int len=strlen(cmd);
        if(cmd[0] == 'e' && cmd[1] == 'c') // echo
        {
            int flag=0;
            int i=0;
            for( i=5; i<len; i++)
            {
                if(cmd[i]!=' ') flag=1;
                if(flag)
                {
                    putchar(cmd[i]);
                }
            }
            if(flag) putchar('\n');
        }
        else if(cmd[0]=='q' || cmd[1]=='x' || cmd[0]=='b') // quit,exit,bye
        {
            puts('Bye ~');
            return 0;
        }
        else if(cmd[0]=='h') // help
        {
            printf("/**********************************/\n");
            printf("echo <content>\tprint a line content\n");
            printf("quit,exit,bye\tend produce\n");
            printf("ls   <catalog>\tshow catalog\n");
            printf("jobs\techo process name and pid...\n");
            printf("environ\techo environment variable\n");
            printf("/**********************************/\n");
        }
        else
        {
            char cata[100];
            int cnt=0;
            if(cmd[0]=='c') // cd
            {
                int flag=0;
                int i=0;
                for( i=3; i<len; i++)
                {
                    if(cmd[i]!=' ') flag=1;
                    if(flag)
                    {
                        cata[cnt++] = cmd[i];
                    }
                }
                if(cnt==0)
                {
                    cata[0]='.';
                    cata[1]='\0';
                }
            }
            /* fork a child process */
            pid_t pid = fork();
            if (pid < 0)
            {
                /* error occurred */
                fprintf(stderr, "Fork Failed");
                return 1;
            }
            else if(pid==0)
            {
                if(cmd[0]=='ls') //ls 
                {
                    execlp("/bin/ls",cata,NULL);
                }
                else if(cmd[0]=='j') // jobs
                {
                    execlp("pstree","-p",NULL);
                }
                else if(cmd[0]=='e') // environ
                {
                    execlp("env","",NULL);
                }
            }
            else
            {
                /* wait wait，until child process exit*/
                wait();
            }
        }
    }
    return 0;
}
