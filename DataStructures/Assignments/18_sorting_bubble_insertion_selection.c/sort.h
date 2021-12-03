#ifndef SORT
#define SORT

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define ARRAYSIZE 25
#define NOELEMENT -2


void swap(int *a, int *b);

void print_array(int array[], int n);

int bubbleSort(int array[], int narray);

int insertionSort(int array[], int narray);

int selectionSort(int array[], int narray);


#endif
