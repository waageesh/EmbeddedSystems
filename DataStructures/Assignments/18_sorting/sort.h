#ifndef SORT_H
#define SORT_H

#define swap(a, b)	\
{			 \
	int temp = a;	 \
	     a   = b;	 \
	     b   = temp; \
}	

#define SUCCESS 1
#define FAILURE 0
typedef int data_t;

int bubble_sort(data_t arr[], data_t size);
int insertion_sort(data_t arr[], data_t size);
int selection_sort(data_t arr[], data_t size);
void print_array(int arr[], int size);

#endif
