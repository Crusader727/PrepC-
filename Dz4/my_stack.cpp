#include "my_stack.h"
#include <string.h>
#include <iostream>
using namespace my_stack;
int stack:: get_result()
			{
				return mass[0];
			}
int stack:: get_size()
			{
				return size;
			}
void stack:: push(int data)
			{
				if(size == cap)
					extend();
				mass[size] = data;
				size++;
			}
int stack:: pop()
			{
				if(size > 0)
				{
					size--;
					return mass[size];
				}
				else 
					return 0;
			}
stack::	~stack()
		{
			delete[] mass;
		}
stack::	stack(const int col)
		{
			mass = new int[col];
			size = 0;
			cap = col;
		}
void stack::extend(const int num)
			{
				int* ptr = new int[cap * num];
				memcpy(ptr, mass, size*sizeof(int)); 
				delete[] mass;
				mass = ptr;
			}
