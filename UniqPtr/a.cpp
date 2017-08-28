#include <iostream>
template<class T>
class my_ptr
{
private:
	T* ptr;
public:
	constexpr my_ptr(): ptr(NULL)
	{}
	my_ptr(T* t): ptr(t)
	{
		
	}
	my_ptr& operator = (my_ptr<T>&& obj)
	{
		Swap(*this, obj);
		obj.ptr = NULL;
		return *this;
	}
	void Print()
	{
		std::cout << ptr << "    " << *ptr << std::endl;
	}
	T* release()
	{
		my_ptr<T> a;
		Swap(*this, a);
		return a.get();
	}
	T* get()
	{
		return ptr;
	}
	T& operator* () 
	{
		return *ptr;
	}
	T* operator->() 
	{ 
		return ptr; 
	}
	void Swap(my_ptr<T>& first, my_ptr<T>& second)
	{
		using std::swap;
		swap(first.ptr, second.ptr);
	}
};

int main()
{
	my_ptr<int> a(new int(20));

	return 0;
}