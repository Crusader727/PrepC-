#include <iostream>
//#include <memory>
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
	void reset(T* t = NULL)
	{
		ptr = t;
	}
	operator bool()
	{
		return !(ptr == NULL);
	}
	void Swap(my_ptr<T>& first, my_ptr<T>& second)
	{
		using std::swap;
		swap(first.ptr, second.ptr);
	}
	/*bool operator== (my_ptr<T>* New)
	{
		return !(this->ptr == New->ptr);
	}
	bool operator != (my_ptr<T>* New)
	{
		return !(this == New);
	}*/
	//bool operator > (const my_ptr<T>& left, const my_ptr<T>& right)
	//{
	//	return ((*(left.ptr)) > (*(right.ptr))); 
	//} 
	~my_ptr()
	{
		delete ptr;
	}

};

int main()
{	
	return 0;
}