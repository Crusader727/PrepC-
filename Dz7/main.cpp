#include "String.h"
#include "mySet.h"

int main()
{
	mySet<int> a ;
	a.add(10);
	a.add(12);
	a.add(7);
	a.add(6);
	a.add(3);
	a.add(5);
	a.add(4);
	a.Print();
	try{
		a.add(4);
	}
	catch(exception& e)
	{
		cout << e.what() << endl;
	}
	a.erase(4);
	a.erase(5);
	a.erase(12);
	a.erase(6);
	a.Print();
	cout << "<<<STRING>>>" << endl;
	mString a1("String 1 ");
	mString b("String 2");
	mString c = a1 + b;
	cout << c << endl; 
return 0;
}
