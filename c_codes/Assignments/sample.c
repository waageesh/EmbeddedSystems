#include<stdio.h>
#include<stdlib.h>
void foo1()
{
	printf("In foo1()\n");
}

void foo2()
{
	printf("In foo1()\n");
}

void foo3()
{
	printf("In foo1()\n");
}

int main()
{
	atexit(foo1);  // throws error
	atexit(foo2);  // throws warning
	atexit(foo3);  // works fine
	int x;
	scanf("%d",x);
	return 0;
}
