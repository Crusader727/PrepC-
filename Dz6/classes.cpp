#include "classes.h"
#include <cmath>
#include <iostream>

Polygon::Polygon(int pcol)
	{
		pnum = pcol;
		p = new point[pnum];
		/*for(int i = 0; i < pnum; i++)
		{
			p[i].y = arr[i].y;
			p[i].x = arr[i].x;
		}*/
		sides = new double[pnum];
		setPoints();
		sideCal();
	}
Polygon::~Polygon()
	{
		if (p != NULL)
			delete[] p;
		if (sides != NULL)
			delete[] sides;
	}
void Polygon::setPoints()
	{
		for(int i = 0; i < pnum;  i++)
		{
			std::cout << "Enter point(X,Y) #" << i+1 << ": ";
			std::cin >> p[i].x >> p[i].y;
		}
	}
void Polygon::sideCal()
	{
		for(int i = 0; i < pnum - 1; i++)
			sides[i] = sqrt((p[i].x - p[i+1].x) * (p[i].x - p[i+1].x) + (p[i].y - p[i+1].y) * (p[i].y - p[i+1].y));
		sides[pnum - 1] = sqrt((p[pnum-1].x - p[0].x) * (p[pnum-1].x - p[0].x) + (p[pnum-1].y - p[0].y) * (p[pnum-1].y - p[0].y));
	}
double Polygon::perimeter()
	{
		double perim = 0;
		for(int i = 0; i < pnum; i++)
			perim += sides[i];
		return std::abs(perim);
	}
void Polygon::pointsInfo()
	{
		for(int i = 0; i < pnum; i++)
			std::cout << "Point #" << i+1 << " X:" << p[i].x << " Y:" << p[i].y << std::endl;
	}
void Polygon::type()
	{
		std::cout << "Polygon" << std::endl;
	}
double Polygon::area()
	{
		double buf1 = 0;
		double buf2 = 0;
		for(int i = 0; i < pnum - 1; i++)
		{
			buf1 += p[i].x * p[i+1].y;
			buf2 += p[i].y * p[i+1].x;
		}
		buf1 += p[pnum-1].x * p[0].y;
		buf2 += p[pnum-1].y * p[0].x;
		double area =(buf1 - buf2) / 2;
		return area;
	}

//Triangle//
void Triangle::type()
	{
		std::cout << "Triangle" << std::endl;
	}

void Triangle::medians()
	{
		double med1;
		double med2;
		double med3;
		med1 = (sqrt(2*sides[0]*sides[0] + 2*sides[1]*sides[1] - sides[2]*sides[2])) / 2;
		med2 = (sqrt(2*sides[0]*sides[0] + 2*sides[2]*sides[2] - sides[1]*sides[1])) / 2;
		med3 = (sqrt(2*sides[1]*sides[1] + 2*sides[2]*sides[2] - sides[0]*sides[0])) / 2;
		std::cout << "Medians: " << med1 << " " << med2 << " " << med3 << std::endl;
	}
void Triangle::mediansPoint()
	{
		point c;
		c.x = (p[0].x + p[1].x + p[2].x) / 3;
		c.y = (p[0].y + p[1].y + p[2].y) / 3;
		point c = (p[0] + p[1]) / 3;
		std::cout << "Medians point:" << "X = " << c.x << " Y = " << c.y << std::endl;
	}
void Triangle::bissektr()
	{
		double p = perimeter() / 2;
		double biss1;
		double biss2;
		double biss3;
		biss1 =(2 * sqrt(sides[0] * sides[1] * p * (p - sides[2]))) / (sides[0] + sides[1]);
		biss2 =(2 * sqrt(sides[2] * sides[1] * p * (p - sides[0]))) / (sides[2] + sides[1]);
		biss3 =(2 * sqrt(sides[0] * sides[2] * p * (p - sides[1]))) / (sides[0] + sides[2]);
		std::cout << "Bissiktrs: " << biss1 << " " << biss2 << " " << biss3 << std::endl;
	}
void Triangle::bissPoint()
	{
		point c;
		c.x = (p[0].x * sides[1] + p[1].x * sides[2] + p[2].x * sides[0]) / 
				(sides[0] + sides[1] + sides[2]);
		c.y = (p[0].y * sides[1] + p[1].y * sides[2] + p[2].y * sides[0]) / 
				(sides[0] + sides[1] + sides[2]);
		std::cout << "Bissiktiss point:" << "X = " << c.x << " Y = " << c.y << std::endl;
	}
void Triangle::heighPoint()
	{
		point c;
		double zn = p[0].x*p[1].y + p[1].x*p[2].y + p[0].y*p[2].x - p[2].x*p[1].y - p[1].x*p[0].y - p[2].y*p[0].x;
		c.x = 0;
		c.x = p[2].x*p[0].x*p[0].y + p[0].y*p[1].y*p[1].y + p[2].y*p[1].x*p[2].x + p[0].y*p[0].y*p[2].y + p[1].y*p[0].x*p[1].x + 
				p[1].y*p[2].y*p[2].y - p[2].y*p[2].x*p[0].x - p[1].y*p[1].y*p[2].y - p[0].y*p[0].x*p[1].x - p[0].y*p[2].y*p[2].y - 
					p[1].y*p[1].x*p[2].x - p[0].y*p[0].y*p[1].y;
		c.x /= zn;
		c.y = 0; // доделать Y
		c.y = p[1].x*(p[0].x*p[0].x+p[1].y*p[2].y) + p[0].x*(p[2].x*p[2].x+p[0].y*p[1].y) + p[2].x*(p[1].x*p[1].x+p[2].y*p[0].y) - 
				p[1].x*(p[2].x*p[2].x+p[0].y*p[1].y) - p[2].x*(p[0].x*p[0].x +p[1].y*p[2].y) - p[0].x*(p[1].x*p[1].x+p[2].y*p[0].y);
		c.y /= zn;
		std::cout << "Heighs point:" << "X = " << c.x << " Y = " << c.y << std::endl;
	}
//Square
void Square::type()
	{
		std::cout << "Square" << std::endl;
	}
Square::Square(): Polygon(4)
	{
		diags();
	}
void Square::diags()
	{
		diag1 = sqrt((sides[0] * sides[0]) + (sides[1] * sides[1]));
		diag2 = sqrt((sides[2] * sides[2]) + (sides[3] * sides[3]));
	}
void Square::showDiags()
	{
		std::cout << "Diags: " << diag1 << " " << diag2 <<  std::endl;
	}
