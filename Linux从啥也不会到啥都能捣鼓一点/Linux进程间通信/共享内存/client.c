#include<stdio.h>
#include"head.h"
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
int main()
{
    key_t k=ftok(PATHNAME,PROJ_ID);
    printf("key=%p\n",k);
    int shmid=shmget(k,SIZE,0);//创建共享内存

    if(shmid==-1)
    {
        printf("创建共享内存失败!\n");
        return 1;
    }
    printf("shmid=%d\n",shmid);
   // sleep(10);

    char* str=(char*)shmat(shmid,NULL,0);//关联共享内存
   // sleep(5);

    char arr[20] ="i am process A";
   /* for(c;c<=strlen(arr);c++)
    {
        str[c]=arr[c];
    }
   */
    strncpy(str,arr,strlen(arr));

  /*  char c='a';
    for(c;c<='z';c++)
    {
        str[c-'a']=c;
        sleep(3);
    }
    */
    shmdt(str);//去除关联的共享内存
    sleep(5);
   
   shmctl(shmid,IPC_RMID,NULL);//删除共享内存
   // sleep(10);
    return 0;
}
