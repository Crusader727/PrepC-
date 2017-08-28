#include "word.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <math.h>

Word::Word(const string &s)
	{
		word = s;
		this->newSent();
	}
void Word::compare(string &s)
	{
		char buf = s.back();
		if(ispunct(buf)) 
			s.pop_back();
		if(word == s)
			arrofnum.back() = arrofnum.back() + 1;
		if(buf == '.' || buf == '?' || buf == '!')
			this->newSent();
	}
double Word::dispers()
	{
		arrofnum.pop_back();
		if(arrofnum.size() == 1 || arrofnum.size() == 0)
			return 0;
		float mid = accumulate(arrofnum.begin(), arrofnum.end(), 0);
		mid /= arrofnum.size();
		double disp = 0;
		for(int i = 0; i < arrofnum.size(); i++)
			disp += (arrofnum[i] - mid) * (arrofnum[i] - mid);
		disp /= arrofnum.size() - 1;
		disp = sqrt(disp);
		return disp;

	}
void Word::newSent()
	{
		arrofnum.push_back(0);
	}
