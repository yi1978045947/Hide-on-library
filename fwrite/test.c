#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    FILE* fp=fopen("test.txt","a+");
    if(fp==NULL)
    {
        printf("打开文件失败!\n");
        exit(1);
    }
    char *arr="bit education!";
    fwrite(arr,sizeof(char),strlen(arr),fp);
    fclose(fp);
    return 0;
}
