/*
Title  : queue implementation using linked list.
Author : Vaageesh
Date   : Wednesday 09 December 2020 05:23:51 PM IST
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define QEMPTY 1
#define QFULL 2

typedef int data_t;

typedef struct snode
{
	data_t data;
	struct snode *link;
}SLink;

typedef struct
{
	SLink *rear;
	SLink *front;
}Queue;

int enqueue(Queue *, data_t);
int dequeue(Queue *, data_t *);
void print_queue(Queue Q);


