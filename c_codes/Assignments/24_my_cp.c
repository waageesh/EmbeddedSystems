/*
Title  : File copy from source file to target file
Author : Vaageesh
Date   : Friday 13 November 2020 07:48:08 PM IST 
*/

#include <stdio.h>
#include <stdlib.h>

#define _GNU_SOURCE							// macro for closing all files at a time

void my_cp(FILE *src_fp, FILE *tgt_fp);					// function prototype for file_copy

int main(int argc, char *argv[])
{
	FILE *src_fp, *tgt_fp;						// defining file pointers using FILE macro for both src and tgt files
	src_fp = fopen(argv[1], "r");					// opening source file in read mode
	tgt_fp = fopen(argv[2], "w");					// opening target file in write mode
	if (src_fp == NULL && tgt_fp == NULL)				// checking if both files doesn't exist
	{
		printf("source & target files are missing\n");
		return -1;
	}
	else if (src_fp == NULL )					// checking if src file exist
	{
		printf("source file is missing\n");
		return -1;
	}
	else if (tgt_fp == NULL)					// chekcing if tgt file exist
	{
		printf("destination file is missing\n");
		return 1;
	}
	my_cp(src_fp, tgt_fp);						// calling file copying function
	fcloseall();							// closing all files after file copying
}

void my_cp(FILE *src_fp, FILE *tgt_fp)					// function definition for file copying
{
	char ch;							
	while( (ch = fgetc(src_fp)) != EOF )				// reading character everytime and checking across EOF
	{
		fputc(ch, tgt_fp);					// putting read character, in tgt_fp stream instead of stdout
	}
}

