#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	int hashtable[256] = { 0 };
	for (int i = 0; i < str2.size(); i++)
	{
		hashtable[str2[i]]++;
	}

	string ret;
	for (int i = 0; i < str1.size(); i++)
	{
		if (hashtable[str1[i]] == 0)
		{
			ret += str1[i];
		}
	}
	cout << ret << endl;
	return 0;
}