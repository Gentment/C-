#include<vector>
#include<iostream>
#include<iterator>
using namespace std;

#if 0


class StringFormat {
public:
	string formatString(string A, int n, vector<char> arg, int m) {
		// write code here
		vector<char> v;
		size_t count = 0;
		for (int i = 0; i < n; i++)
		{
			v.push_back(A[i]);
		}
		vector<char>::iterator itt = arg.begin();
		for (vector<char>::iterator it = v.begin();it!=v.end();++it)
		{
			if ('s' == *it)
			{
				if ('%' == *(it-1) && itt != arg.end())
				{					
					count++;
					*(it - 1) = NULL;
					*it = *itt++;

				}
			}
		}

		if (count < arg.size() )
		{
			while(arg.size()-v.size()&& itt != arg.end())
			{
				v.push_back(*itt++);
			}
		}
		vector<char>::iterator iit = v.begin();
		string B = { 0 };
		for (size_t i = 0; i < count+arg.size(); i++)
		{
			if (*iit !='\0')
			{
				B[i] = *iit++;
			}
		}
		return B;
	}
};



int main()
{
	StringFormat s;
	string A = "A%sC%sE";
	vector<char> arg = { 'B','D','F' };
	
	int m = 0;
	string ret = s.formatString(A,A.size(),arg,m);
	system("pause");
	return 0;
}


#endif

#if 0



int jumpFloorII(int number) {
	if (number<2)
	{
		return 1;
	}
	return jumpFloorII(number)+jumpFloorII(--number)+1;
}

int main()
{
	int ret = jumpFloorII(3);
	cout << ret << endl;
	system("pause");
}


#endif

#if 0
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		// write code here
		if (gifts.size() < n)
		{
			return 0;
		}
		if (gifts.size() == 0)
		{
			return 0;
		}

		int temp, count = 0;
		for (int i=0; i < n; ++i)
		{
			if (count == 0)
			{
				temp = gifts[i];
				count++;
			}
			else {
				if (temp == gifts[i])
				{
					count++;
				}
				else {
					count--;
				}
			}
		}
		int size = 0;
		for (int i = 0; i < n; i++)
		{
			if (temp == gifts[i])
			{
				size++;
			}
		}
		return (size > n / 2) ? temp : 0;
	}
};
int main()
{
	vector<int> v = { 1,3,2,2,2,4,2 };
	Gift g;
	int ret = g.getValue(v,7);
	cout << ret << endl;
	system("pause");
}

#endif 

int Fibonacci(int n) {
	
	if (n <= 2)
	{
		return 1;
	}
	int a = 1;
	int b = 1;
	int tmp = 0;
	while (n-2 > 0)
	{
		tmp = a + b;
		a = b;
		b = tmp;
		n--;
	}
	return tmp;

}

int Fibonacci1(int n) {
	if (n <= 2)
	{
		return 1;
	}
	else
	return Fibonacci1(n-1)+Fibonacci1(n-2);
}


bool Find(int target, vector<vector<int> > array) {

	//
	//size_t row = 0;
	//int col = array[0].size() - 1;
	//if (col > 0 && array.size() > 0)
	//{
	//	while (row < array.size() && col >= 0)

	for (size_t i=0;i<array.size();++i)
	{
		int j = array[i].size()-1;
		while(j>0)
		{
			if (target == array[i][j] )
			{
				cout << "success" << endl;
				return true;
			}
			else if (target > array[i][j] && i<array.size())
			{
				i+=1;
			}
			else if(target < array[i][j])
			{
				j--;
			}
		}
	}
	return false;
}


bool Find1(int target, vector<vector<int> > array) {

	size_t row = 0;
	int col = array[0].size() - 1;
	if(col >0 && array.size() >0)
	{
		while (row < array.size()&&col >=0)
		{
			if (target == array[row][col])
			{
				cout << "success" << endl;
				return true;
			}
			else if (target > array[row][col])
			{
				row++;
			}
			else if (target < array[row][col])
			{
				--col;
			}
		}
	}
	return false;
}

#include<string>
int main()
{
//	cout << Fibonacci1(5) << endl;
//	cout << Fibonacci(5) << endl;
	
	vector<vector<int> > array = { {1,2,3,4},{2,3,4,5},{3,4,5,6} };
//	cout << array.size() << endl;
	cout << Find1(5,array) << endl;

//	cout << array.size() << endl;
//	string s = "abc";
//	cout << s.c_str() << endl;;
	system("pause");
}
