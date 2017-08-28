#include "iostream"
namespace my_book
{
	class Book
	{
	public:
		Book(const char* aut = "None", const char* nme = "None", const char* pub = "None", const int y = 2000, const int pnum = 0 );
		Book(const Book&);
		~Book();
		void setallparams(const char* nme = "None", const char* aut = "None", const char* pub = "None", const int y = 2000, const int pnum = 0 );
		char* getName();
		char* getAuthor();
		char* getPubl();
		int getYear();
		int getPcount();
		friend std::ostream& operator << (std::ostream& os, Book& b);
	private:
		char* author = nullptr;
		char* name = nullptr;
		char* publ = nullptr;
		int year;
		int pcount;
		bool setParam(const char* src,char** dest);
		void setparams(const char* nme = "None", const char* aut = "None", const char* pub = "None");

	};

}
