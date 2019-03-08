//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int num = 0,p;
//	cin >> num>>p;
//	vector<int> vec;
//	for (int i = 0; i < num; i++)
//	{
//		cin >> vec[i];
//	}
//
//	sort(vec.begin(), vec.end());
//	if (vec.size()%2 ==1)
//	{
//
//	}
//	return 0;
//}


/*

军训队列


									题目描述

某大学开学进行军训队列训练，将学生从一开始按顺序依次编号，并排成一行横队，训练的规则如下：
从头开始一至二报数，凡报到二的出列剩下的依次向前靠拢，再从头开始进行一至三报数，凡报到三的出列，
剩下的依次向前靠拢，继续从头开始进行一至二报数。。。
以后每次从头开始轮流进行一至二报数、一至三报数直到剩下的人数不超过三人为止。
输入
第一行为组数N，接着为N行学生人数，学生人数不超过5000。
样例输入
2
20
40
输出
输出有N行，分别对应输入的学生人数，每行输出剩下的学生最初的编号，编号之间有一个空格。

样例输出
1 7 19

1 19 37
*/
#define _CRT_SECURE_NO_WARNINGS 0
#include<cstdio>
int t, n, r, finalcnt;
bool is2;
void dfs(int x, int m) {
	if (x <= 3) {
		finalcnt = x;
		is2 = (m == 3);
		return;
	}
	++r;
	return dfs(x - x / m, m == 2 ? 3 : 2);
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		r = 0;
		dfs(n, 2);
		printf("1");
		for (int i = 2; i <= finalcnt; ++i) {
			int tmp = i;
			bool is = is2;
			for (int j = 0; j < r; ++j) {
				if (is) {
					tmp = tmp * 2 - 1;
				}
				else {
					tmp = (tmp * 3 - 1) / 2;
				}
				is = !is;
			}
			printf(" %d", tmp);
		}
		printf("\n");
	}
	return 0;
}




////
//#include<iostream>
//#include<vector>
//using namespace std;
//
//void solve(int n)
//{
//	vector<int> vec;
//	for (size_t i = 1; i <= n; i++)
//	{
//		vec.push_back(i);
//	}
//
//	for (int i = 1; i <= vec.size(); i+=2)
//	{
//		vec.erase(vec.begin()+i);
//	}
//
//	for (int i = 2; i < vec.size(); i+=3)
//	{
//		vec.erase(vec.begin() + i);
//	}
//
//	for (int i = 0; i < vec.size(); i++)
//	{
//		cout << vec[i] << " ";
//	}
//
//	cout << endl;
//}
//
//int main()
//{
//	int num;
//	cin >> num;
//	vector<int> vec(num);
//	for (int i = 0; i < num; i++)
//	{
//		cin>>vec[i];
//	}
//
//	for (int i = 0; i < num; i++)
//	{
//		int n = vec[i];
//		solve(n);
//	}
//	
//	return 0;
//}

// erasing from vector
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	unsigned int i;
//	vector<unsigned int> myvector;
//
//	// set some values (from 1 to 10)
//	for (i = 1; i <= 10; i++) myvector.push_back(i);
//
//	// erase the 6th element
//	myvector.erase(myvector.begin() + 5);
//
//	// erase the first 3 elements:
//	for (int i = 0; i < myvector.size(); i++)
//	{
//		myvector.erase(myvector.begin(), myvector.begin() + i);
//		//cout << "myvector contains:";
//		//for (i = 0; i < myvector.size(); i++) {
//		//	cout << " " << myvector[i];
//		//}
//		//cout << endl;
//	}
//
//
//	system("pause");
//	return 0;
//}