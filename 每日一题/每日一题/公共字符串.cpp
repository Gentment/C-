//
//
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main() {
//	string str1;
//	string str2;
//	int hashtable[128] = { 0 };
//	string ret;
////	while (true) {
//		getline(cin, str1);
//		getline(cin, str2);
//		for (auto e : str2) {
//			if (hashtable[e] == 0)
//				hashtable[e]++;
//		}
//		for (auto& a : str1) {
//			if (hashtable[a] == 0) {
//				ret += a;
//			}
//		}
//		cout << ret << endl;
//	//}
//	return 0;
//}




//#include<stdio.h>
//#include<stdlib.h>
//int letter(char a[20])
//{
//	int amount1=0, i=0;
//	for (i = 0; i < 20; i++)
//	{
//		if (a[i] >= 'a' && a[i] <= 'z' || a[i] >= 'A' && a[i] <= 'Z')
//			amount1++;
//		if (a[i] == '\0')
//			break;
//	}
//	return amount1;
//}
//int figure(char a[20])
//{
//	int amount2=0, i=0;
//	for (i = 0; i < 20; i++)
//	{
//		if (a[i] >= '0' && a[i] <= '9')
//			amount2++;
//		if (a[i] == '\0')
//			break;
//	}
//	return amount2;
//}
//int main()
//{
//	char a[20];
//	int b, c;
//	//gets(a);
//	scanf("%s",a);
//	b = letter(a);
//	c = figure(a);
//	printf("字母的数量为%d,数字的数量为%d", b, c);
//}

//
//#include<iostream>
//using namespace std;
//int func() {
//	int i, j, k = 0;
//	for ( i = 0,j=-1; j=0; i++,j++)
//	{
//		k++;
//	}
//	return k;
//}
//
//int main() {
//	cout << (func());
////}
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//
//	vector<int> v;
//	int hashtable[100] = { 0 };
//	int i = 0;
//	while (cin >> v[i]) {
//		i++;
//	}
//
//	for (auto e : v) {
//		hashtable[e]++;
//	}
//	for (auto e : v) {
//		if (hashtable[e] >= v.size() / 2)
//			cout << e;
//	}
//	return 0;
//}