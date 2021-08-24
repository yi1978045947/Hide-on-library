#include<stdio.h>
int main()
{
    int x=0;
    scanf("%d",&x);
    switch(x%2)
    {
        case 0:
            printf("这是偶数!\n");
            break;
        case 1:
            printf("这是奇数!\n");
            break;
    }
    return 0;
}
