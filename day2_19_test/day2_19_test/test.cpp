//#include<iostream>
//#include<vector>
//using namespace std;
//
//vector<int> Fib(int num,int n=1)
//{
//	vector<int> vec;
//	if (n > num)
//	{
//		return vec;
//	}
//	int a = 1;
//	int b = 1;
//	int c = 0;
//	while (n<num)
//	{
//		a = b;
//		b = c;
//		c = a + b;
//		vec.push_back(c);
//	}
//	return vec;
//}
//
//int Fibonacci(int num,vector<int> vec)
//{
//	int count = 1;
//	if (num < 2) return 1;
//	for (size_t i = 0; i < vec.size(); i++)
//	{
//		if (num == vec.front())
//		{
//			return count;
//		}
//		else if(num-- == vec.front()){
//			count++;
//			return count;
//		}
//		else if(num++ == vec.front()) {
//			count++;
//			return count;
//		}
//	}
//	return count;
//}
//
//
//int main()
//{
//	int num;
//	cin >> num;
//	vector<int> vec = Fib(num, 1);
//	int ret = Fibonacci(num,vec);
//	cout << ret << endl;
//}

//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int num;
//	int sum;
//	cin >> num;
//	
//	vector<int> vec;
//	while (num--)
//	{
//		int a = 0;
//		cin >> a;
//		vec.push_back(a);
//	}
//	for (int i = 0; i < vec.size(); ++i)
//	{
//		sum += vec[i];
//	}
//
//	for (int i = 0; i < vec.size(); ++i)
//	{
//		if (vec[i] > sum / num) vec[i] -= 1;
//	}
//	return 0;
//}


//#include<iostream>
//#include<algorithm>
//#include<string>
//const int  maxn = 30;
//using namespace std;
//string str1,str2;
//int len1, len2;
//
//int dp[maxn][maxn];
//
//int solve()
//{
//	for (int i = 1; i <= len1; i++)
//	{
//		for (int j = 1; j < len2; j++)
//		{
//			if (str1[i - 1] == str2[j - 1]) {
//				dp[i][j] = dp[i - 1][j-1];
//			}
//			else
//			{
//				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
//			}
//		}
//	}
//	return dp[len1][len2];
//}
//int main()
//{
//	string str;
//	cin >> str;
//	len1 = str.length();
//	cout << str << endl;
//}

//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution {
//public:
//	int FindGreatestSumOfSubArray(vector<int> array) {
//		vector<int> vec;
//		int sum = 0;
//		for (size_t i = 0; i < array.size()-1; i++)
//		{
//			if (array[i] > 0)
//			{
//				if (array[0] < 0) i++;
//				sum += array[i];
//				vec.push_back(sum + array[i + 1]);
//			}
//		}
//		for (int i = 0; i < vec.size(); ++i)
//		{
//			cout << vec[i] << " ";
//		}
//		cout << endl;
//		sort(vec.begin(), vec.end());
//		for (int i = 0; i < vec.size(); ++i)
//		{
//			cout << vec[i] << " ";
//		}
//		cout << endl;
//		return vec.back();
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<int> vec = { 2,3,5,4,-7 };
//	int ret = s.FindGreatestSumOfSubArray(vec);
//	cout << ret << endl;
//}

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
using namespace std;

//class Solution {
//public:
//	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//		priority_queue<int,vector<int>,greater<int>> queue;
//		for (auto &num :input)
//		{
//			queue.push(num);
//		}
//		vector<int> vec;
//		for (int i = 0; i < k; ++i)
//		{
//			vec.push_back(queue.top());
//			queue.pop();
//		}
//		return vec;
//	}
//};

/*
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		unordered_map<int,int> map;
		unordered_set<int> set;
		for (auto num : numbers) set.insert(num);
		for (auto num:numbers)
		{
			if (map.count(num))
			{
				map[num]++;
			}
			else
			{
				map[num] = 1;
			}
		}
		for (auto num : numbers)
		{
			if (map[num]>(numbers.size() / 2))
			{
				return num;
			}
		}
		return 0;
	}
};
*/

class Solution {
public:
	vector<string> Permutation(string str) {

	}
};
int main()
{
	Solution s;
	//vector<int> vec = { 1,2,3,2,2,2,5,4,2 };
	//s.GetLeastNumbers_Solution(vec,4);
	//cout << s.MoreThanHalfNum_Solution(vec) << endl;;
	
	return 0;
}