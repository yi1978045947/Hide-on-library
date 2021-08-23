#include<stdio.h>
#include<stdlib.h>
int main()
{
    int sum=0;
    int i=0;
    for( i=0;i<100;i++)
    {
      sum=sum+i;
    }
    printf("sum=%d\n",sum);
    printf("myenv:%s\n",getenv("myenv"));
    return 0;
}
