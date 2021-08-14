#include<stdio.h>
int main()
{
    int i=1000;
    int sum=0;
    while(i<=2000)
    {
        if(i%16==0)
        {
            sum=sum+i;
        }
        i++;
    }
    printf("%d\n",sum);
    return 0;
}
