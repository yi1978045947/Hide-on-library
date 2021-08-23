#include<stdio.h>
#include<sys/types.h>
#include"comm.h"
#include<sys/ipc.h>
#include<sys/shm.h>
int main()
{
    key_t k=ftok(PATHNAME,PROJ_ID);
    printf("key=%p\n",k);

    int shmid=shmget(k,SIZE,IPC_CREAT|IPC_EXCL);
    if(shmid<0)
    {
        printf("创建共享内存失败!\n");
    }
    return 0;
}
