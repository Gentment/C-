//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<list>
//using namespace std;
//class Solution {
//private:
//	vector<int> vec;
//public:
//	void Insert(int num)
//	{
//		vec.push_back(num);
//	}
//
//	double GetMedian()
//	{
//		sort(vec.begin(), vec.end());
//		double value;
//		int size = vec.size();
//		if (size % 2 == 1)
//		{
//			value = (vec[size / 2] + vec[size / 2 - 1]) / 2;
//		}
//		else {
//			value = vec[size / 2];
//		}
//		return value;
//	}
//
//};
//
//#include<iostream>
//using namespace std;
//class MyClass
//{
//public:
//	MyClass(int i = 0)
//	{
//		cout << i;
//	}
//	MyClass(const MyClass &x)
//	{
//		cout << 2;
//	}
//	MyClass &operator=(const MyClass &x)
//	{
//		cout << 3;
//		return *this;
//	}
//	~MyClass()
//	{
//		cout << 4;
//	}
//};
//int main()
//{
//	MyClass obj1(1), obj2(2);
//	MyClass obj3 = obj1;
//	system("pause");
//	return 0;
//}

//
//#include<iostream>
//#include<vector>
//#include<string>
//#include<map>
//
//using namespace std;
//
//int MoreThanHalfNum_Solution(vector<int> numbers) {
//	map<int, int> map;
//
//	for (auto num : numbers)
//	{
//		if (map.count(num))
//		{
//			map[num]++;
//		}
//		else
//		{
//			map[num] = 1;
//		}
//	}
//	for (auto num : numbers)
//	{
//		if (map[num] > (numbers.size() / 2))
//		{
//			return num;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	string str;
//	while (getline(cin,str))
//	{
//		break;
//	}
//	vector<int> vec;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] != ' ')
//		{
//			vec.push_back(str[i]);
//		}
//	}
//
//	int ret = MoreThanHalfNum_Solution(vec);
//	cout << ret << endl;
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//int main(void)
//{
//	printf("%s , %5.2s\n", "computer", "computer");
//	getchar();
//	return 0;
//}


#include<iostream>
#include<stack>
#include<string>

std::string Reverser(std::string &str)
{
	std::stack<char> s;
	std::string strs = { 0 };
	for (size_t i = 0; i < str.size(); ++i)
	{
		s.push(str[i]);
	}

		std::cout << s.size() << std::endl;
	for (size_t i = 0; i < s.size(); ++i)
	{
		strs += s.top();
		s.pop();
	}
	return strs;
}
int main()
{
	std::string str;
	getline(std::cin, str);
	std::cout << str << std::endl;
	std::string ret = Reverser(str);
	std::cout << ret << std::endl;
	getchar();
	return 0;
}