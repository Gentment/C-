#include<iostream>

using namespace std;

#if 0


template<int N>
struct Sum
{
	const static int value;
};

template<int N>
const int Sum<N>::value = Sum<N - 1>::value + N;

template<>
struct Sum<0>
{
	const static int value;
};

const int Sum<0>::value = 0;


int main()
{
	cout << Sum<100>::value << endl;
}



#include<list>

int main()
{
	list<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	
	for (size_t i = 0; i < l.size(); ++i)
	{
		printf("%d ",l.front());
	}


	for(auto e:l)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}

#endif // 0

#include<deque>

class Data
{
public:
	Data(int year = 1990, int month = 1,int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	friend ostream& operator<<(ostream& _cout,Data& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}
	~Data() {};

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	deque<Data> d;

	Data d1(2018,11,26);
	Data d2(2018,11,25);
	Data d3(2018,11,24);
	Data d4(2018,11,23);
	d.push_back(d1);
	d.push_back(d2);
	d.push_back(d3);
	d.push_back(d4);

	for (deque<Data>::iterator it = d.begin(); it != d.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}