#include "String.h"
String::String()
	{
        pStr = NULL;
        _size = 0;
    }
String::String(const char* str)  
	{
        if(str != NULL)
		{
			_size = strlen(str);
			pStr = new char[_size + 1];
			strcpy(pStr, str);  
		}
		else
		{
			pStr = NULL;
			_size = 0;
		}
    }
String::String(const String &obj) 
	{
        _size = obj._size;
        pStr = new char[_size + 1];
        strcpy(pStr, obj.pStr);
    }
String::~String()
	{
        delete []pStr;
    }
int String::size()
	{
        return _size;
    }
String String::operator + (const String &obj) 
	{
        char *temp = new char[_size + obj._size + 1];
        strcpy(temp, this->pStr);
        strcat(temp, obj.pStr);
        String result(temp);
        delete []temp;
        return result;
    }
String String::operator + (const char c)
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
        String result(temp);
        delete []temp;
        return result;
    }
void Swap(String& first, String& second)
{
	using std::swap;
	swap(first._size, second._size);
	swap(first.pStr, second.pStr);
}
String& String::operator = (String obj) 
	{
        /*if(&obj == this)
            return *this;
        delete []pStr;
        _size = obj._size;
        pStr = new char[_size + 1];
        strcpy(pStr, obj.pStr);
        return *this;*/
		Swap(*this, obj);
		return *this;
    }
std::ostream &operator << (std::ostream &os, String &obj)
	{
        for(int i = 0; i < obj.size(); i++)
            os <<obj.pStr[i];
        return os;
    }