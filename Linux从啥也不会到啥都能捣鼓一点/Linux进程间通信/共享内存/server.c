#include<stdio.h>
#include"head.h"
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main()
{
    key_t k=ftok(PATHNAME,PROJ_ID);
    printf("key=%p\n",k);
    int shmid=shmget(k,SIZE,IPC_CREAT|IPC_EXCL|0666);//创建共享内存

    if(shmid==-1)
    {
        printf("创建共享内存失败!\n");
        return 1;
    }
    printf("shmid=%d\n",shmid);
    sleep(5);

    char* str=(char*)shmat(shmid,NULL,0);//关联共享内存
   // sleep(5);
   while(1)
   {
       sleep(1);
       printf("%s\n",str);
   }

    shmdt(str);//去除关联的共享内存
   // sleep(5);

    shmctl(shmid,IPC_RMID,NULL);//删除共享内存
    sleep(5);
    return 0;
}
