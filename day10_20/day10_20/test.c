
#if 0


#include<stdio.h>
int main()
{
	int i;
	int n;
	for ( i = 1; i <=9; i++)
	{
		for (n = 1; n <= i; n++)
		{
			printf("%d*%d = %d", i, n, i*n);
		}
		printf("\n");
	}
}
#endif // 0
#define _CRT_SECURE_NO_WARNINGS 0

#include<stdio.h>
#include<stdlib.h>

//声明结构体类型 
typedef struct LNode {
	int  nData;  //数据域 
	struct LNode *next;   //指针域 
}LNode, *Linkedlist;


//create an empty List
Linkedlist createList(int data) {
	Linkedlist p = (Linkedlist)malloc(sizeof(LNode));
	if (p == NULL)
		return NULL;

	p->nData = data;
	p->next = NULL;
	return p;
}


//追加数据元素建表，建立带头结点的单链表


Linkedlist  InsertAsHead(Linkedlist Head) {
	int i, n, x;
	//把数据元素封装到节点中 
	Linkedlist pNew = (Linkedlist)malloc(sizeof(LNode));
	pNew->next = NULL;
	printf("请输入单链表的长度：");
	scanf("%d", &n);
	printf("输入元素：");
	for (i = 1; i <= n; i++) {
		Linkedlist q = Head;
		scanf("%d", &x);
		q->next = createList(x);
		pNew->next = q;
		
	}
	return pNew;

}

//输出单链表
void outputList(Linkedlist L)
{
	Linkedlist p = L;
	while (p->next != NULL)
	{
		printf("%d", p->nData);
		p = p->next;
	}
	printf("\n");
}

//计算单链表的长度
int  getlen_L(Linkedlist Head)
{
	int len = 0;
	Linkedlist p;

	p = Head->next;
	while (p) {
		len++;
		p = p->next;
	}
	return len;
}

//输出单链表的第i个元素
void GetElem_L(Linkedlist L, int i) {
	int j = 1;                     //书中代码含有EleType e解释为由e返回其值？？？ 
	Linkedlist p = L->next;

	while (p&&j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i)
	{
		printf("没有该元素\n");
		return ;
	}
	else
		printf("%d\n", p->nData);
}

//在第i个元素插入一个数据元素
void ListInsert_L(Linkedlist L, int i, int e) {
	Linkedlist p = L;
	Linkedlist s;
	int j = 0;
	while (p&&j < i - 1) {
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
		return ;
	s = (Linkedlist)malloc(sizeof(LNode));
	s->nData = e;
	s->next = p->next;
	p->next = s;
}

//删除第i个元素,函数存在无限循环 
void Deletelist_L(Linkedlist L, int i)
{
	Linkedlist p, q;
	p = L->next;

	int j = 1;
	while (j < i - 1) {
		j++;
		p = p->next;

	}
	q = p->next;
	p->next = p->next->next;

	free(q);//free(p)导致函数进行无限循环 

}
//查找给出数据，存在则删除
void LocateByValue(Linkedlist pHead, int nElem) {
	Linkedlist p = NULL, q = NULL;

	if (p == NULL)
		return ;

	p = pHead->next;//令p指向第一个节点
	while (p) {
		if (p->nData == nElem)
		{
			q = p->next;
			p->next = p->next->next;
			free(q);
		}
		p = p->next;
	}

}




int main()
{

	Linkedlist pHead = NULL;

	pHead = InsertAsHead(pHead); //函数在调用过程中括号内部不能出现字符 

	outputList(pHead);//程序无法正常输出 

	getlen_L(pHead);//计算长度有误 
	printf("输出第三个元素：");
	GetElem_L(pHead, 3);
	printf("在第二个位置插入一个元素5：");
	ListInsert_L(pHead, 2, 5);
	outputList(pHead);
	printf("删除第三个元素：");
	Deletelist_L(pHead, 3);
	outputList(pHead);
	printf("查找值为6的元素存在则删除：");
	LocateByValue(pHead, 6);//删除出错 
	outputList(pHead);

	// 这段代码加上之后，程序出现死循环 
}
//目前程序代码无法运行 
