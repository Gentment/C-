//#include<iostream>
//#include<string>
//#include<vector>
//#include<deque>
//using namespace std;
//
//int main()
//{
//	int num;
//	string commond;
//	cin >> num>>commond;
//	vector<int> music(num);
//	for (int i = 1; i <= num; i++)
//	{
//		music[i] = i;
//	}
//	int curr = music[0];
//	if (num<=4)
//	{
//		for (int i = 0; i < num; i++)
//		{
//			cout << music[i];
//		}
//
//		for (int i = 0; i < commond.size(); i++)
//		{
//			if (commond[i] = 'U') {
//				curr = num - curr + 1;
//			}
//			else if(commond[i] = 'D'){
//				if (curr >=4)
//				{
//					curr = (curr + 1) % num;
//				}
//				else {
//					curr += 1;
//				}
//			}
//		}
//		cout << endl;
//		cout << curr << endl;
//	}
//	else if(num > 4){
//		for (int i = 0; i < commond.size(); i++)
//		{
//			if (commond[i] = 'U')
//			{
//				if (curr = 1)
//				{
//					for (int i = num-curr+4; i < 4; i++)
//					{
//						cout << music[i] << " ";
//						curr = num - curr + 1;
//					}
//					cout << endl;
//					cout << music[curr] << endl;
//				}
//				else {
//					for (int i = curr - 4; i < 4; i++)
//					{
//						cout << music[i] << " ";
//						if (curr > 1)
//						{
//							curr--;
//						}
//					}
//					cout << endl;
//					cout << music[curr] << endl;
//				}
//			}else if(commond[i] == 'D') {
//				if (curr == num)
//				{
//					for (int i = curr-num+1; i< 4; i++)
//					{
//						cout << music[i] << " ";
//					}
//					curr = (curr + 1) % num;
//					cout << endl;
//					cout << music[curr] << endl;
//				}
//				else {
//					for (int i = curr; i < 4; i++)
//					{
//						cout << music[i] << " ";
//						if (curr <num)
//						{
//							curr++;
//						}
//					}
//					cout << endl;
//					cout << music[curr] << endl;
//				}
//			}
//		
//		}
//		////光标不在第一首和最后一首时
//		//if (curr != 1 && curr != num)
//		//{
//		//	for (int i = curr; i < curr+4; i++)
//		//	{
//		//		cout << music[i]<<" ";
//		//	}
//		//	cout << endl;
//		//	cout << music[curr] << endl;
//		//}
//	}
//	return 0;
//}


//#include<iostream>
//
//#include<string>
//using namespace std;
//int main()
//{
//	string str;
//	getline(cin, str);
//	//cin >> str;
//	int hashtable[256] = { 0 };
//	for (int i = 0; i < str.size(); i++)
//	{
//		hashtable[str[i]]++;
//	}
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (hashtable[str[i]] == 1)
//			cout<<str[i]<<endl;
//	}
//	return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string str1, str2;
//	cin >> str1 >> str2;
//	
//	int count = 0;
//	for (int i = 0; i < str1.size(); i++)
//	{
//		for (int j = 0; j < str2.size(); j++)
//		{
//			if (str1[i] == str2[j]) {
//				count++;
//			}
//			else if (str1[i] == str2[j+1] || str1[i] == str2[j-1])
//			{
//				count++;
//			}
//		}
//	}
//	cout << count << endl;
//	return 0;
////}
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;

//
//class Gift {
//public:
//	int getValue(vector<int> gifts, int n) {
//		// write code here
//		sort(gifts.begin(), gifts.end());
//		int ret = count(gifts.begin(), gifts.end(), gifts[n / 2]);
//		if (ret > n / 2)
//		{
//			return gifts[ret];
//		}
//		return 0;
//	}
//};

//
//class Gift {
//public:
//	int getValue(vector<int> gifts, int n) {
//		// write code here
//		int gift = gifts[0];
//		int count = 0;
//		for (int i = 1; i < n; ++i)
//		{
//			if (gifts[i] == gift) {
//				count++;
//			}
//			else {
//				count--;
//			}
//			if (count == 0)
//			{
//				gift = gifts[i];
//				count = 1;
//			}
//		}
//		count = 0;
//		for (int i = 0; i < n; i++)
//		{
//			if (gifts[i] == gift) {
//				count++;
//			}
//		}
//		if (count > n / 2)
//			return gift;
//		return 0;
//	}
//};


//class Gift {
//public:
//	int getValue(vector<int> gifts, int n) {
//		// write code here
//		int hashtable[256] = { 0 };
//
//		for (int i = 0; i < gifts.size(); i++)
//		{
//			hashtable[gifts[i]]++;
//		}
//
//		for (int i = 0; i < 256; i++)
//		{
//			if (hashtable[i] > (n / 2))
//			{
//				return gifts[i];
//			}
//		}
//
//		return 0;
//	}
//};

//int main()
//{
//	vector<int> v = { 1,2,3,2,2};
//
//	Gift g;
//	cout<<g.getValue(v, 5)<<endl;
//}

#define _CRT_SECURE_NO_WARNINGS 0
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void GetMemory(char *p)
{
	p = (char *)malloc(100);
}
void Test(void)
{
	char *str = NULL;
	GetMemory(str);
	strcpy(str, "hello world");
	printf(str);
}

int main()
{
	Test();
}