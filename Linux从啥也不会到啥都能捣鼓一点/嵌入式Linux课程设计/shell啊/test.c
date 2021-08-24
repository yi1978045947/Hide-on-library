#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

// 最大输入字符
#define MAXLINE 4096
// 最大可以使用的管道数
#define MAXPIPE 16
// 最大能存储的命令中的字符串，比如ls -l -R > file 这个命令有5个字符串，以空格区分
#define MAXARG 8  

struct Cmd { 
	// argv是命令的每个部分，以空格分隔
	char *argv[MAXARG];
	// in和out分别表示输入重定向和输出重定向的文件名字符串
	char *in, *out; 
} cmd[MAXPIPE+1];

int parse(char *buf, int cmdnum)
{
	int n = 0; // n是命令分割出来的字符串的次数。
	char *p = buf; // 当前解析到的字符。
	cmd[cmdnum].in = cmd[cmdnum].out = NULL;

	//ls -l -d -a -F  > out
	while (*p != '\0') {

		if (*p == ' ') {            //将字符串中所有的空格,替换成'\0',方便后续拆分字符串
			*p++ = '\0';
			continue;
		}

		if (*p == '<') {
			*p = '\0';
			while (*(++p) == ' ');    /* cat <     file 处理连续多个空格的情况*/
			// p的位置为 < 后第一个不为 ' ' 的字符，比如cat <     file为 f
			cmd[cmdnum].in = p;
			if (*p++ == '\0') //输入重定向<后面没有文件名
				return -1;
			continue;
		}

		if (*p == '>') {
			*p = '\0';
			while (*(++p) == ' '); // 同理输入重定向
			cmd[cmdnum].out = p;
			if (*p++ == '\0')
				return -1;
			continue;
		}

		// argv中存入每一个字符的第一个位置
		// 如果p处于第一个位置或者p的前一个位置是空格，那么这个位置就是分割出的第一个位置。
		if (*p != ' ' && ((p == buf) || *(p-1) == '\0')) {

			if (n < MAXARG - 1) {
				cmd[cmdnum].argv[n++] = p++;   //"ls -l -R > file"
				continue;
			} else {
				return -1;
			}
		}
		p++;
	}

	// n为0说明没有输入。
	if (n == 0) {
		return -1;
	}

	cmd[cmdnum].argv[n] = NULL;

	return 0;
}

int main(void)
{
	// 存储输入的字符
	char buf[MAXLINE];
	// 进程号
	pid_t pid;
	// 文件描述符，
	int fd;
	// 数组下标定位
	int i;
	// 数组下标定位
	int j;
	// 储存管道数组，0是读端，1是写端
	int pfd[MAXPIPE][2];
	// 管道数量
	int pipe_num;
	// 命令数量
	int cmd_num;
	// 当前命令指针，下一个命令指针
	char* curcmd, *nextcmd;

	while (1) {
		printf("mysh%% ");
		// 从stdin中读取最大MAXLINE个字符
		if (!fgets(buf, MAXLINE, stdin))
			exit(0);
		// "ls -l\n"
		if (buf[strlen(buf)-1]=='\n')
			buf[strlen(buf)-1]='\0';
		cmd_num = 0;
		nextcmd = buf;

		// 实现管道符
		// 把nextcmd拆分,curcmd是前半部分，nextcmd为后半部分。
		while ((curcmd = strsep(&nextcmd, "|"))) {

			if (parse(curcmd, cmd_num++)<0) {
				cmd_num--;
				break;
			}

			// 如果最大命令数满了，那么就不能执行下去。
			if (cmd_num == MAXPIPE + 1)     
				break;
		}

		if (!cmd_num)
			continue;

		pipe_num = cmd_num - 1;     //根据命令数确定要创建的管道数目

		for (i = 0; i < pipe_num; i++) {    //创建管道
			if (pipe(pfd[i])) { //创建失败
				perror("pipe");
				exit(1);
			}
		}

		for (i = 0; i < cmd_num; i++) {     //管道数目决定创建子进程个数
			if ((pid = fork()) == 0)
				break;
		}

		if (pid == 0) {
			if (pipe_num) {     //用户输入的命令中含有管道 

				if (i == 0) {                //第一个创建的子进程
					dup2(pfd[0][1], STDOUT_FILENO);
					close(pfd[0][0]);

					for (j = 1; j < pipe_num; j++) { //在该子进程执行期间,关闭该进程使用不到的其他管道的读端和写端
						close(pfd[j][0]);
						close(pfd[j][1]);
					}

				} else if (i==pipe_num) {    //最后一个创建的子进程
					dup2(pfd[i-1][0], STDIN_FILENO);
					close(pfd[i-1][1]);

					for (j = 0; j < pipe_num-1; j++) { //在该子进程执行期间,关闭该进程不使用的其他管道的读/写端
						close(pfd[j][0]);
						close(pfd[j][1]);
					}

				} else {
					dup2(pfd[i-1][0], STDIN_FILENO);    //重定中间进程的标准输入至管道读端
					close(pfd[i-1][1]);                 //close管道写端

					dup2(pfd[i][1], STDOUT_FILENO);     //重定中间进程的标准输出至管道写端
					close(pfd[i][0]);                   //close管道读端

					for (j = 0; j < pipe_num; j++)    //关闭不使用的管道读写两端
						if (j != i || j != i-1) {
							close(pfd[j][0]);
							close(pfd[j][1]);
						}
				}
			}

			if (cmd[i].in) {            /*用户在命令中使用了输入重定向*/
				fd = open(cmd[i].in, O_RDONLY); //打开用户指定的重定向文件,只读即可
				if (fd != -1)
					dup2(fd, STDIN_FILENO);     //将标准输入重定向给该文件
			}

			if (cmd[i].out) {           /*用户在命令中使用了输出重定向*/
				fd = open(cmd[i].out, O_WRONLY|O_CREAT|O_TRUNC, 0644);  //使用写权限打开用户指定的重定向文件
				if (fd != -1)
					dup2(fd, STDOUT_FILENO);    //将标准输出重定向给该文件
			}

			execvp(cmd[i].argv[0], cmd[i].argv);    //执行用户输入的命令
			fprintf(stderr, "executing %s error.\n", cmd[i].argv[0]);
			exit(127);
		}

		/*  parent */
		for (i = 0; i < pipe_num; i++) { /*父进程不参与命令执行,关闭其掌握的管道两端*/
			close(pfd[i][0]);
			close(pfd[i][1]);
		}

		for (i = 0; i < cmd_num; i++) { /*循环回首子进程*/
			wait(NULL);
		}
	}
}
