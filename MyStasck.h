#ifndef MYSTACK_H
#define MYSTACK_H

class MyStack
{
public:
	MyStack(int size);  //�����ڴ�����ջ�ռ䣬�趨ջ������ջ��
	~MyStack();			//ͬ��ջ�ռ��ڴ�
	bool stackEmpty();	//..
	bool stackFull();
	void clearStack();
	int stackLength();
	bool push(char elem);
	bool pop(char &elem);
	void stackTraverse(bool isFromButtom);
private:
	char *m_pBuffer;  //ջ�ռ�ָ��
	int m_iSize;	  //ջ����
	int m_iTop;		  //ջ����ջ��Ԫ�ظ���
};
#endif //MYSTACK_H
