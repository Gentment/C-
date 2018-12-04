#include<iostream>
#include<stack>
using namespace std;

//template<class T>
class Solution
{
public:
	void push(int node) 
	{
		stack1.push(node);
	}

	int pop() 
	{
		if (!stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
			stack2.pop();
		}
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main()
{
	Solution s;
	s.push(1);

	s.push(2);
	return 0;
}