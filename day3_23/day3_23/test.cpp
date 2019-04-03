#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int month;
	int sum = 0;
	cin >> month;
	vector<int> vec(month+1);
	vec[1] = vec[1] = 1;
	for (int i = 3; i <= month; i++)
	{
		vec[i] = vec[i - 1] + vec[i - 2];
	}
	cout <<"sum:"<<vec[month] << endl;
	return 0;
}