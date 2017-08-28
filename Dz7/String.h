#include <iostream>
#include <string.h>
class mString  {
private:
    char *pStr;
    int _size;
public:
    mString() ;
    mString(const char* str);
    mString(const mString &obj);
    ~mString();
    int size();
    mString operator + (const mString &obj) ;
	mString operator + (const char c);
	mString& operator = (const mString &obj) ;
    friend std::ostream &operator <<(std::ostream &os, mString &obj);
};
