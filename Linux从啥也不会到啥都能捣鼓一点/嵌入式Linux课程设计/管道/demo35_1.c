//fifo3.c
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "./test"
#define BUFFER_SIZE 128
#define TEN_MEG (1024*1024*10)

int main()
{
	int pipe_fd;
	int res;
	int open_mode = O_WRONLY;
	int bytes_sent = 0;
	char buffer[128];
	if(access(FIFO_NAME, F_OK) == -1)
	{
		res = mkfifo(FIFO_NAME, 0777);
		if(res != 0)
		{
			fprintf(stderr,"COULD not creat fifo %s \n",FIFO_NAME);
			exit(0);
		}
		printf("process %d opening FIFO O_WRONLY\n",getpid());
		pipe_fd = open(FIFO_NAME, open_mode);
		printf("Process %d result %d\n",getpid(),pipe_fd);

		if(pipe_fd != -1)
		{
			while(bytes_sent < TEN_MEG)
			{
				res = write(pipe_fd, buffer, BUFFER_SIZE);
				if(res == -1)
				{
					fprintf(stderr, "Write errer on pipe \n");
					exit(0);
				}
				bytes_sent += res;
			}
			(void)close(pipe_fd);
		}
		else
		{
			exit(EXIT_FAILURE);
		}
		printf("Process %d finished\n ",getpid());
		exit(EXIT_SUCCESS);
	}
	exit(0);
}

