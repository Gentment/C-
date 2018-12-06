#include<iostream>
#include<vector>
using namespace std;

/*
����һ���������飬ʵ��һ�����������������������ֵ�˳��
ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿�֣�
����֤������������ż����ż��֮������λ�ò��䡣
*/
//  1 2 3 4 5
//  1 3 5 2 4
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> v;
		for (size_t i = 0; i < array.size(); ++i)
		{
			if (array[i]%2==1)
			{
				v.push_back(array[i]);
			}
		}
		for (size_t i = 0; i < array.size(); ++i)
		{
			if (array[i] % 2 == 0)
			{
				v.push_back(array[i]);
			}
		}
		array.swap(v);
	}
};


class Solution1 {
public:
	int GetUglyNumber_Solution(int index) {

	}
};

#include<stack>
class Solution2 {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() != popV.size())
		{
			return false;
		}
		size_t i = 0, j = 0;
		stack<int> stack;
		while (i<pushV.size())
		{
			if (pushV[i] == popV[j])
			{
				++i;
				++j;
			}
			else if (!stack.empty() && stack.top() == popV[j])
			{
				stack.pop();
				++j;
			}
			else
			{
				stack.push(pushV[i]);
				++i;
			}
		}

		while (!stack.empty())
		{
			if (stack.top() == popV[j])
			{
				stack.pop();
				++j;
			}
			else {
				return false;
			}
		}

		return true;
	}
};
int main()
{
	//vector<int> v = { 1,2,3,4,5,6 };
	//Solution s;
	//s.reOrderArray(v);
	//for (size_t i = 0; i < v.size(); i++)
	//{
	//	cout << v[i] << endl;
	//}
	vector<int> pushV = { 1,2,3,4,5 };
	vector<int> popV = { 4,5,1,2,3 };
	Solution2 s;
	cout << s.IsPopOrder(pushV, popV) << endl;
	system("pause");
}