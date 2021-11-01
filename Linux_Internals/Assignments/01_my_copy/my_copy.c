#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>

void copy_file_permissions(int fr, int fw);			// function prototype for copying file permissions
int my_copy(int source_fd, int dest_fd);			// function prototype for copying file permissions
int main(int argc, char* argv[])
{
	char cont;
	int file_permission_flag = 0;
	int fr, fw;
	if (argc == 1)						// no arguments passed
	{	
		printf("Insufficient arguments\nUsage:- ./my_copy [option] <source file> <destination file>\n");
		return -1;
	}
	if (!strcmp(argv[1], "-p"))				// -p flag passed
	{
		if (argc == 2)					// no file names passed as arg after -p flag
		{
			printf("missing file operand\n");
			return -1;
		}	
		else if (argc == 3)				// dest file is not provided
		{
			printf("missing destination file operand after 'file1.txt'\n");
			exit(0);
		}
		else						// -p along with src, dest files are provided
		{
			fr = open(argv[2], O_RDONLY);			// opening src file in read mode
			/* O_EXCL to check file already there */
			/*  O_CREATE to create and open file in write mode, if file doesn't exist */
			fw = open(argv[3], O_EXCL | O_CREAT | O_WRONLY);
			file_permission_flag = 1;		// making flag 1, to copy permissions too
		}
	}
	else							// -p flag not passed
	{
		if (argc == 2)					// DEST file not provided
		{
			printf("missing destination file operand after 'file1.txt'\n");
			return -1;
		}
		else if (argc == 3)				// both SRC, DEST files are provided
		{
			fr = open(argv[1], O_RDONLY);		// opening SRC file in read mode
			/* O_EXCL to check file already there
			   O_CREATE to create and open file in write mode, if file doesn't exist */
			fw = open(argv[2], O_EXCL | O_CREAT | O_WRONLY, 0666);
		}
	}

	if (fr == -1)						// opening file in read mode fails
	{
		perror("File open read mode ");		// prints message why file open failed for read mode
		return -1;
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
				if (!strcmp(argv[1],"-p"))			// -p provided for existing dest file
				{
					fw = open(argv[3], O_WRONLY | O_TRUNC);
				}
				else						// -p not provided for existing dest file
				{
					fw = open(argv[2], O_WRONLY | O_TRUNC);
				}
				if (fw == -1)					// if file dont have write permissions,to open in write mode
				{
					perror("cannot create regular file");
					return -1;
				}
			}
			else							// terminate if user entered n/N
			{
				exit(0);
			}
		}
	}
	if (file_permission_flag)						// if file copy flag is set to 1
	{
		copy_file_permissions(fr, fw);					// copy src file permissions to dest file
	}
	my_copy(fr, fw);
	exit(0);
}

void copy_file_permissions(int fr, int fw)			// function definition to copy src file permissions to dest file 
{
	struct stat* statbuf;					// declaring pointer to hold file info in stat structure
	fstat(fr, statbuf);					// passing declared stat pointer, to copy src file data
	fchmod(fw, statbuf->st_mode);				// passing st_mode(file permissions) from src file as argument to dest file
}

int my_copy(int source_fd, int dest_fd)
{
	char buff[50];						// buff string to stored copied bytes from src file
	int byte_cnt_left;	
	do
	{
		byte_cnt_left = read(source_fd, buff, 50);		// read 50 bytes from file1 to buff
		write(dest_fd, buff, byte_cnt_left);			// writes bytes read from buff to file2
	} while(byte_cnt_left == 50);				// if no of bytes read is less than 50,then it reached EOF
	return 1;
}
