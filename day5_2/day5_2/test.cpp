#include <iostream>
using namespace std;

class C_F {
private:
	C_F() {}
	C_F(const C_F&) {}
	C_F& operator = (C_F&) {}
public:
	static int flag;
	static C_F* GetInstance() {
		if (1 == flag)
		{
			flag = 0;
			return new C_F;
		}
		else {
			return NULL;
		}
	}
	/*当delete 对象的时候，就设置flag为1，以便重新创建对象的成功*/
	~C_F() {
		flag = 1;
	}
};
int C_F::flag = 1;                          //静态成员变量 必须在类外初始化
int main()
{
	/*这样就可以通过内部区实现对象，避免在外部调用私有成员
	缺点：当两个指针都指向C_F::Getinstance()的时候，就违背单例模式了*/
	C_F* p_F = C_F::GetInstance();
	delete p_F;
	/*解决：定义一个静态的flag，使对象不能创建两次：*/
	C_F* p_F1 = C_F::GetInstance();         //返回的是NULL

	delete p_F1;
	return 0;
}

//
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//	int myAtoi(string str) {
//		if (str.empty()) return 0;
//		int sign = 1, base = 0, n = str.size(), i = 0;
//		while (i < n && str[i] == ' ')
//			i++;
//		if (str[i] == '+' || str[i] == '-') {
//			sign == (str[i++] == '+') ? 1 : -1;
//		}
//		while (i<n && str[i]>'0' && str[i] < '9') {
//			if (base > INT_MAX / 10 || base == INT_MAX / 10 && str[i] - '0' > 7) {
//				return (sign == 1) ? INT_MAX : INT_MIN;
//			}
//			base = 10 * base + (str[i++] - '0');
//		}
//		return base * sign;
//	}
//};
//
//int main() {
//
//	return 0;
//}