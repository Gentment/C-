#include"Rect.h"

using namespace std;

Rect::Rect(double x,double y)
{
	cout << "Rect::Rect" << endl;
	m_x = x;
	m_y = y;
}

Rect::~Rect()
{
	cout << "Rect::~Rect()" << endl;
}

double Rect::calcArea()
{
	cout << "Rect-->calcArea" << endl;
	return m_x * m_y;
}
