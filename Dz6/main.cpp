#include "classes.h"
#include <iostream>

int main()
{
	Polygon** arr = new Polygon*[2];
	std::cout << "this is triangle " << std::endl;
	arr[0] = new Triangle();
	arr[0]->type();
	std::cout << "this is square " << std::endl;
	arr[1] = new Square();
	arr[1]->type();
	std::cout << "*********" << std::endl;
	std::cout << arr[0]->area() << std::endl;
	std::cout << arr[1]->area() << std::endl;
	std::cout << "Triangles methods" << std::endl;
	Triangle t;
	t.medians();
	t.mediansPoint();
	t.bissektr();
	t.bissPoint();
	t.heighPoint();
	delete arr[0];
	delete arr[1];
	delete[] arr;
	return 0;
}
