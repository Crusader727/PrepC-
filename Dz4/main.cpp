#include <iostream>
#include "fileRead.h"
using namespace std;

int main(int argc, char *argv[])
 {
	FILE *ptrfile = fopen(argv[1], "r");
	if(argc != 2)
	{
		cout << "Wrong data" << endl;
		return -1;
	}
	if(ptrfile == NULL)
	{
		cout << "Wrong file name" << endl;
		return -1;
    	}
	fileRead(ptrfile);
	fclose(ptrfile);
	return 0;
}
