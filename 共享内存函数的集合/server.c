#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include"comm.h"
#include<sys/ipc.h>
#include<sys/shm.h>
int main()
{
    key_t k=ftok(PATHNAME,PROJ_ID);
    printf("key=%p\n",k);

    int shmid=shmget(k,SIZE,IPC_CREAT|0664);
    if(shmid<0)
    {
        printf("创建共享内存失败!\n");
        return 0;
    }
    char* addr=(char*)shmat(shmid,NULL,0);
    if(addr==NULL)
    {
        printf("关联失败!\n");
        return 0;
    }
    while(1)
    {
        printf("%s\n",(char*)addr);
        sleep(1);
    }
    //shmdt(addr);
    shmctl(shmid,IPC_RMID,NULL);
    return 0;
}
