////类继承中的static关键字
//#include<iostream>
//using namespace std;
//
///*
//派生类中的静态成员
//基类定义的静态成员，将被所有派生类共享
//根据静态成员自身的访问特性和派生类的继承方式，在类层次体系中具有不同的访问性质
//派生类中访问静态成员，用以下形式显示说明：
//
//类名::成员
//或者通过对象访问   对象名.成员
//
//*/
//
//
//class PointA {
//public:
//	static int a;
//	static void Print() {
//		cout << "静态成员函数" << endl;
//		cout << "a=" << a << endl;
//		// 报错 error LNK2001: 无法解析的外部符号 "public: static int PointA::a" (?a@PointA@@2HA)
//		//发现只要使用静态变量就会报错
//		//原因是 静态变量没有初始化，静态变量是属于类的，定义类对象的时候（PointB pb;）并不会自动初始化类的静态成员属性
//
//	}
//	PointA() {
//		//就算在构造函数里初始化静态成员变量,也是不成功的，静态成员变量必须在全局初始化
//		a++;
//	}
//};
//
////唯一正确的初始化静态变量的方法
//int PointA::a = 0;
//
//class PointB :public PointA {
//public:
//};
//
//void ProtectA() {
//	PointB pb;//a=1
//	pb.Print();
//	pb.a = 3;//a=3
//	PointA pa = pb;//拷贝赋值   a=3
//	pa.Print();
//	PointA pa2;//a=4
//	pa.Print();
//
//}
//
//int main() {
//	ProtectA();
//}



#include<iostream>

using namespace std;

template<typename T>
void fun(T& a, T& b) {
	cout << "a" << a << "-b: " << b << endl;
	cout << "我是模板函数" << endl;
}

void fun(int a, char b) {
	cout << "a" << a << "-b: " << b << endl;
	cout << "我是函数调用" << endl;
}
int main() {

	int a = 1;
	char b = 'z';
	fun(a, b);//普通函数调用，可以进行隐式的类型转换
	fun(b, a);//  普通函数调用
	fun(a, a);//调用函数模板（本质：参数类型化），严格按照类型匹配，不会进行类型自动转换
	return 0;
}


/*
	1.函数模板可以像普通函数一样被重载
	2.C++编译器优先考虑普通函数
	3.如果函数模板可以产生一个更好的匹配，则选择模板
	4.可以通过空模板实参列表的语法限定编译器只通过模板匹配
*/

//#include<iostream>
//using namespace std;
//
//int Max(int a, int b) {
//	cout << "int Max(int a,int b)" << endl;
//	return a > b ? a : b;
//}
//
//template<typename T>
//T Max(T a, T b) {
//	cout << "T Max(T a,T b)" << endl;
//	return a > b ? a : b;
//}
//
//template<typename T>
//T Max(T a, T b,T c) {
//	cout << "T Max(T a,T b,T c)" << endl;
//	return Max(Max(a, b), c);
//}
//int main() {
//
//	int a = 1;
//	int b = 2;
//	cout << Max(a, b) << endl; //当函数模板和普通函数模板都符合时，优先选择普通函数
//	cout << Max<>(a, b) << endl;//若显示使用函数模板，则使用<>类型列表
//	cout << Max(3.0, 4.0) << endl;//如果函数模板可以产生一个更好的匹配，则选择模板
//	cout << Max(5.0, 6.0, 7.0) << endl;//重载
//	cout << Max('a', 100) << endl;//调用普通函数可以隐式类型转换
//	return 0;
//}