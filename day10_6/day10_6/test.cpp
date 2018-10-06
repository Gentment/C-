#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>

using	namespace std;
 
int main()
{
	vector<int> v;
	ifstream srcFile("in.text", ios::in);
	ofstream destFile("out.text", ios::out);

	int x;
	while (srcFile>>x)
	{
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		destFile << v[i]<<" ";
	}

	destFile.close();
	srcFile.close();
	cout << "Success"<<endl;
	return 0;
}