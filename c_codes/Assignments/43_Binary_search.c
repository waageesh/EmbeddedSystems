#include<stdio.h>
#include<string.h>
#include<string.h>

int main(int  argc, char* argv[], char* envp[])
{
	int size,menu;
	scanf("%d",&size);
	printf("1. Int\n2. Char\n3. Float\n4. Double\n5. String\nChoice: ");
	scanf("%d",&menu);
	switch(menu)
	{
		case 1:
			{
				int arr[atoi(argv[1])];   // size from command line argument

				printf("Enter the elements : ");
				for(int i=0; i < atoi(argv[1]); i++)
				{
					scanf("%d", &arr[i]);
				}
				qsort(arr, argv[1], sizeof(int), compare);

				printf("After sorting elements : ");
				for(int i=0; i < argv[1]; i++)
				{
					printf("%d", arr[i]);
				}
				break;
			}
		case 2:
			{
				break;
			}
		case 3:
			{
				break;
			}
		case 4:
			{
				break;
			}
		case 5:
			{
				break;
			}
	}

	void compare(void* a, void* b)
	{
		for (int i=0; i<)
		{

			if (*a == *b)
			{
				return 0;
			}
			else if (*a > *b)
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}






		return 0;

	}
}
