#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    FILE* fp=fopen("test.txt","w+");
    if(fp==NULL)
    {
        printf("文件打开失败!\n");
        exit(1);
    }
    fwrite("bit person!",sizeof(char),11,fp);
    fseek(fp,0,SEEK_CUR);
    char arr[100];
    fread(arr,sizeof(char),strlen(arr),fp);
    fclose(fp);
    return 0;
}
