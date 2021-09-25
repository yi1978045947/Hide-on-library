#include<stdio.h>
void _copy(char arr2[],char arr1[])
{
    int i=0;
    while(*arr1)
    {
        arr2[i]=*arr1;
        i++;
        arr1++;
    }
}
int main()
{
    char* arr1="abcdefg";
    char arr2[10];
    _copy(arr2,arr1);
    printf("%s\n",arr2);
}
