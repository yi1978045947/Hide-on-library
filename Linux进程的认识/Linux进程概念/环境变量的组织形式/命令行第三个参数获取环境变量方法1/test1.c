#include<stdio.h>
int main(int argc,char* argv[],char* env[])
{
    //argc : 命令行参数的个数， 本质上就是argv数组的元素个数
    //argv ：具体的命令行参数
    // envp : 环境变量的值
    for(int i=0;i<argc;i++)
    {
        printf("%s\n",argv[i]);
    }
    for(int i=0;env[i]!=NULL;i++)
    {
        printf("%s\n",env[i]);
    }
    return 0;
}
