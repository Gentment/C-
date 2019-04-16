//// write your code here cpp
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string s,res;
//	while (getline(cin,s))
//	{
//		getline(cin, res);
//		bool sta = true;
//		for (int i = 0; i < s.length(); ++i)
//		{
//			string t;
//			if (s[i] == '"')
//			{
//				i++;
//				while (i < s.length() && s[i] != '"')
//				{
//					t += s[i];
//					i++;
//				}
//				if (t == res)
//				{
//					sta = true;
//					break;
//				}
//			}
//			else if (s[i] != ',')
//			{
//				while (i, s.length() && s[i] != ',')
//				{
//					t += s[i];
//					i++;
//				}
//				if (t == res)
//				{
//					sta = true;
//					break;
//				}
//			}
//		}
//		if (sta)
//			cout << "Ignore" << endl;
//		else
//			cout << "Important!" << endl;
//	}
//	return 0;
//}

#include<iostream>
#include<algorithm>
using namespace std;
int func(std::string& str, int L, int k)
{
	std::string ret;
	int count = 0;
	for (int i = 0; i < L - k; i++)
	{
		ret = str.substr(i,  k);
		std::sort(ret.begin(), ret.end());
		//判断该区间是否连续
		int n = 0;
		for (int j = 0; j < k - 1; j++)
		{
			if (ret[j+1] - ret[j] == 1) {
				n += 1;
			}
			else {
				break;
			}
		}
		if (n == k - 1) {
			count += 1;
		}
	}
	return count+1;
}
//
//int  main()
//{
//	int num = 0;
//	string str = "123456789";
////	string str = "1345321898";
//	int L = 10, K = 3;
//	cout << func(str,L,K) << endl;
//
//	return 0;
//}

#include<vector>
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		int len = data.size();
		int hashtable[256] = { 0 };
		for (int i = 0; i < len; i++)
		{
			hashtable[data[i]]++;
		}
		return hashtable[k];
	}
};



string funcstr(std::string& str, int n)
{
	string ret;
	int sum = 0;
	for (int i = 0; i < str.size(); i++)
	{
		//if (sum == n)
		//	return ret;
		
		int num = str[i] - '0';
		if (sum == n) {
			ret += str[i];
			sum += num;
		}
		else if (sum < n) {
			sum += num;
			ret += str[i];
		}else if(sum > n)
		{
			sum = 0;
			ret.clear();
		}
	}
	return ret;
}
#include<string>

int main()
{
	string str = "123456";
	string ret = funcstr(str, 9);
	cout << ret << endl;
	return 0;
}