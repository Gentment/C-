#if 0
#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main(void)
{
	// 使用vector存储数字：3、4、8、4
	vector<int> vec;
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(8);
	vec.push_back(4);

	//循环打印数字
	vector<int>::iterator itor ;
	for (itor = vec.begin(); itor != vec.end(); itor++)
	{
		cout << *itor << endl;
	}


	// 使用map来存储字符串键值对
	map<string, string> m;

	pair<string, string> p1("S", "Shang Hai");
	pair<string, string> p2("B", "Bei Jing");
	pair<string, string> p3("G", "Guang Zhou");

	m.insert(p1);
	m.insert(p2);
	m.insert(p3);
	// 打印map中数据
	map<string, string>::iterator it ;
	for (it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << endl;
		cout << it->second << endl;
	}
	return 0;
}


/**
 * 定义一个矩形类模板Rect
 * 成员函数：calcArea()、calePerimeter()
 * 数据成员：m_length、m_height
 */
template <class T>
class Rect
{
public:
	Rect(T length, T height);
	T calcArea();
	T calePerimeter();
public:
	T m_length;
	T m_height;
};

/**
 * 类属性赋值
 */
template <class T>
Rect<T>::Rect(T length, T height)
{
	m_length = length;
	m_height = height;
}

/**
 * 面积方法实现
 */
template <class T>
T Rect<T>::calcArea()
{
	return m_length * m_height;
}

/**
 * 周长方法实现
 */
template <class T>
T Rect<T>::calePerimeter()
{
	return (m_length + m_height) * 2;
}

int main(void)
{
	Rect<int> rect(3, 6);
	cout << rect.calcArea() << endl;
	cout << rect.calePerimeter() << endl;
	return 0;
}

#endif
