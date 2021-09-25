#include<stdio.h>
#include<malloc.h>
int main()
{
   unsigned  char* arr=(char*)malloc(sizeof(char)*256); 
    int i=0;
    for(i=0;i<256;i++)
    {
        arr[i]=i;
    }
    for(i=0;i<256;i++)
    {
        printf("0x%02x\n",arr[i]);
    }
    return 0;
}
