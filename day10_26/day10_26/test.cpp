#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1) { };
	Date(const Date& date);
	Date& operator=(const Date& date);
	Date operator+(int days);
	Date operator-(int days);
	int operator-(const Date& date);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	bool operator>(const Date& date)const;
	bool operator>=(const Date& date)const;
	bool operator<(const Date& date)const;
	bool operator<=(const Date& date)const;
	bool operator==(const Date& date)const;
	bool operator!=(const Date& date)const;

	~Date();
	//void setDate(int year, int month, int day);
	//Date& getDate(const Date& date);
	//void display(Date& date);
private:
	int _year;
	int _month;
	int _day;
};


Date::~Date()
{
	cout << "delete ~Date" << endl;
}
//Date::Date(int year = 1900, int month = 1, int day = 1)
//{}

Date::Date(const Date& date)
{
	_year = date._year;
	_month = date._month;
	_day = date._day;	
}


//赋值运算符，需要给出返回值，特例a=b=c，还需要注意自身赋值
Date& Date::operator=(const Date& date)
{
	if (this != &date)
	{
		this->_year = date._year;
		this->_month = date._month;
		this->_day = date._day;
	}
	return *this;
}

Date Date::operator+(int days)
{
	if (_day <= 31)
	{
		this->_day += days;
	}
	return *this;
}

Date Date::operator-(int days)
{
	if (_day>0)
	{
		this->_day -= days;
	}
	return *this;
}

int Date::operator-(const Date& date)
{
	this->_year -= date._year;
	this->_month -= date._month;
	this->_day -= date._day;
	
	return 0;
}
Date& Date::operator++()
{
	this->_year++;
	this->_month++;
	this->_day++;
	return *this;
}

Date Date::operator++(int)
{
	Date temp = (*this);
	_year++;
	_month++;
	_day++;
	return temp;
}
Date& Date::operator--()
{
	this->_year--;
	this->_month--;
	this->_day--;
	return *this;
}
Date Date::operator--(int)
{
	Date temp = (*this);
	this->_year--;
	this->_month--;
	this->_day--;
	return temp;
}
bool Date::operator>(const Date& date)const
{
	//2018.10.28  vs  2018.10.29
	if (_year > date._year && _month  > date._month && _day > date._day)
	{
		return true;
	}
	return false;
}
bool Date::operator>=(const Date& date)const
{
	if (_year >= date._year &&_month >= date._month && _day >= date._day)
	{
		return true;
	}
	return false;
}
bool Date::operator<(const Date& date)const
{
	if (_year < date._year && _month < date._month && _day < date._day)
	{
		return true;
	}
	return false;
}
bool Date::operator<=(const Date& date)const
{
	if (_year <= date._year &&_month <= date._month && _day <= date._day)
	{
		return true;
	}
	return false;
}
bool Date::operator==(const Date& date)const
{
	if (_year == date._year && _month == date._month && _day == date._day)
	{
		return true;
	}	
	return false;
}
bool Date::operator!=(const Date& date)const
{
	if (*this == date)
	{
		return false;
	}
	return true;
}


int main()
{
	Date date1(2018,10,31);
	Date date2(2018, 10, 30);
	cout << "123" << endl;
	date1++;
	if (date2 == date1)
	{
		cout << "date1 > date2" << endl;
	}
	else
	{
		cout << "date1 > date2" << endl;
	}
	return 0;
}

#if 0
void Date::display(Date& date)
{
	cout << date._year << "年" << date._month << "月" << date._day << "日" << endl;
}
void Date::setDate(int year, int month, int day)
{
	if (year>1970||year<2018 && month<=12||month>0 && day>0||day<=31)
	{
		_year = year;
		_month = month;
		_day = day;
	}
}
Date& Date::getDate(const Date& date)
{
	return *this;
}

/*
int main()
{
	Date d1;
	d1.setDate(1997,10,26);
	Date d2;

	d1.display(d1);
	d2 = d1.getDate(d1);
	d2.display(d2);
	return 0;
	const int debugLevel = 10;
	int logLevel = 10;

	const int *p;
	int *q;

	p = &logLevel;
	q = (int*)&debugLevel;

	*q = 5;
	*p = 5;
	return 0;
	system("puase");
}*/

#endif // 0

