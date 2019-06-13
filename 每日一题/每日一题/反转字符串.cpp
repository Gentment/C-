// reverse algorithm example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	//vector<int> myvector;
	//vector<int>::iterator it;

	//// set some values:
	//for (int i = 1; i < 10; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

	//reverse(myvector.begin(), myvector.end());       // 9 8 7 6 5 4 3 2 1

	//// print out content:
	//cout << "myvector contains:";
	//for (it = myvector.begin(); it != myvector.end(); ++it)
	//	cout << " " << *it;

	//cout << endl;
	string str = "abcd";
	reverse(str.begin(), str.end());
	cout << str << endl;
	return 0;
}



//int getCommonStrLength(char* pFirstStr, char* pSecondeStr) {
//	int count = 0;
//	int max = 0;
//	while (pSecondeStr != NULL)
//	{
//		if (*pFirstStr == *pSecondeStr)
//		{
//			count++;
//			*pFirstStr++;
//			*pSecondeStr++;
//		}
//		else if (count > max)
//		{
//			
//		}
//		
//	}
//}
//#include<vector>
//
//int main() {
//	string str1,str2;
//	int max = 0;
//	while(cin >> str1>>str2)
//	{
//		int len1 = str1.size();
//		int len2 = str2.size();
//		vector<vector<int>> dp(len1, vector<int>(len2, 0));
//		for (int i = 0; i < len1; i++)
//		{
//			for (int j = 0; j < len2; j++)
//			{
//				if (str1[i] == str2[j])
//				{
//					if (i >= 1 && j >= 1)
//						dp[i][j] = dp[i - 1][j - 1] + 1;
//					else
//						dp[i][j] = 1;
//				}
//
//				if (dp[i][j] > max)
//				{
//					max = dp[i][j];
//				}
//			}
//		}
//		cout << max<< endl;
//	}
//	return 0;
//}
