//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class work {
//public:
//	int di;
//	int pi;
//	work()
//	{
//		di = 0;
//		pi = 0;
//	}
//};
//class student {
//public:
//	int ai;
//	int id;
//	student()
//	{
//		ai = 0;
//		id = 0;
//	}
//};
//bool sortByPi(const work &w1, const work &w2)
//{
//	if (w1.di == w2.di)
//	{
//		return w1.pi > w2.pi;
//	}
//	else
//	{
//		return w1.di < w2.di;
//	}
//}
//bool sortByAi(const student &stu1, const student &stu2)
//{
//	return stu1.ai < stu2.ai;
//}
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<work> vec_work(n);
//	vector<student> vec_student(m);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> vec_work[i].di >> vec_work[i].pi;
//	}
//	sort(vec_work.begin(), vec_work.end(), sortByPi);
//	for (int j = 0; j < m; j++)
//	{
//		cin >> vec_student[j].ai;
//		vec_student[j].id = j;
//	}
//	sort(vec_student.begin(), vec_student.end(), sortByAi);
//	int worknum = 0, ans = 0;
//	int max_pi[101000];
//	for (int i = 0; i < m; i++)
//	{
//		while (worknum < n && vec_student[i].ai >= vec_work[worknum].di)
//		{
//			ans = max(vec_work[worknum].pi, ans);
//			worknum++;
//		}
//		max_pi[vec_student[i].id] = ans;
//	}
//	for (int i = 0; i < m; i++)
//	{
//		cout << max_pi[i] << endl;
//	}
//	return 0;
//
//}


#include<iostream>

using namespace std;

int main()
{
	int n, m;
	int sum=0, count=0;
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
	{
		sum += i;
	}
	for (int i = n; i < m; n++)
	{
		sum += (i + 1);
		if (sum % 3 == 0)
		{
			count++;
		}
	}
	cout << count << endl;
	return 0;
}