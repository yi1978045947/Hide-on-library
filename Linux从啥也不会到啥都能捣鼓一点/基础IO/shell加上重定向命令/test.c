#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<ctype.h>
#define SIZE 256
#define NUM 16
void redirt(char* cmd)
{
    int fd=-1;
    int redirt_count=0;//检查>符号出现了几次
    char* ptr=cmd;//用ptr指向字符串cmd的首地址
    char* file=NULL;//防止文件名后面还出现空格
    while(*ptr)
    {
        if(*ptr=='>')
        {
            *ptr++='\0';
            redirt_count++;
            if(*ptr=='>')
            {
                *ptr++='\0';
                redirt_count++;
            }
            while(*ptr!='\0'&&isspace(*ptr))
            {
                ptr++;
            }
            file=ptr;//此时ptr指向文件名的首字符
            while(*ptr!='\0'&&isspace(*ptr))
            {
                ptr++;
            }
            *ptr='\0';//末尾以'\0'结束
            if(redirt_count==1)
            {
                fd=open(file,O_CREAT|O_TRUNC|O_WRONLY);
            }
            else if(redirt_count==2)
            {
                fd=open(file,O_CREAT|O_APPEND|O_WRONLY);
            }
            else 
            {

            }
            dup2(fd,1);
            close(fd);
        }
        ptr++;
    }
}
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
        pid_t pid=fork();
        if(pid<0)
        {
            printf("fork error");
        }
        else if (pid==0)
        {
            redirt(cmd);

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
                execvp(args[0],args);
                exit(1);
            }while(1);
            int status=0;
            pid_t ret=waitpid(pid,&status,0);
            if(ret>0)
            {
                printf("status code:%d\n",((status>>8)&0xff));
            }
        }
        return 0;
    }
}
