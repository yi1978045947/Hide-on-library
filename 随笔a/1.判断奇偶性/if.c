#include<stdio.h>
int  Judge(int x)
{
    if(x%2==1)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
int main()
{
    int x=0;
    printf("请输入你要判断的数:");
    scanf("%d",&x);
    int ret=Judge(x);
    if(ret==1)
    {
        printf("这是奇数!\n");
    }
    else
    {
        printf("这是偶数!\n");
    }
    return 0;
}
