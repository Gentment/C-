//#include<iostream>
//#include<vector>
//#include<string>
//
//using namespace std;
//
//int main()
//{
//	string str;
//	getline(cin, str);
//	int count = 0;
//	for (size_t i = 0; i < str.size(); i++)
//	{
//		if (str[i] == '\t'||str[i] == '!' || str[i] == ' ' || str[i] == '.' || str[i] == '?' || str[i] == ',' || str[i] == '\n' || str[i] == '\"')
//		{
//			cout << str[i] << " ";
//			count++;
//		}
//	}
//
//	cout << count << endl;
//	return 0;
//}
/*
#include<stdio.h>
#include<stdlib.h>
#define N 1000
int main() {
	char en[N][81];
	int i, j, num = 0, n, state;
	//num 用来统计单词的个数
	//state 用来记录程序当前是否处于一个单词之中，初值为0，表示不在单词中，值为1，表示正处于在一个单词中

	printf("Please input the number of lines for English passage:");
	scanf("%d", &n);  //输入英语短文的行数
	getchar();   //吸收回车符

	for (i = 0; i < n; i++) {
		gets(en[i]);   //输入英语短文
	}
	for (i = 0; i < n; i++) {
		state = 0;  //设每行的开始都是单词的开始
		for (j = 0; en[i][j] != '\0'; j++) {
			if (en[i][j] == ' ') {
				state = 0;   //判断 en[i][j] 是否为空格字符
			}
			else if (state == 0) {
				state = 1;
				num++;
			}
		}
	}
	printf("The number of words is %d\n", num);
}

*/
//
//#include<iostream>
//#include<vector>
//using namespace std;
//void Sex(vector<char> &vec,string &str)
//{
//	for (int i = 0; i < vec.size(); i++)
//	{
//		for (int j = 0; j < str.size(); ++j)
//		{
//
//		}
//	}
//}
//
//int main()
//{
//	vector<char> vec;
//	for (int i = 0; i < 36; i++)
//	{
//		cin >> vec[i];
//	}
//	int moude;
//	
//	cin >> moude;
//
//
//
//	if (moude == 1)
//	{
//		Sex(vec);
//	}
//	else if (moude == 0)
//	{
//
//	}
//}
//
//
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//bool IsRevo(const string &str)
//{
//	bool falg = true;
//	auto start = str.begin();
//	auto end = str.end();
//	while (*start == *end && start > end)
//	{
//		start++;
//		end--;
//	}
//
//	if (start >= end)
//	{
//		falg = true;
//	}
//	else {
//		falg = false;
//	}
//	return falg;
//}
//
//int main()
//{
//	string str;
//	cin >> str;
//	string ch;
//	cin >> ch;
//	int count = 0;
//	auto it = str.begin();
//	for (int i = 0; i < str.size(); i++)
//	{
//		string newstr = str.insert(i, ch);
//		if (IsRevo(newstr))
//		{
//			count++;
//		}
//	}
//	return 0;
//}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) {
	if (array.size() <= 0) return 0;
	int sum = 0;
	int GreatestSum = 0x80000000;
	for (int i = 0; i < array.size(); ++i)
	{
		if (sum <= 0)
		{
			sum = array[i];
		}
		else {
			sum += array[i];
		}
		if (sum > GreatestSum)
		{
			GreatestSum = sum;
		}
	}
	return GreatestSum;
}

int main()
{
	int n;
	vector<int> vec;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	cout << FindGreatestSumOfSubArray(vec) << endl;
	
	return 0;
}
