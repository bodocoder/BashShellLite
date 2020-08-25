#include "header.h"


char *dir;//current working directory
char username[80],host[40];

void loop(void){
	char *line;
	int status;
	do{
		printf("<%s@%s:%s>",username,host,dir);
		line=read_line();
		char *myline;
		status=split_command(line);//this function also executes command
		free(line);

		//signal handling
		signal(SIGINT,ctrlC);
		signal(SIGQUIT,ctrlD);
	}while(status);
}

void getdirectory(){
	char thishome[20]="myshell";
	char Dir[200];
	getcwd(Dir,200);
	dir=strstr(Dir,thishome);
	//if dir=home
	if(strcmp(dir,thishome)==0)
		dir="~";
	else{
		char *temp=strtok(dir,thishome);
		strcpy(dir,"~");
		strcat(dir,temp);
	}
}

void prompt(){
	//username
	struct passwd *p=getpwuid(getuid());
	strcpy(username,p->pw_name);
	//hostname
	gethostname(host,40);
	//get current working directory
	getdirectory();
}

int main(int argc, char **argv)
{
	//prompt
	prompt();

	//command loop
	loop();

	return 0;
}