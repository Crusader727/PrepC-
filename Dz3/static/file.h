#ifndef _FILE_H_
#define _FILE_H_
#include <stdio.h>

typedef struct stack
{
	char symb;
	struct stack *next;
} stack;
void push(stack **head , char data);
void pop(stack **head);
int fileRead(stack** head , FILE* ptrfile);

#endif //_FILE_H_
