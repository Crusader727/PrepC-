#include "nsp_book.h"
#include <iostream>
#include <cstring>
#include <string>

void authorsBks(const char *name, my_book::Book *arr, const int size);
void publBks(const char *name, my_book::Book *arr, const int size);
void yearBks(int year, my_book::Book *arr, const int size);
void menu(my_book::Book *arr, const int size);
int main()
{
    //my_book::Book** arr;
    const int size = 10;
    my_book::Book arr[size];
    arr[0].setallparams("#1", "Ruben", "Moscow", 2007, 120);
    arr[1].setallparams("#2", "Ilya", "Odincovo", 2005, 213);
    arr[2].setallparams("#3", "Petros", "Moscow", 2004, 112);
    arr[3].setallparams("#4", "Nikolay", "Moscow", 1994, 201);
    arr[4].setallparams("#5", "Eric", "Yerevan", 2000, 333);
    arr[5].setallparams("#6", "Suren", "Paris", 1996, 588);
    arr[6].setallparams("#7", "Ruben", "Moscow", 2006, 135);
    arr[7].setallparams("#8", "Ruben", "Moscow", 2016, 727);
    arr[8].setallparams("#9", "Eric", "Yerevan", 2003, 255);
    arr[9].setallparams("#10", "Ilya", "Odincovo", 2015, 25);
    menu(arr, size);
    ini awd;
	//authorsBks("Ruben", arr, size);
	/*for(auto& b:arr)
		std::cout << b;*/
	return 0;
}
void menu(my_book::Book *arr, const int size)
{
    int i = 1;
    while (i != 0)
    {
	std::cout << std::endl
		  << std::endl
		  << std::endl;
	std::cout << "Enter 1 to get books of author" << std::endl;
	std::cout << "Enter 2 to get books of publ" << std::endl;
	std::cout << "Enter 3 to get books from year" << std::endl;
	std::cout << "Enter 0 to exit" << std::endl;
	char buf[20] = {0};
	int b;
	std::cin >> i;
	switch (i)
	{
	case 1:
	    system("clear");
	    std::cout << "Enter name of the author" << std::endl;
	    std::cin >> buf;
	    authorsBks(buf, arr, size);
	    break;
	case 2:
	    system("clear");
	    std::cout << "Enter name of the publ" << std::endl;
	    std::cin >> buf;
	    publBks(buf, arr, size);
	    break;
	case 3:
	    system("clear");
	    std::cout << "Enter year of books" << std::endl;
	    std::cin >> b;
	    yearBks(b, arr, size);
	    break;
	case 0:
	    break;
	default:
	    std::cout << "Not valid number try again" << std::endl;
	    std::cin >> i;
	    break;
	}
    }
}
