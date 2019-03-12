//#include<iostream>
//#include<stack>
//
//using namespace std;
//
//
//class Parenthesis {
//public:
//	bool chkParenthesis(string A, int n) {
//		// write code here
//		stack<char> s;
//		bool flag = true;
//		if (n % 2 == 1)
//		{
//			flag = false;
//		}
//		for (int i = 0; i < A.size(); i++)
//		{
//			if (A[i] == '(')
//			{
//				s.push(A[i]);
//			}
//			else if(!s.empty() && A[i] == ')'){
//				s.pop();
//			}else {
//				flag = false;
//			}
//		}
//		return flag;
//	}
//};
//
//int main()
//{
//	Parenthesis p;
//	string A = "(()()())";
//	cout << p.chkParenthesis(A, 8) << endl;
//	return 0;
//}

//
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int  main()
//{
//	int a=0, b=1, c=1,leftstep = 0,rightstep = 0 ;
//	int n;
//	cin >> n;
//
//	while (true)
//	{
//		a = b;
//		b = c;
//		c = a + b;
//		if (c<n)
//		{
//			leftstep = n - c;
//		}
//		else
//		{
//			rightstep = c - n;
//			break;
//		}
//	}
//	cout << min(leftstep,rightstep) << endl;
//	return 0;
//}


#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int num = 0;
	cin >> num;
	vector<int> vec(num);
	for (size_t i = 0; i < num; i++)
	{
		cin>>vec[i];
	}
	int sum = 0;
	int result = vec[0];
	for (size_t i = 0; i < vec.size(); i++)
	{
		sum += vec[i];
		if (sum > result)
		{
			result = sum;
		}
		if (sum <0)
		{
			sum = 0;
		}
		
	}
	cout << result << endl;
	return 0;
}


//#include<iostream>
//#include<queue>
//#include<vector>
//
//using namespace std;
//
//class Solution {
//public:
//	priority_queue<int,vector<int>, less<int> > p;
//	priority_queue<int,vector<int>, greater<int> > q;
//	
//	void Insert(int num)
//	{
//		if (p.empty() || num <= p.top())
//			p.push(num);
//		else
//			q.push(num);
//		if (p.size() == q.size() + 2)
//		{
//			q.push(p.top()),
//			p.pop();
//		}
//		if (p.size() + 1 == q.size())
//		{
//			p.push(q.top()),
//			q.pop();
//		}
//	}
//
//	double GetMedian()
//	{
//		return p.size() == q.size() ? (p.top + q.top()) / 2.0 : p.top();
//	}
//
//};