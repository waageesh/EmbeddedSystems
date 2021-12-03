/* 
Title  : Binary Search (Header file)
Author : Vaageesh
Date   : Monday 14 December 2020 11:40:49 PM IST
*/

#ifndef SEARCH_H
#define SEARCH_H

#include<stdio.h>
#include<stdlib.h>



typedef int data_t;

int binary_iterative(data_t arr[], data_t element, data_t high, data_t low);
int binary_recursive(data_t arr[], data_t element, data_t high, data_t low);

#endif 
