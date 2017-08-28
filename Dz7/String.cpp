#include "String.h"
mString::mString()
	{
        pStr = NULL;
        _size = 0;
    }
mString::mString(const char* str)  
	{
        _size = strlen(str);
        pStr = new char[_size + 1];
        strcpy(pStr, str);  
    }
mString::mString(const mString &obj) 
	{
        _size = obj._size;
        pStr = new char[_size + 1];
        strcpy(pStr, obj.pStr);
    }
mString::~mString()
	{
        delete []pStr;
    }
int mString::size()
	{
        return _size;
    }
mString mString::operator + (const mString &obj) 
	{
        char *temp = new char[_size + obj._size + 1];
        strcpy(temp, this->pStr);
        strcat(temp, obj.pStr);
        mString result(temp);
        delete []temp;
        return result;
	}
mString mString::operator + (const char c)
	{
        int t_size;
        if(_size != 0)
            t_size = this->_size + 2;
        else
            t_size = 2;
        char *temp = new char[t_size];
        if(pStr)
            strcpy(temp, this->pStr);
        temp[t_size - 2] = c;
        temp[t_size - 1] = '\0';
        mString result(temp);
        delete []temp;
        return result;
    }
mString& mString::operator = (const mString &obj) 
	{
        if(&obj == this)
            return *this;
        delete []pStr;
        _size = obj._size;
        pStr = new char[_size + 1];
        strcpy(pStr, obj.pStr);
        return *this;
    }
std::ostream &operator << (std::ostream &os, mString &obj)
	{
        for(int i = 0; i < obj.size(); i++)
            os <<obj.pStr[i];
        return os;
    }
