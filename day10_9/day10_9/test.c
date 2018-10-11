//#include<stdio.h>
//
//
//int main()
//{
//	int a = 1;
//	int b = 2;
//	a = b ^ a;
//	b = a ^ b;
//	a = b ^ a;
//	printf("%d %d\n",a,b);
//	return 0;
//}

//#include<stdio.h>
//
//
//
//void chengfakoujue()
//{
//	int i = 0;
//	int j = 0;
//	for ( i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= 9; j++)
//		{
//			printf("%d * %d = %d \t", i, j, i*j);
//		}
//		printf("\n");
//	}
//
//}
//
//int Mutle(int n)
//{
//	if (n%100 != 0&&n%4==0||n%400==0)
//	{
//		return 1;
//	}
//	return 0;
//}
//int main()
//{
////	chengfakoujue();
//	for (int i = 1000; i <= 2000; i++)
//	{
//		if (Mutle(i))
//		{
//			printf("%d  ", i);
//		}
//	}
//	return 0;
//}
//
//#include<math.h>
//int priem(int n)
//{
//	int i = 0;
//	for (int i = 2; i < sqrt(n); i++)
//	{
//		if (n%i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	for (int i = 100; i < 200; i++)
//	{
//		if (priem(i))
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}


//#include<iostream>
//#include<set>
//#include<cstring>
//#include<sstream>
//#include<vector>
//
//using namespace std;
//
//int  main() {
//	set<string> map;
//
//	string str;
//	string result;
//	vector<string>res;
//
//	while (cin >> str) {//读取字符串
//		stringstream input(str);
//		while (input >> result) {//对每一个字符串进行分割
//			res.push_back(result);
//		}
//	}
//	/*cout<<res.size()<<endl;
//	for(int i=0;i<res.size();i++){
//		cout<<res[i]<<" ";
//	}
//	cout<<endl;*/
//
//	for (int i = 0; i < res.size(); i++) {//去除重复字符串
//		if (map.size() == 0) {
//			map.insert(res[i]);
//		}
//		else {
//			if (map.find(res[i]) == map.end()) {
//				map.insert(res[i]);
//			}
//		}
//	}
//	cout << map.size() << endl;
//	system("pause");
//	return 0;
//}
