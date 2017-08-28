#include "String.h"
#include "newSet.h"

int main()
{
	/*String a("awd");
	String b("sss");
	cout << a << endl << b << endl;
	a = b;
	cout << a << endl << b << endl;
	return 0;*/
	newSet<int> a(2);
	a.Insert(4);
	a.Insert(5);
	a.Insert(11);
	a.Insert(9);
	a.Insert(55);
	a.Insert(1);
	a.Print();
	/*std::cout << a.Min() << std::endl;
	std::cout << a.Max() << std::endl;*/
	std::cout<< std::endl<<std::endl;
	a.Erase(2);
	a.Erase(55);
	a.Print();
}
