#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<pwd.h>

typedef struct running_jobs{
	char jobName[100];
	pid_t pid;
	struct running_jobs *next;
}running_jobs;

int main(int argc, char **argv);

void displayprompt();
void loop(void);
void getdirectory();

//builtin functions
int cd(char **args);
int pwd(char **args);
int echo(char **args);
int pinfo(char **args);
int jobs();
int fg(char **args);
int killallbg();
int quit();
int kjob(char **args);

int execute(char **args);
int commandRun(char **args);
char *read_line(void);
char **split_line(char *line);
int split_command(char* line);
void sig_chld(int signo);
int launch(char **args);
int add_job(pid_t pid,char * jobName);
int delete_job(pid_t pid);


void ctrlC();
void ctrlD();