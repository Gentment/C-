//#pragma
//#include<stdlib.h>
//#include<stdio.h>
////1. ��װջ�Ļ�������
//// ���飺��̬ 
//
//typedef struct BTNode* SDataType;
//
//#define MAXSIZE 10 
//
//typedef struct Stack
//{
//	SDataType _array[MAXSIZE];
//	int _top; // ���ջ��(ջ��Ԫ�صĸ���) 
//}Stack;
//
//
//void StackInit(Stack* ps)
//{	
//	ps->_top = 0;
//}
//void StackPush(Stack* ps, SDataType data)
//{
//	Stack* newNode = (Stack*)malloc(sizeof(Stack));
//	if (ps->_top == 0)
//	{
//		ps->_array[ps->_top] = newNode;
//	}
//}
//
//
//void StackPop(Stack* ps);
//SDataType StackTop(Stack* ps);
//int StackSize(Stack* ps);
//int StackEmpty(Stack* ps);