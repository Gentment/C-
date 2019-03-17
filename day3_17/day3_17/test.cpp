//#include<iostream>
//#include<string>
//using namespace std;
//
//bool CheckStr(const string &s)
//{
//	size_t begin = 0;
//	size_t end = s.size() - 1;
//	while (begin < end) {
//		if (s[begin] != s[end])
//		{
//			return false;
//		}
//		++begin;
//		--end;
//	}
//	return true;
//}
//
//int main()
//{
//	string str1, str2;
//
//	//while(cin>>str1>>str2){}
//	getline(cin, str1);
//	getline(cin, str2);
//	int count = 0;
//	for (int i = 0; i < str1.size(); ++i)
//	{
//		string str = str1;
//			str.insert(i, str2);
//		if (CheckStr(str))
//		{
//			++count;
//		}
//	}
//	cout << count << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//void main() {
//	int n[][3] = { 10,20,30,40,50,60 };
//	int(*p)[3];
//	p = n;
//	cout << p[0][0] << "," << *(p[0] + 1) << "," << (*p)[2] << endl;
//}

#include<iostream>
struct st_task
{
	uint16_t id;
	uint32_t value;
	uint64_t timestamp;
};
//同时定义fool函数如下：
void fool()
{
	st_task task = {};
	uint64_t a = 0x00010001;
	memcpy(&task, &a, sizeof(uint64_t));
	std::cout<<task.id<<"--"<<task.value<<"--"<< task.timestamp<<std::endl;
}

int main()
{
	fool();
	return 0;
}