#include<stdio.h>
int main()
{
    FILE *fp=fopen("log.txt","w");
    if(NULL==fp)
    {
        printf("打开文件失败!\n");
    }
    else 
    {
        char c='A';
        for(;c<'Z';c++)
        {
            fputc(c,fp);
        }
    }
    fclose(fp);
    return 0;
}
