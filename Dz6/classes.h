#ifndef _CLASSES_H_
#define _CLASSES_H_
struct point
{
	double x;
	double y;
};

class Polygon 
{
public:
	Polygon(int pcol);
	virtual ~Polygon();
	void setPoints();

	double perimeter();
	void pointsInfo();
	virtual void type();
	double area();
protected:
	point* p;
	int pnum;
	double* sides;
	void sideCal();
};

class Triangle: public Polygon
{
public:
	Triangle(): Polygon(3){};
	void type(); 
	void medians();
	void mediansPoint();
	void bissektr();
	void bissPoint();
	void heighPoint();
};

class Square: public Polygon
{
public:
	Square();
	void type();
	void showDiags();
private:
	double diag1;
	double diag2;
	void diags();
};
#endif //_CLASSES_H_
