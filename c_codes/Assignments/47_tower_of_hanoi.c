/*
Title  : Tower of Hanoi problem using recursive call
Author : Vaageesh
Date   : Tuesday 10 November 2020 01:22:49 PM IST
*/
#include <stdio.h>

int tower_of_hanoi(int n, char A, char B, char C);		// function prototype for Tower of Hanoi problem
int main()
{
	int n;						
	printf("Enter the number of disks");
	scanf("%d", &n);					// reading no of disks
	tower_of_hanoi(n, 'A', 'B', 'C');			// passing 'A','B','C' as disks to function call and "n" as no of rods

}
int tower_of_hanoi(int n, char A, char B, char C)		// function definition for Tower of Hanoi
{
	if (n>0)						// recursive call till rod count becomes 0
	{
		tower_of_hanoi(n-1, A, C, B);			// recursive call for moving n-1 rods from  A to B,  C being auxillary rod
		printf("make the legal move from rod %c to %c\n", A, C);
		tower_of_hanoi(n-1, B, A, C);			// recursive call for moving n-1 rods back B to C, A being auxillary rod
	}
	else
	{
		return 0;
	}
}

