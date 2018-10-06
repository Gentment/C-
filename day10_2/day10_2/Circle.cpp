#include"Circle.h"

using namespace std;

Circle::Circle(double r)
{
	cout << "Circle::Circle(double r)" << endl;
	m_r = r;
}

Circle::~Circle()
{
	cout << "Circle::~Circle()" << endl;
}

double Circle::calcArea()
{
	cout << "Circle-->calc Area" << endl;

	return 3.14*m_r*m_r;
}