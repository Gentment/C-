////��̳��е�static�ؼ���
//#include<iostream>
//using namespace std;
//
///*
//�������еľ�̬��Ա
//���ඨ��ľ�̬��Ա���������������๲��
//���ݾ�̬��Ա����ķ������Ժ�������ļ̳з�ʽ����������ϵ�о��в�ͬ�ķ�������
//�������з��ʾ�̬��Ա����������ʽ��ʾ˵����
//
//����::��Ա
//����ͨ���������   ������.��Ա
//
//*/
//
//
//class PointA {
//public:
//	static int a;
//	static void Print() {
//		cout << "��̬��Ա����" << endl;
//		cout << "a=" << a << endl;
//		// ���� error LNK2001: �޷��������ⲿ���� "public: static int PointA::a" (?a@PointA@@2HA)
//		//����ֻҪʹ�þ�̬�����ͻᱨ��
//		//ԭ���� ��̬����û�г�ʼ������̬������������ģ�����������ʱ��PointB pb;���������Զ���ʼ����ľ�̬��Ա����
//
//	}
//	PointA() {
//		//�����ڹ��캯�����ʼ����̬��Ա����,Ҳ�ǲ��ɹ��ģ���̬��Ա����������ȫ�ֳ�ʼ��
//		a++;
//	}
//};
//
////Ψһ��ȷ�ĳ�ʼ����̬�����ķ���
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
//	PointA pa = pb;//������ֵ   a=3
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
	cout << "����ģ�庯��" << endl;
}

void fun(int a, char b) {
	cout << "a" << a << "-b: " << b << endl;
	cout << "���Ǻ�������" << endl;
}
int main() {

	int a = 1;
	char b = 'z';
	fun(a, b);//��ͨ�������ã����Խ�����ʽ������ת��
	fun(b, a);//  ��ͨ��������
	fun(a, a);//���ú���ģ�壨���ʣ��������ͻ������ϸ�������ƥ�䣬������������Զ�ת��
	return 0;
}


/*
	1.����ģ���������ͨ����һ��������
	2.C++���������ȿ�����ͨ����
	3.�������ģ����Բ���һ�����õ�ƥ�䣬��ѡ��ģ��
	4.����ͨ����ģ��ʵ���б���﷨�޶�������ֻͨ��ģ��ƥ��
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
//	cout << Max(a, b) << endl; //������ģ�����ͨ����ģ�嶼����ʱ������ѡ����ͨ����
//	cout << Max<>(a, b) << endl;//����ʾʹ�ú���ģ�壬��ʹ��<>�����б�
//	cout << Max(3.0, 4.0) << endl;//�������ģ����Բ���һ�����õ�ƥ�䣬��ѡ��ģ��
//	cout << Max(5.0, 6.0, 7.0) << endl;//����
//	cout << Max('a', 100) << endl;//������ͨ����������ʽ����ת��
//	return 0;
//}