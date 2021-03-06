#include"pch.h"
#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> sta;
		char ch;
		char leftBracket;
		for (int i = 0; i < s.size(); i++)
		{
			ch = s[i];
			switch (ch)
			{
			case'(':
			case'[':
			case'{':
				sta.push(ch);
				break;
			case')':
			case']':
			case'}':
				if (sta.empty())
				{
					return false;
				}
				leftBracket = sta.top();
				sta.pop();
				if (leftBracket == '('&&ch != ')')
					return false;
				if (leftBracket == '['&&ch != ']')
					return false;
				if (leftBracket == '{'&&ch != '}')
					return false;
			default:
				return false;
			}
			if (!sta.empty())
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	Solution s;
	string ss = { '(',')' };
	cout << s.isValid(ss) << endl;
}