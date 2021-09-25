#include<stdio.h>
#include<string.h>
void reverse(char* arr,int left,int right) 
{
    while(left<right)
    {
        int tmp=0;
        tmp=arr[left];
        arr[left]=arr[right];
        arr[right]=tmp;
        left++;
        right--;
    }
}
int main()
{
    char arr[]="abcdefghijkl";
    int len=strlen(arr);
    int left=0;
    int right=len-1;
    reverse(arr,left,right);
    printf("%s\n",arr);
}
