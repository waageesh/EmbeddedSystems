/*
Title  : File concatenation using file pointers
Author : Vaageesh
Date   : Friday 13 November 2020 07:48:08 PM IST 
*/

#include <stdio.h>
#include <stdlib.h>

#define _GNU_SOURCE							// macro for closing all files at a time

void file_concat(FILE *src1_fp, FILE *src2_fp, FILE *tgt_fp);					// function prototype for file_copy

int main(int argc, char *argv[])
{
	FILE *src1_fp, *src2_fp, *tgt_fp;				// defining file pointers using FILE macro for both src and tgt files
	src1_fp = fopen(argv[1], "r");					// opening source file in read mode
	src2_fp = fopen(argv[2], "r");					// opening target file in write mode
	tgt_fp = fopen(argv[3], "w");					// opening target file in write mode
	char* str = malloc(sizeof(char*)*1024);
	if (argc == 1)							// checking if no arguments are given
	{
		fgets(str, 1024 ,stdin);				// reading from stdin
		fputs(str, stdout);					// printing on stdout
		return -1;
	}
	if (src1_fp != NULL && src2_fp == NULL && tgt_fp == NULL)		// checking if both FILE2 & tgt file doesn't exist
	{
		char ch;
		while( (ch = fgetc(src1_fp)) != EOF)			// prinnting FILE1 content alone
		{
			printf("%c", ch);
		}
		return -1;
	}
	else if (src1_fp != NULL && src2_fp != NULL && tgt_fp == NULL )			// checking if both files exist & tgt file doesn't exist
	{
		char ch;
		printf("<contents of %s>\n", argv[1]);
		while( (ch = fgetc(src1_fp)) != EOF)			// printing FILE1 content
		{
			fputc(ch, stdout);
		}
		printf("<contents of %s>\n", argv[2]);
		while( (ch = fgetc(src2_fp)) != EOF)			// printing FILE1 content
		{
			fputc(ch, stdout);
		}
		return -1;
	}
	else if (tgt_fp == NULL)					// chekcing if tgt file exist
	{
		printf("destination file is missing\n");
		return 1;
	}
	file_concat(src1_fp, src2_fp, tgt_fp);				// calling file concating function
	fcloseall();							// closing all files after file copying
}

void file_concat(FILE *src1_fp,FILE *src2_fp, FILE *tgt_fp)		// function definition for file copying
{
	char ch;							
	while( (ch = fgetc(src1_fp)) != EOF )				// reading character everytime and checking across EOF
	{
		fputc(ch, tgt_fp);					// putting read character, in tgt_fp stream instead of stdout
	}
	while( (ch = fgetc(src2_fp)) != EOF )				// reading character everytime and checking across EOF
	{
		fputc(ch, tgt_fp);					// putting read character, in tgt_fp stream instead of stdout
	}
}

