//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//
//int main() {
//	string str;
//	getline(cin, str);
//	int count = 0;
//	for (size_t i = 0; i < str.size(); i++)
//	{
//		if (str[i] == ' ')
//		{
//			count++;
//		}
//		if (str[i] == '"')
//		{
//			do
//			{
//				i++;
//			} while (str[i] != '"');
//		}
//	}
//	cout << count + 1 << endl;
//	int flag = 1;
//
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] == '"')
//			flag ^= 1;
//		if (str[i]!= ' '&&str[i] != '"')
//		{
//			cout << str[i];
//		}
//
//		if (str[i] ==' '&& (!flag))
//		{
//			cout << str[i];
//		}
//		if (str[i] ==' '&&flag)
//		{
//			cout << endl;
//		}
//	}
//	cout << endl;
//	return 0;
//}

//
//#include<iostream>
//
//using namespace std;
//
//class Date
//{
//public:
//	Date(int _year,int _month,int _day)
//		:year(_year),
//		 month(_month),
//		 day(_day)
//	{
//		
//	}
//
//	~Date() {}
//
//private:
//	int year;
//	int month;
//	int day;
//};
//
//int main()
//{
//	return 0;
//}


//#include<iostream>
//using namespace std;
//bool IsYear(int year)
//{
//	return (year % 4 == 0&& year % 100 != 0) || (year % 400 == 0);
//}
//int main()
//{
//	int year, month, day;
//	int arr[12] = {31,59,90,120,151,181,212,243,273,304,334,365 };
//	int sum = 0;
//	while (cin>>year>>month>>day)
//	{
//		if (month > 12 || month < 1)
//		{
//			return -1;
//		}
//		sum += arr[month-2];
//		sum += day;
//		if (IsYear(year))
//		{
//			if (month > 2)
//			{
//				sum += 1;
//			}
//		}
//		break;
//	}
//
//	cout << sum << endl;
//	return 0;
//}

#include<stdio.h>	
int main()
{
	int i = 1;
	printf("%d %d \n", i++, ++i);
//	fun(a, b);
}

int fun(int a, int b) {

}