#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <math.h>
#include "word.hpp"
using namespace std;


void fileReader(const string& file, Word& w)
{
	ifstream myfile (file);

	if (!myfile.is_open())
		throw runtime_error("File was not oppened");;
	string buf;

	while(myfile >> buf)
	{
		w.compare(buf);
	}
	myfile.close();
}

int main(int argc, char *argv[])
{
	if(argc != 3)
	{ 
		cout << "Wrong Data" << endl;
		return -1;
	}
	Word w(argv[2]);
	try
	{
		fileReader(argv[1],w);
	}
	catch(exception& e)
	{
		cout << e.what() << endl;
		return -1;
	}
	cout << "Dispers = " << w.dispers() << endl;
	return 0;
}
