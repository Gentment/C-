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
	/*��delete �����ʱ�򣬾�����flagΪ1���Ա����´�������ĳɹ�*/
	~C_F() {
		flag = 1;
	}
};
int C_F::flag = 1;                          //��̬��Ա���� �����������ʼ��
int main()
{
	/*�����Ϳ���ͨ���ڲ���ʵ�ֶ��󣬱������ⲿ����˽�г�Ա
	ȱ�㣺������ָ�붼ָ��C_F::Getinstance()��ʱ�򣬾�Υ������ģʽ��*/
	C_F* p_F = C_F::GetInstance();
	delete p_F;
	/*���������һ����̬��flag��ʹ�����ܴ������Σ�*/
	C_F* p_F1 = C_F::GetInstance();         //���ص���NULL

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