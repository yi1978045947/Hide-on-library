#include<stdio.h>
int main()
{
    int i=0;
    int sum=0;
    for(i=100;i<=200;i++)
    {
        if(i%2==1)
        {
            sum=sum+i;
        }
    }
    printf("%d\n",sum);
    return 0;
}
