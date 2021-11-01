#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define BUFF_SIZE 255

char** cmd_line_parsing(char* sep, char** cmd_args,char* args);
int main(int argc, char* argv[])
{
	int pipe_cnt=0;
	char* args = malloc(255);
	for(int i=1,j=0; i<argc; i++)
	{
		if (!strcmp(argv[i], "|"))
		{
			pipe_cnt++;
		}
		strcat(args, argv[i]) ;
		strcat(args, " ") ;
	}
	char* cmd_args[pipe_cnt];
	cmd_line_parsing("|", cmd_args, args);
	
	int fd[pipe_cnt][2];
	int pid[pipe_cnt];
	int k=0;
	printf("parent %d started\n", getpid());
	int status, pipe_freq=0;
	// printf("pipe count %d\n", pipe_cnt);
    for (int i = 0; i < pipe_cnt+1; i++)
	{
		sleep(i);
		if (pipe(fd[i]) == -1)
			perror("pipe create");
		if ( (pid[i] = fork()) == 0)
		{
			
			printf("child %d started\n", getpid());
			if (i == 0)
			{
				printf("1st child\n");
				// first child, only write into (i)th pipe
				// close read end of curr pipe
				if (close(fd[i][0]) == -1)
					perror("pipe read end");
					
				// duplicate stdout with write end of curr pipe
				if (dup2(fd[i][1], 1) == -1)
					perror("redirect stdout");
					
				// write at write end of curr pipe
				char cmd_name[strlen(cmd_args[i])];
				strcpy(cmd_name, cmd_args[i]);
				printf("%s, %s\n",strtok(cmd_name," "), cmd_args[i]);
				
				system(cmd_args[i]);
				
				//printf("child %d completed\n", i);
				
				// execlp(strtok(cmd_name," "), cmd_args[i], (char*)NULL);
				// execvp(cmd_args[i], &cmd_args[i]);
			}
			else if (i == pipe_cnt)
			{
				printf("last child %d\n", i);
				// last child
				
				//close read end of curr pipe
				if (close(fd[i-1][1]) == -1)
					perror("pipe read end");
					
				// duplicate stdin with read end of curr pipe
				if (dup2(fd[i-1][0], 0) == -1)
					perror("redirect stdout");
					
				// read at read end of curr pipe
				char cmd_name[strlen(cmd_args[i])];
				strcpy(cmd_name, cmd_args[i]);
				printf("%s, %s\n",strtok(cmd_name," "), cmd_args[i]);
				
				//char buff[50] ;
				//if ( read(fd[i-1][0], buff, 50) == -1)
				//	perror("read from prev pipe error");
				//printf("buff read from prev pipe:%s", buff);
				system(cmd_args[i]);
				
				//printf("child %d completed\n", i);
				
				// execlp(strtok(cmd_name," "), cmd_args[i], (char*)NULL);
				// execvp(cmd_args[i], &cmd_args[i]);
			}
			else
			{
				printf("intermediate child\n");
				// intermediate child
				
				char* buff = malloc(BUFF_SIZE);
				// close write end of prev pipe
				
				if (close(fd[i-1][1]) == -1)
					perror("pipe write end close");
					
				// duplicate stdin with read end of prev pipe
				if (dup2(fd[i-1][0], 0) == -1)
					perror("redirect stdout");

				// close read end of curr pipe
				if (close(fd[i][0]) == -1)
					perror("pipe read end");
					
				// duplicate stdout with write end of curr pipe
				if (dup2(fd[i][1], 1) == -1)
					perror("redirect stdout");
					
				// write at write end of curr pipe
				char cmd_name[strlen(cmd_args[i])];
				strcpy(cmd_name, cmd_args[i]);
				printf("%s, %s\n",strtok(cmd_name," "), cmd_args[i]);
				
				system(cmd_args[i]);
				
				//printf("child %d completed\n", i);
				
				// execlp(strtok(cmd_name," "), cmd_args[i], (char*)NULL);
				// execvp(cmd_args[i], &cmd_args[i]);
			}
			printf("child %d with id %d completed\n", i, getpid());
			exit(0);
		}
		else
		{
			// printf("child %d started\n", pid[i]);
		}
	}
	
	if( pid[0] == -1 || pid[1] == -1 || pid[2] == -1 )		//if any of child process is not created then
	    {											//parent and child process will terminate
		printf("Unable to create child process!\n");
		exit(1);
	    }
    
    	/*
	while (wait(&status) != -1)
	{
		sleep(3);
		if (WIFEXITED(status))
		{
			printf("child %d terminated\n", pid[k++]);
		}
		else
		{
			printf("child process %d not terminated", pid[k]);
		}
		 //exit(0);
	}
	*/
	sleep(10);
    	exit(0);
}

char** cmd_line_parsing(char* sep, char** cmd_args, char* args)
{
	int len=0, pipe_cnt=0, k=0;
	
	char* token = strtok(args, sep);
	cmd_args[k] = malloc(strlen(token)+1);
	strcpy(cmd_args[k], token);
	k++;
	while(token)
	{
		token = strtok(NULL, sep);
		if (token == NULL)
			break;
		cmd_args[k] = malloc(strlen(token)+1);
		strcpy(cmd_args[k], token);
		k++;
	}
	return cmd_args;
}
