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
#endif // 0


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