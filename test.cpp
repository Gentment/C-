#include <iostream>
#include <stdlib.h>
#include "MyStasck.h"
using namespace std;


int main()
{
	MyStack *pStack = new MyStack(5);

	pStack->push('a');
	pStack->push('b');
	pStack->push('c');
	pStack->push('d');
	pStack->push('e');

	pStack->stackTraverse(true); //1
	cout<<endl;
	cout<<"ջ��Ԫ�ظ�����"<<pStack->stackLength()<<endl;
	char elem = 0;
	pStack->pop(elem);
	cout<<endl;
	cout<<"popԪ�أ�"<<elem<<endl;	//2
	
	pStack->stackTraverse(true); //3
	cout<<endl;
	cout<<"ջ��Ԫ�ظ�����"<<pStack->stackLength()<<endl; //4
	//pStack->clearStack();
	if (pStack->stackEmpty())
	{
	   cout<<"ջΪ��"<<endl; //5
	}
	if (pStack->stackFull())
	{
	   cout<<"ջΪ��"<<endl;
	}

	delete pStack;
	pStack = NULL;


}