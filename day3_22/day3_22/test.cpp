//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n,m;
//	while (cin >> n)
//	{
//		m = 2 * n - 1;
//		vector<vector<int>> dp(n, vector<int>(m, 0));
//		dp[0][0] = 1;
//		for (int i = 0; i < n; i++)
//		{
//			dp[i][0] = dp[i][i * 2] = 1;
//			for (int j = 0; j < 2 * i; j++)
//			{
//				if (j == 1)
//				{
//					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
//				}
//				else
//				{
//					dp[i][j] = dp[i - 1][j - 2] + dp[i - 1][j - 1] + dp[i - 1][j];
//				}
//			}
//		}
//
//		int k;
//		for (k = 0; k < m; k++)
//		{
//			if (dp[n - 1][k] % 2 == 0 && dp[n - 1][k] != 0)
//			{
//				cout << k + 1 << endl;
//				break;
//			}
//		}
//		if (k == m)
//			cout << -1 << endl;
//	}
//	return 0;
//}
//
//#include<iostream>
//#include<algorithm>
//#include<string>
//using namespace std;
//
//string AddLongInteger(string str1,string str2)
//{
//	int n = str1.size();
//	int m = str2.size();
//	string result;
//	int carry = 0;
//	while (m>=0 ||n>= 0)
//	{
//		if (n > 0) {
//			carry += str1[n] - '0';
//		}
//		if (m > 0) {
//			carry += str1[m] - '0';
//		}
//
//		result += (carry % 10 + '0');
//		carry /= 10;
//
//		n--;
//		m--;
//	}
//	if (carry == 1)
//	{
//		result += '1';
//	}
//	reverse(result.begin(), result.end());
//	return result;
//}
//
//int main()
//{
//	string str1="10000", str2="99999";
//	AddLongInteger(str1, str2);
//
//	//while (cin>>str1>>str2)
//	//{
//	//	AddLongInteger(str1,str2);
//
//	//}
//	return 0;
//}


#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string AddLongInteger(string &str1, string &str2)
{
	int n = str1.size() - 1;
	int m = str2.size() - 1;
	string result = "";
	int carry = 0;
	while (n >= 0 || m >= 0)
	{
		if (n >= 0) {
			carry += str1[n] - '0';
		}
		if (m >= 0) {
			carry += str2[m] - '0';
		}

		result += (char)(carry % 10 + '0');
		carry /= 10;

		n--;
		m--;
	}
	if (carry == 1)
	{
		result += '1';
	}
	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		cout << AddLongInteger(str1, str2) << endl;

	}
	return 0;
}