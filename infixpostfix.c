#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define n 100
int first;
char infix[n],postfix[n];
void push (char x)
{
	first++;
	postfix[first]=x;
}
char pop()
{
	if(first== -1)
	{
		return 1;
	}
	else
	{
		return postfix[first--];
	}
}

int checking(char x)
{
	if (x == '(')
	{
	return 0;
	}
	if(x== '+' ||  x== '-')
	{
		return 1;
	}
	if (x== '*' || x== '/')
	{
		return 2;
	}
	return 0;
}


int main()
{
	char *e,x;
	printf("Enter the expression in infix form:");
	scanf("%s",infix);
	printf("\n");
	e=infix;
	while (*e!= '\0')
	{
		if (isalnum(*e))
		{
			printf("%c",*e);
		}
		else
		{
			while (checking(postfix[first]) >= checking (*e))
			{
				printf("%c",pop());
			}
			push(*e);
		}
		e++;
	}
	while(first!= -1)
	{
		printf("%c",pop());
	}
	printf("\n");
	return 0;
}
