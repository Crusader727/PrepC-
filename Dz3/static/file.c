#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "file.h"

void push(stack **head, char data) //new element
{
	stack *tmp = (stack*) malloc(sizeof(stack));
	tmp->symb = data;
	tmp->next = (*head);
	(*head) = tmp;
}

void pop(stack **head) //dell head element
{
	stack* prev = NULL;
	if (head == NULL || (*head) == NULL) 
	{
		return;
    	}
	prev = (*head);
	(*head) = (*head)->next;
	free(prev);
}


int fileRead(stack** head , FILE* ptrfile)
{
	char ch;
	int count = 0; //count for closers
	while( !feof(ptrfile) ) 
	{
		ch = getc(ptrfile);
		if (ch == '(' || ch == '[' || ch == '{') 
		{
			push(head , ch);
			count++;
		}
		if (ch == ')') 
		{
			if (count > 0 && (*head)->symb == '(')
				pop(head);
			else 
				return 0;
			count--;
		}
		if (ch == ']') 
		{
			if (count > 0 && (*head)->symb == '[')
				pop(head);
			else 
				return 0;
			count--;
		}
		if (ch == '}') 
		{
			if (count > 0 && (*head)->symb == '{' )
				pop(head);
			else 
				return 0;
			count--;
		}
	}
	if((*head) == NULL)
		return 1;
	else
		return 0;

}
