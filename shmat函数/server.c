#include<stdio.h>
#include<sys/types.h>
#include"comm.h"
#include<sys/ipc.h>
#include<sys/shm.h>
int main()
{
    key_t k=ftok(PATHNAME,PROJ_ID);
    printf("key=%p\n",k);

    int shmid=shmget(k,SIZE,IPC_CREAT|IPC_EXCL|0666);//创建共享内存
    if(shmid<0)
    {
        printf("创建共享内存失败!\n");
        return 1;
    }
    printf("shmid=%d\n",shmid);

    char* str=(char*)shmat(shmid,NULL,0);
    
    shmdt(str);//去除关联的共享内存

    shmctl(shmid,IPC_RMID,NULL);//删除共享内存

    return 0;
}
