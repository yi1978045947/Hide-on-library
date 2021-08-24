#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[])
{
    int fd, fd1, fd2;
    char bufs[20];
    int len;
    if (argc != 3)
    {
        printf("参数不对\n");
    }
    else
    {
        fd = open(argv[1], O_RDONLY | O_CREAT);
        if (fd != -1)
        {
            fd1 = creat(argv[2], 0775);
            if (fd1 != -1)
            {
                fd2 = open(argv[2], O_WRONLY);
                while ((len = read(fd, bufs, 20)) > 0)
                {
                    write(fd2, bufs, len);

                }

            }
            else
            {
                printf("创建文件失败\n");

            }

        }
        else
        {
            printf("要复制的文件不存在\n");

        }
    }
    return 0;
}
