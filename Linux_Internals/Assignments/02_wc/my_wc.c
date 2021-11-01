/*
Title	: implement wc linux command using syste call getopt() and open() and read() system calls
Author	: Vaageesh
Date	: Friday 01 January 2021 10:47:15 PM IST
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>

int word_count (int fd, int *lines, int *words, int *bytes);

int main(int argc, char* argv[])
{
	char buff[50], ch, prev;
	int fr, ret, menu, word_cnt=0, line_cnt=0, char_cnt=0 ;
	char opt;
	char* fname = malloc(10);
	int l_flag=0, w_flag=0, c_flag=0, i=0;
	while( (opt = getopt(argc,argv, "lwc")) != -1)	// read options from command line arguments
	{
		i++;
		switch (opt) 					// make corresponding flag as 1 based on flag given in terminal
		{
			case 'l':
				l_flag  = 1;
				break;
			case 'w':
				w_flag = 1;
				break;
			case 'c':
				c_flag = 1;
				break;
		}
	}
	if (argc != i+1)				// if file is given, word count from file
	{
		strcpy(fname, argv[i+1]);
		menu = 2;
	}
	else						// if file not given, word count from STDIN
	{
		menu=1;
	}
	switch(menu)
	{
		case 1:
			{
				word_count(0, &line_cnt, &word_cnt, &char_cnt);
				if (argc == 1)
				{
					l_flag = w_flag = c_flag = 1;
				}
				break;
			}
		case 2 :
			{
				/* O_EXCL to check file already there
		   		O_CREATE to create and open file in write mode, if file doesn't exist */
				fr = open(fname, O_EXCL | O_RDONLY, 0666);
				/* if not there send the error code to errno */
				if (fr == -1 && errno != EEXIST)				// opening file for read fails
				{
					perror("File Error");
					exit(0);
				}
				else
				{
					word_count (fr, &line_cnt, &word_cnt, &char_cnt);
				}
				if (argc == 2)
				{
					l_flag = w_flag = c_flag = 1;
				}
				break;
			}
	}
		
	if (l_flag)				// if -l flag given, print line count
	{
		printf("%d ", line_cnt);
	}
	if (w_flag)				// if -w flag given, print word count
	{
		printf("%d ", word_cnt);
	}
	if (c_flag)				// if -c flag given, print character count
	{
		printf("%d ", char_cnt);
	}
	printf("%s\n", fname);			// print file name if given
	return 0;
}

int word_count (int fd, int *lines, int *words, int *bytes)
{
	int ret;
	char buff[50], prev;
	do
	{
		ret = read(fd, buff, 50);
		if (ret == -1)					// if file doesn't exist
		{
			perror("read Error");
			exit(0);
		}
		//printf("char read:%d\n", ret);
		for(int i = 0; i < ret; i++)
		{
			//printf("%c", buff[i]);
			(*bytes)++;				// counting character
			if (buff[i] == '\n')			// line count , for every new line charaacter
			{
				(*lines)++;
				prev = buff[i];		// storing new line in prev
				continue;				
			}

			if (buff[i] == ' ' || buff[i] == '\t')		// checking character either space or tab space
			{
				prev = buff[i];				// storing space or tab in prev character
			}
			else if ( (buff[i] != ' ' || buff[i] != '\t') && ( prev == ' ' || prev == '\t' || prev == '\n' || !prev ) )
			{			// if character is non-empty and prev is either space or tab or newline or nothing
				(*words)++;			// then a word is there , count that word by incrementing
				prev = buff[i];
			}
		}
	} while(ret);
	//printf("line:%d, word:%d, char:%d\n", *lines, *words, *bytes);	
	return 1;
}




