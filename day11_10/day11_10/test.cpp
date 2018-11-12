#include<iostream>
#include<vector>
using namespace std;
class Test {
public:
	void Permutation(string str) {
	
		str.push_back('a');
		str.push_back('b');
		str.push_back('c');
		cout << str[1] << endl;

	}
};


int main()
{
	Test t;
	t.Permutation("abc");
}