/*================================================================
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>

using namespace std;

/*
 * 1.实现单线程的tcp服务端
 *
 *
 * 2.在单线程tcp服务端基础上， 添加epoll代码（让epoll监控两种文件描述符 侦听套接字 & 新连接套接字）
 *   epoll监控的文件描述符 = 1个侦听套接字 + 若干个新连接的套接字
 *        侦听套接字（读事件）： 一旦读事件就绪， 表示当前有新连接三次握手建立连接了， 调用accept函数处理读事件
 *        新连接的套接字（读事件） ： 一旦读事件就绪了，表示当前客户端给服务端发送消息了， 调用recv函数处理读事件
 * */

int main()
{
    int listen_sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(listen_sockfd < 0){
        perror("socket:");
        return 0;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(45678);
    addr.sin_addr.s_addr = inet_addr("0.0.0.0");

    int ret = bind(listen_sockfd, (struct sockaddr*)&addr, sizeof(addr));
    if(ret < 0){
        perror("bind:");
        return 0;
    }

    ret = listen(listen_sockfd, 5);
    if(ret < 0){
        perror("listen: ");
        return 0;
    }

    /*
     * 1.创建epoll操作句柄
     * 2.添加侦听套接字， 让epoll进行监控
     * 3.监控到侦听套接字的读事件之后， 调用accept函数处理读事件(接收新连接)
     *  区分到底是新连接套接字还是侦听套接字， 分别处理
     *    3.1 将新连接的套接字添加到epoll当种进行监控
     *
     *
     *  如果说是新连接套接字的读事件产生， 则接收数据
     *
     * */


    int epoll_fd = epoll_create(5);
    if(epoll_fd < 0){
        perror("epoll_create");
        return 0;
    }

    struct epoll_event ee;
    ee.events = EPOLLIN;
    ee.data.fd = listen_sockfd;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listen_sockfd, &ee);

    while(1){
        struct epoll_event arr[10];
        int ret = epoll_wait(epoll_fd, arr, 10, -1);
        if(ret < 0){
            perror("epoll_wait:");
            continue;
        }else if(ret == 0){
            continue;
        }
        //一定是由epoll监控的文件描述符， 有对应的就绪事件产生了
        for(int i = 0; i < ret; i++){
            if(arr[i].data.fd == listen_sockfd){
                //accept
                int new_sockfd = accept(listen_sockfd, NULL, NULL);
                if(new_sockfd < 0){
                    perror("accept:");
                    continue;
                }

                int flag = fcntl(new_sockfd, F_GETFL);
                fcntl(new_sockfd, F_SETFL, flag | O_NONBLOCK);

                struct epoll_event new_ee;
                new_ee.events = EPOLLIN | EPOLLET;
                new_ee.data.fd = new_sockfd;
                epoll_ctl(epoll_fd, EPOLL_CTL_ADD, new_sockfd, &new_ee);
            }else{
                int new_sockfd = arr[i].data.fd;
                string recv_buf;
                int flag = true;

                while(1){
                    char buf[2] = {0};
                    ssize_t recv_size = recv(new_sockfd, buf, sizeof(buf) - 1, 0);
                    if(recv_size < 0){
                        if(errno == EAGAIN || errno == EWOULDBLOCK){
                            flag = true;
                            break;
                        }
                        perror("recv:");
                        flag = false;
                        break;
                    }else if(recv_size == 0){
                        printf("peershutdown connect\n");
                        epoll_ctl(epoll_fd, EPOLL_CTL_DEL, new_sockfd, NULL);
                        close(new_sockfd);
                        flag = false;
                        break;
                    }
                    //printf("%s\n", buf);
                    recv_buf.append(buf);
                }

                if(flag == true){
                    printf("recv_buf: %s\n", recv_buf.c_str());
                    char buf[1024] = {0};
                    memset(buf, '\0', sizeof(buf));
                    strncpy(buf, "hello, i am server~~", sizeof(buf));
                    send(new_sockfd, buf, strlen(buf), 0);
               }
            }
        }
    }

    epoll_ctl(epoll_fd, EPOLL_CTL_DEL, listen_sockfd, NULL);
    close(listen_sockfd);
    return 0;
}
