#pragma once
#include"Shape.h"

class Rect:public Shape
{
public:
	Rect(double x,double y);
	~Rect();
	virtual double calcArea();
protected:
	double m_x;
	double m_y;

};

