/*
 ================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <errno.h>
#include <string>
/*
 * 1.监控0号文件描述符对应的可读事件
 */

using namespace std;

int main()
{
    int flag = fcntl(0, F_GETFL);
    fcntl(0, F_SETFL, flag | O_NONBLOCK);


    //1.创建epoll操作句柄
    int epfd = epoll_create(5);
    if(epfd < 0)
    {
        perror("epoll_create:");
        return 0;
    }

    //2.添加0号文件描述符对应的事件结构到epoll当中

    struct epoll_event ee;
    ee.events = EPOLLIN | EPOLLET;
    //ee.data.fd = 0 : 当监控成功之后， 从双向链表当中将事件结构拷贝到用户空间的事件结构数组当中之后
    //程序员可以通过该结构当中的fd， 知道该事件结构属于哪一个文件描述符
    ee.data.fd = 0;

    epoll_ctl(epfd, EPOLL_CTL_ADD,  0,  &ee);

    //epoll等待
    int count = 0;
    while(1)
    {
        struct epoll_event arr[10];
        //int ret = epoll_wait(epfd, arr, 10, -1);
        //int ret = epoll_wait(epfd, arr, 10, 1000);
        int ret = epoll_wait(epfd, arr, 10, 0);
        if(ret < 0)
        {
            perror("epoll_wait:");
            return 0;
        }
        else if(ret == 0)
        {
            //printf("timeout: %d\n", count++);
            continue;
        }

       
        string str;
        while(1)
        {
            char buf[2] = {0};
            int ret = read(arr[0].data.fd, buf, sizeof(buf) - 1);
            //printf("ret : %d\n", ret);
            if(ret < 0)
            {
                if(errno == EAGAIN || errno == EWOULDBLOCK)
                {
                   break;
                }
            }
            //a b c 
            //
            printf("%s ", buf);
            str.append(buf);
            //printf("count: %d\n", count++);
        }

        printf("str : %s\n", str.c_str());
    }
    return 0;
}
