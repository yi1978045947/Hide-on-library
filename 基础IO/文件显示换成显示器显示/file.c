#include<stdio.h>
#include<string.h>
int main()
{
    FILE *fp=fopen("log.txt","w");
    if(NULL==fp)
    {
        printf("打开文件失败!\n");
    }
    else 
    {
       /* char c='A';
        for(;c<'Z';c++)
        {
            fputc(c,fp);
        }*/
        const char* msg="Hello bit!";
       // fwrite(msg,strlen(msg),sizeof(char),fp);//往log.txt文件里面写
        fwrite(msg,strlen(msg),sizeof(char),stdout);//输出，往显示屏上输出

    }
    fclose(fp);
    return 0;
}
