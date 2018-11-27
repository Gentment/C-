#define _CRT_SECURE_NO_WARNINGS 0
#include<iostream>
using namespace std;
namespace mystring
{
	class Mystring 
	{
	public:
	
		//构造函数
		Mystring(const char* str = "") 
		{
			if (str == nullptr)
			{
				return;
			}

			_str = new char[strlen(str)+1];
			strcpy(_str,str);
		}

		//拷贝构造函数
		Mystring(const Mystring& s):_str(new char[strlen(s._str)+1])
		{
			strcpy(_str,s._str);
		}

		//赋值运算符
		Mystring& operator=(const Mystring& s)
		{
			if (&s != this)
			{
				char *pStr = new char[strlen(s._str)+1];

				strcpy(pStr,s._str);
				delete[] _str;
				_str = pStr;
			}

			return *this;
		}

		Mystring& operator+(const Mystring& s)
		{
			Mystring temp;
			temp._str = new char[strlen(_str) +strlen(s._str) + 1];
			temp._str = strcat(_str,s._str);
			return temp;
		}

		char& operator[](const int index)
		{
			if (index<0)
			{
				cout << "index out of rang" << endl;
			}

			return _str[index];
		}


		friend ostream& operator<<(ostream& _cout,const Mystring& s)
		{
			_cout << s._str << "";
			return _cout;
		}


		~Mystring() 
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}

		
	private:
		char* _str;
	};


}

using namespace mystring;
int main()
{
	Mystring s = "123";
	Mystring s1 = "abc";
	cout << s1[1] << endl;
//	cout << s+s1 << endl;
	return 0;
}