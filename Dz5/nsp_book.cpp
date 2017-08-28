#include "nsp_book.h"
#include <cstring>
#include <iomanip>
namespace my_book
{
	Book::Book(const char* nme, const char* aut, const char* pub, const int y, const int pnum) : year(y), pcount(pnum)
		{   
			setparams(nme, aut, pub);
		}
	Book::~Book()
		{
			if(name != nullptr)
				delete[] name;
			if(publ != nullptr)
				delete[] publ;
			if(author != nullptr)
				delete[] author;
		}

	char* Book::getName()
		{
			return name;
		}
	char* Book::getAuthor()
		{
			return author;
		}
	char* Book::getPubl()
		{
			return publ;
		}
	int Book::getYear()
		{
			return year;
		}
	int Book::getPcount()
		{
			return pcount;
		}
	bool Book::setParam(const char* src,char** dest)
	{
		if(src != nullptr)
		{	
			if(*dest != nullptr && dest != nullptr)
				delete [] *dest;
			*dest = new char [strlen(src)+1];
			memcpy(*dest, src, strlen(src)+1);
			return 1;
		}
		else
		{
			*dest = new char[4];
			memcpy(*dest,"***",4);
			return 0 ;
		}
	}
	std::ostream& operator << (std::ostream& os, Book& b)
	{
		os << std::left << "Name:" << std::setw(4) << b.getName() << " Author:" << std::setw(8) << b.getAuthor() << " Public:" <<  std::setw(8) << b.getPubl() << " Year:" << std::setw(4) << b.getYear() << " Pages:" << std::setw(4) <<  b.getPcount() << std::endl;
		return os;
	}
	Book::Book(const Book& B)
	{
		setallparams(B.name, B.author, B.publ, B.year, B.pcount);
	}
	void Book::setparams(const char* nme ,const char* aut, const char* pub)
	{
			if(!setParam(nme,&name))
				std::cout << "Wrong data in Book" << std::endl;
			if(!setParam(aut,&author))
				std::cout << "Wrong data in Book" << std::endl;
			if(!setParam(pub,&publ))
				std::cout << "Wrong data in Book" << std::endl;
	}
	void Book::setallparams(const char* nme, const char* aut, const char* pub, const int y, const int pnum)
	{
		setparams(nme, aut, pub);
		if(y > 0)
			this->year = y;
		if(pnum > 0)
			this->pcount = pnum;
	}

	
}
void authorsBks(const char* name, my_book::Book* arr, const int size)
{
	bool flag = 0;
	if(arr == nullptr || name == nullptr)
	{
		std::cout << "Not correct parametors in function authorsBks" << std::endl;
		return ;
	}
	else
		for(int i = 0; i < size; i++)
		{
			if(!strcmp(arr[i].getAuthor(), name))
			{
				std::cout << arr[i];
				flag = 1;
			}
		}
	if (flag == 0)
		std::cout << "This author doesnt have books" << std::endl;
}
void publBks(const char* name, my_book::Book* arr, const int size)
{
	bool flag = 0;
	if(arr == nullptr || name == nullptr)
	{
		std::cout << "Not correct parametrs in function authorsBks" << std::endl;
		return ;
	}
	else
		for(int i = 0; i < size; i++)
		{
			if(strcmp(arr[i].getPubl(), name) == 0)
			{
				std::cout << arr[i];
				flag = 1;
			}
		}
	if (flag == 0)
		std::cout << "This Publ doesnt have books" << std::endl;
}
void yearBks(int year, my_book::Book* arr, const int size)
{
	bool flag = 0;
	if(arr == nullptr || year < 0 || year > 2016 )
	{
		std::cout << "Not correct parametrs in function authorsBks" << std::endl;
		return ;
	}
	else
		for(int i = 0; i < size; i++)
		{
			if(arr[i].getYear() >= year)
			{
				std::cout << arr[i];
				flag = 1;
			}
		}
	if (flag == 0)
		std::cout << "This author doesnt have books" << std::endl;

}
