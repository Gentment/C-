/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<vector>
using namespace std;
//template<class T>
class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> v;
		if (size == 0) return v;
		size_t index = size;
		while (index <= num.size())
		{
			int max = num[index-size];
			for (size_t i = index - size+1; i < index; ++i)
			{
				if (max < num[i])
				{
					max = num[i];
				}
			}
			index++;
			v.push_back(max);
		}
		return v;
	}
};

#include<deque>
class Solution2 {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> res;
		deque<int> q;
		for (int i = 0; i < nums.size(); ++i) {
			if (!q.empty() && q.front() == i - k) q.pop_front();
			while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
			q.push_back(i);
			if (i >= k - 1) res.push_back(nums[q.front()]);
		}
		return res;
	}
};


int main()
{
	vector<int> v = { 2,3,4,2,6,2,5,1 };
	Solution2 s;
	vector<int> ret = s.maxSlidingWindow(v, 0);
	for (size_t i = 0; i < ret.size(); ++i)
	{
		cout << ret[i] << endl;
	}
	system("pause");
	return 0;
}
