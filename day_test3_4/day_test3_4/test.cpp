#include<iostream>
#include<string>
#include<vector>
using namespace std;

void deleteOneChar(char *str, char todelet)
{
	if (str == NULL) return;
	int len = strlen(str);
	char *p = str;
	for (int i = 0;str[i] !='\0'&& i < len; i++)
	{
		if (str[i] == todelet)
		{
			int j = 1;
			for (; str[j] != '\0'&&j < len; ++j)
				str[j] = str[j + 1];
			str[j] = '\0';
		}
	}

}

void deleteChars(char *str, const char* chars)
{
	if (str == NULL)
	{
		return;
	}
	for (int i = 0; i < strlen(str); i++)
	{
		deleteOneChar(str, chars[i]);
	}
	return;
}

int main()
{
	string str;
	string newstr;
	string del;
	vector<string> vec;
	while (cin >> str)
	{
		vec.push_back(str);
	}
	for (int i = 0; i < vec.size(); i++)
	{
		deleteChars();

	}
	cout << str << endl;
	cout << newstr << endl;
	return 0;
}