#if 0
#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main(void)
{
	// ʹ��vector�洢���֣�3��4��8��4
	vector<int> vec;
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(8);
	vec.push_back(4);

	//ѭ����ӡ����
	vector<int>::iterator itor ;
	for (itor = vec.begin(); itor != vec.end(); itor++)
	{
		cout << *itor << endl;
	}


	// ʹ��map���洢�ַ�����ֵ��
	map<string, string> m;

	pair<string, string> p1("S", "Shang Hai");
	pair<string, string> p2("B", "Bei Jing");
	pair<string, string> p3("G", "Guang Zhou");

	m.insert(p1);
	m.insert(p2);
	m.insert(p3);
	// ��ӡmap������
	map<string, string>::iterator it ;
	for (it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << endl;
		cout << it->second << endl;
	}
	return 0;
}


/**
 * ����һ��������ģ��Rect
 * ��Ա������calcArea()��calePerimeter()
 * ���ݳ�Ա��m_length��m_height
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
 * �����Ը�ֵ
 */
template <class T>
Rect<T>::Rect(T length, T height)
{
	m_length = length;
	m_height = height;
}

/**
 * �������ʵ��
 */
template <class T>
T Rect<T>::calcArea()
{
	return m_length * m_height;
}

/**
 * �ܳ�����ʵ��
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
