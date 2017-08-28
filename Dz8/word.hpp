#ifndef _WORD_HPP_
#define _WORD_HPP_
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <math.h>
using namespace std;
class Word
{
public:
	Word(const string &s);
	void compare(string &s);
	double dispers();
private:
	void newSent();
	string word;
	vector <int> arrofnum;
};
#endif
