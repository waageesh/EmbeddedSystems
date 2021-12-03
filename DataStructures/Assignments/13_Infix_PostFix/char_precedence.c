#include <stdio.h>
#include <string.h>
#include "stack.h"

int char_precedence(char *ch1, char *ch2)
{
	struct precedence
	{
	  char op;
	  int prec;
	} precendence[] =
	{ { '+', 1 },
	  { '-', 1 },
	  { '*', 2 },
	  { '/', 2 },
	  { '^', 3 },
	  { '%', 4 },
	  { '(', 5 },
	  { ')', 5 },
	  { 0, 0 }};
	  
  	int prec_a = 0, prec_b = 0;

	for(int i=0; precendence[i].op && (!prec_a || !prec_b); i++)
	{
		if (*ch1 == precendence[i].op)
			prec_a = precendence[i].prec;
		if (*ch2 == precendence[i].op)
			prec_b = precendence[i].prec;
	}
	
	//printf("precedence 1 : %d, precedence 2 : %d\n", prec_a, prec_b);
	if (!prec_a || !prec_b)
	{
		//fprintf(stderr,"Could not find operator %c and/or %c\n", *ch1, *ch2);
		return(-2);
	}
	if (prec_a < prec_b)
	{
		//printf("%c has low precedence than %c\n", *ch1, *ch2);
		return -1;
	}
	if (prec_a == prec_b)
	{
		//printf("%c has equal precedence of %c\n", *ch1, *ch2);
		return 0;
	}
	return 1;
}
