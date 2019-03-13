//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<map>
//using namespace std;
//
//int myfun(int i,int j)
//{
//	return (i<j);
//}
//int main()
//{
//	int num = 0;
//	cin >> num;
//	string str;
//	vector<string> vec(num);
//	for (int i = 0; i < num; i++)
//	{
//		cin >> vec[i];
//	}
//
//	sort(vec.begin(), vec.end());
//
//	for (int i = 0; i < vec.size(); i++)
//	{
//		cout << vec[i] << "  ";
//	}
//	cout << endl;
	//map<string, int> map;
	//for (int i = 0; i < num; i++)
	//{
	//	cin>>str;
	//	int sz = sizeof(str);
	//	map.insert( pair<string,int>(str,sz) );
	//}
	//sort(map.begin(), map.end(),myfun);
	//
//
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int n1, n2;
//	cin >> n1 >> n2;
//	int max = n1 > n2 ? n1 : n2;
//	while (true)
//	{
//		if (max /n1 == n2 && max /n2 == n1)
//		{
//			cout<< max<< endl;
//			break;
//		}
//		max++;
//	}
//	return 0;
//}
//
//#include<iostream>
//using namespace std;
//
//class UnusualAdd {
//public:
//	int addAB(int A, int B) {
//		// write code here
//		return B==0?A:addAB(A^B,(A&B)<<1);
//	}
//};
//
//
//int main()
//{
//	UnusualAdd u;
//	cout<<u.addAB(3, 3) << endl;
//}

#include<iostream>
using namespace std;

int sum(int x, int y)
{
	if (x > 1 && y > 1)
	{
		return sum(x, y - 1) + sum(x - 1, y);
	}
	else if ((x >= 1 && y == 1) || (x == 1) && (y >= 1)) {
		return x + y;
	}
	else {
		return 0;
	}
}
int main()
{
	int col, row;
	cin >> col >> row;
	cout << sum(row, col) << endl;
	return 0;
}