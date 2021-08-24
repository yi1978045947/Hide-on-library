#ifndef SHELL_H
#define SHELL_H
 
#define SHELL_CD 1
#define SHELL_FORK 2
#define SHELL_EMPTY 3
 
 
int read_char(char *str);
int parse_args(char *args[], char *arg);
int isquit(char *args);
char *shell_prompt(char *promptbuf);
int dealarg(char *arg);
int shell_cd(char *args[]);
int shell_fork(char *args[]);
int get_cmdnum(char *cmd);
int mutifork(char *args[]);
 
#endif

