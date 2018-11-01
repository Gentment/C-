#include<iostream>

using namespace std;

const int SIZE = 10;
class Test
{
public:
	Test() 
	{
		register int i;
		for (i = 0; i < SIZE; i++)
		{
			arr[i] = i;
		}
	};
	int& operator[](int i)
	{
		if (i>SIZE)
		{
			cout << "索引超过下标" << endl;
			return arr[0];
		}

		return arr[i];
	}

	void PrintArr()
	{
		for (int i = 0; i < SIZE; i++)
		{
			cout << arr[i]<<" ";
		}
		cout<<endl;
	}
	~Test() {};

private:
	int arr[SIZE];
};

int main()
{
	Test t;
	cout << t[1] << endl;
}


//class Sum
//{
//public:
//	int i = 0;
//
//	int Sum_1(int n)
//	{
//		i = i + n;
//		n--;
//		return Sum_Solution(n);
//	}
//	int Sum_Solution(int n) {
//		return n==0 ? i : Sum_1(n);
//
//	}
//};
//
//int main()
//{
//	Sum s;
//	int ret = s.Sum_1(5);
//	cout << ret << endl;
//}
