//#include<iostream>
//#include<string>
//using namespace std;
//
//void CharToLow(char * pFirsStr,string &str)
//{
//	while (*pFirsStr != '\0')
//	{
//		if (*pFirsStr <'Z' && *pFirsStr > 'A')
//		{
//			str += *pFirsStr - '0';
//		}
//		else {
//			str += *pFirsStr++;
//		}
//	}
//}
//
//int getCommonStrLength(char *pFirsStr, char *pSecondStr)
//{
//	string str1,str2;
//	CharToLow(pFirsStr, str1);
//	CharToLow(pSecondStr, str2);
//	if (str1.size() < str2.size())
//	{
//		int pos = str2.find(str1);
//		int count = 0;
//		for (int i = pos; i < str2.size(); i++)
//		{
//			for (int j = 0; j < str1.size(); j++) {
//				if (str2[i] == str1[j])
//				{
//					++i; ++j;
//				}
//				else {
//
//				}
//			}
//			
//		}
//	}
//	else {
//		int pos = str1.find(str2);
//		return str1.substr(pos,).size();
//	}
//	return 0;
//}
//
//int main()
//{
//	char str1[] = { "abcdef"}, str2[] = { "abcdefgh" };
//	int ret = 0;
////	while (cin >> str1 >> str2)
//	ret = getCommonStrLength(str1, str2);
//	
//	cout << ret  << endl;
//}




#include<iostream>
#include<string>
#include<vector>
using namespace std;

int sum = 0;
int JuageMent(const string &str)
{
	for (int i = 0; i < str.size(); ++i)
	{
		int scord = 0;
		int count = 0;
		if (str[i]<9 && str[i]>0 )
		{
			count++;
		}
		else {
			count = 0;
			if (str[i] < 'a')
			{

			}
		}
	}
}
int main()
{
	string str;
	cin >> str;
}