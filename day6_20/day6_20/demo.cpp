#include<iostream>
using namespace std;
template<class T>
class A
{
public:
	A(T a = 0) {
		b = a;
	}
	~A();
	void printA() {
		cout << "a:" << b << endl;
	}
private:
	T b;
};

int main() {

	A<int> a(1);
	return 0;
}