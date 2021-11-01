#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
	char cont;
	int byte_cnt_left, fw, new_fw, fw_bkp, menu;
	if (argc == 1)						// no arguments passed
	{	
		printf("Insufficient arguments\nUsage:- ./dup <dest_file_buffer>\n");
		return -1;
	}	
	else							
	{
		/* O_EXCL to check file already there
		   O_CREATE to create and open file in write mode, if file doesn't exist */
		fw = open(argv[1], O_EXCL | O_CREAT | O_WRONLY, 0666);
	}

	/* if there send the error code to errno */
	if (fw == -1)						// opening file for write fails
	{
		if (errno == EEXIST)				// if file already exist, no need of creating it again
		{
			perror("File error ");
			printf("Do you want to overwrite (yY/nN) :");		// asking user to overwrite or not
			scanf(" %c", &cont);
			if (cont == 'y' || cont == 'Y')
			{
				fw = open(argv[1], O_WRONLY | O_TRUNC);
				if (fw == -1)					// if file dont have write permissions,to open in write mode
				{
					perror("cannot create regular file");
					return -1;
				}
				else
				{
					close(fw);				// close the file descriptor after truncating
				}
			}
			else							// terminate if user entered n/N
			{
				exit(0);
			}
		}
	}
	printf("1. dup\n2. dup2\nChoose from above option to print in other file instead of STDOUT :");
	scanf("%d", &menu);
	switch(menu)
	{
		case 1:
			{
				int fw_bkp = dup(1);				// fw_bkp has fd as 4 now which is also pointing to STDOUT
				close(1);					// close STDOUT fd now
				fw = open(argv[1], O_WRONLY | O_TRUNC);		// since 1 is closed above, it is least available fd value now
										// which is assigned to fw
				/* printing message to file */
				printf("This message is printing from dup to %s, instead of STDOUT\n", argv[1]); 
				break;
			}
		case 2:
			{	
				int fd_stdout;
				fw = open(argv[1], O_WRONLY | O_TRUNC);	// 3 is least available fd value now
										// which is assigned to fw
				fw_bkp = dup2(fw, 1);				// fw_bkp will be 1 now which is pointing to STDOUT
										// it silently close 1, and then assign fw_bkp with stdout
				
				/* printing message to file */
				printf("This message is from dup2 printing to %s, instead of STDOUT\n", argv[1]); 
				break;
			}
	}
	
	exit(0);
}

