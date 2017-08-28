#include <iostream>
#include <string.h>
class String  {
public:
    String() ;
	String(const char* str);
    String(const String &obj);
    ~String();
    int size();
    String operator + (const String &obj) ;
	String operator + (const char c);
	String& operator = (String obj) ;
   /* friend std::istream &operator >> (std::istream &is, String &obj)  {
        int ios_size = 0;
        is.sync();
        String temp;
        while(is.peek() != 10)  {
            temp = temp + (char)is.get();
            ios_size++;
        }       
        delete []obj.pStr;
        obj._size = temp._size;
        obj.pStr = new char[obj._size];
        obj = temp;
        return is;
    }*/
    friend std::ostream &operator <<(std::ostream &os, String &obj);
	friend void Swap(String& first, String& second);
private:
    char *pStr;
    int _size;
};
