#include<iostream>
#include<stdlib.h>
using namespace std;

template <class T>
class Stack {
private:
	vector<T> elems;
public:
	void push(T const&);
	void pop();
	T top() const;
	bool empty() const
	{
		return elems.empty();
	}
};

template <class T>
void Stack<T>::push(T const& elem)
{
	elems.push_back(elem);
}

template <class T>
void Stack<T>::pop()
{
	if (elems.empyt())
	{
		throw out_of_range("stack is empty");
	}
	elems.pop_back();
}

template <class T>
T Stack<T>::top()const
{
	if (elems.empyt())
	{
		throw out_of_range("stack is empty");
	}
	return elem.back();
}

int main()
{
	Stack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);

	while (!stack.empty)
	{
		cout << stack.top() << endl;
	}

}
/**
 * 定义模板函数swapNum
 * 实现功能：交换两个数的位置
 */
//template <typename T>
//void swapNum(T &a, T &b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//int main(void)
//{
//	int x = 10;
//	int y = 20;
//	// 调用模板函数
//	swapNum<int>(x, y);
//	cout << "x = " << x << endl;
//	cout << "y = " << y << endl;
//	return 0;
//}

//
//
//template <typename T>
//void display(T a)
//{
//	cout << a << endl;
//}
//
//template <typename T, class S>
//void display(T t, S s)
//{
//	cout << t << endl;
//	cout << s << endl;
//}
//
//template <typename T,int size>
//void display(T t)
//{
//	for (int i = 0; i < size; i++)
//	{
//		cout << t << endl;
//	}
//}
//
//int main()
//{
//	int a = 10;
//	display<int>(10);
//
//	display<int, double>(2, 2.3);
//
//	display<int, 5>(6);
//	return 0;
//}

//template <typename T>
//inline T const& Max(T const& a, T const& b)
//{
//	return a > b ? a : b;
//}
//
//int main()
//{
//	int a = 30;
//	int b = 31;
//	cout << Max(a, b) << endl;
//
//	double i = 2.3;
//	double j = 3.3;
//	cout << Max(i,j) << endl;
//
//	char m = 'A';
//	char n = 'B';
//	cout << Max(m, n) << endl;
//
//}