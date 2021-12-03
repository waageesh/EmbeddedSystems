#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


int main() 
{
	int size, data, cnt;
	int element;
	int menu;
	char cont;
	printf("Enter the size of array :");
	scanf("%d", &size);
	queue_t* Q = malloc(size*sizeof(int));
	if (create(Q, size) != e_true)
	{
		printf("creating queue fails\n");
	}

	do
	{
		printf("1. Enqueue\n2. Dequeue\n3. peek\n4. Peep\n5. free_queue\n");
		printf("Choose option :");
		scanf("%d", &menu);

		switch(menu)
		{
			case 1 :	/* push elements to Queue  */
				{
					printf("Enter the element to be pushed :");
					scanf("%d", &data);
					if (Enqueue(Q, data) != e_true)
					{
						printf("queue is already full, Enqueue not possible\n");
					}
					break;
				}
			case 2 :	/* remove 1st most element in Queue  */
				{
					if (Dequeue(Q, &element) != e_true)
					{
						printf("Dequeue not possible for empty queue\n");
					}
					else
					{
						printf("Dequeued element is %d\n", element);
					}
					break;
				}
			case 3 :	/* print top most element in Queue  */
				{
					if (front(Q, &element) == e_true)
					{
						printf("Front : %d\n", element);
					}
					else
					{
						printf("queue is empty, no front element\n");
					}

					break;
				}
			case 4 :	/* print elements from queue  */
				{
					if (print_queue(Q) != e_true)
					{
						printf("queue is empty, no elements to print\n");
					}
					break;
				}
			case 5 :	/* free elements from Queue  */
				{
					if (free_queue(Q) != e_true)
					{
						printf("queue is already empty\n");
					}
					break;
				}
		}

		printf("Do you want to continue (yY/nN) :");		// asking user to continue or not
		scanf(" %c", &cont);	

	} while (cont == 'Y' || cont == 'y');				// continue if entered y/Y

	return 0;
}
