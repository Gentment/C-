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

��ѵ����


									��Ŀ����

ĳ��ѧ��ѧ���о�ѵ����ѵ������ѧ����һ��ʼ��˳�����α�ţ����ų�һ�к�ӣ�ѵ���Ĺ������£�
��ͷ��ʼһ�������������������ĳ���ʣ�µ�������ǰ��£���ٴ�ͷ��ʼ����һ�������������������ĳ��У�
ʣ�µ�������ǰ��£��������ͷ��ʼ����һ��������������
�Ժ�ÿ�δ�ͷ��ʼ��������һ����������һ��������ֱ��ʣ�µ���������������Ϊֹ��
����
��һ��Ϊ����N������ΪN��ѧ��������ѧ������������5000��
��������
2
20
40
���
�����N�У��ֱ��Ӧ�����ѧ��������ÿ�����ʣ�µ�ѧ������ı�ţ����֮����һ���ո�

�������
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