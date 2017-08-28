#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "file.h"

int main(int argc , char *argv[])
{
	if(argc != 2)
	{
		printf("Wrong data\n");
		return -1;
	}
	FILE *ptrfile = fopen(argv[1], "r");
	if(ptrfile == NULL)
	{
		printf("Wrong file name \n");
		return -1;
	}
	stack* head = NULL;
	int result = fileRead(&head,ptrfile);
	if(result == 1)
		printf("Its OK! \n");
	else
		printf("Its not correct \n");
	fclose(ptrfile);
	return 0;
}
