#include <iostream>
#include <string.h>
#include "my_stack.h"
#include <cstdio>
using namespace std;
using namespace my_stack;

void fileRead(FILE* ptr)
{   
	if(ptr == NULL)
	{
		cout << "Wrong file name in fileRead" << endl;
		return ;
    	}
	stack St;
	char ch;
	int a;
	while(!feof(ptr) && (ch = getc(ptr)) != '\n')
	{	
		if ( isdigit(ch) )
			St.push(ch - 48);
		else
		{
			switch(ch)
			{
				case '+' : 
					St.push(St.pop() + St.pop());
					break;
				case '-' : 
					a = St.pop();
					St.push(St.pop() - a);
					break;
				case '*' : 
					St.push(St.pop() * St.pop());
					break;
				case '/' : 
					a = St.pop();
					St.push(St.pop() / a);
					break;
				default :
					cout << "Wrong data in File!" << endl;
					return;
				};
		}
	}
	if(St.get_size() == 1)
		cout << "Result = " << St.get_result() << endl;
	else
		cout << "Wrong number of data in file" << endl;
}
