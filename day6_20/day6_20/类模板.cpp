//#include<iostream>
//using namespace std;
//
//template<class T>
//class A {
//public:
//	A(T a) {
//		this->a = a;
//		cout << "A()" << endl;
//	}
//private:
//	T a;
//};
//
//class B :public A<int> {
//public:	
//	B(int b,int a):A(a) {
//		cout << "B()" << endl;
//	}
//};
//
//template<typename T>
//class C :public A<T> {
//public:
//	C(T c,T a):A<T>(a) {
//		this->c = c;
//		cout << "C()" << endl;
//	}
//private:
//	T c;
//};
//
//int main() {
//	//B b;
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//template<typename T>
//class A {
//public:
//	static T a;
//};
//
//template<typename T>
//T A<T>::a = 0;
//int main() {
//	A<int> a;
//	return 0;
//}

#include<iostream>
using namespace std;

class A {
public:
	A() {
		cout << "A()" << endl;
	}
};

class B {

};
int main() {
	B b;
	A  a = reinterpret_cast<B>(b);

}