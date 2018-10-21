
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

//�����ṹ������ 
typedef struct LNode {
	int  nData;  //������ 
	struct LNode *next;   //ָ���� 
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


//׷������Ԫ�ؽ���������ͷ���ĵ�����


Linkedlist  InsertAsHead(Linkedlist Head) {
	int i, n, x;
	//������Ԫ�ط�װ���ڵ��� 
	Linkedlist pNew = (Linkedlist)malloc(sizeof(LNode));
	pNew->next = NULL;
	printf("�����뵥����ĳ��ȣ�");
	scanf("%d", &n);
	printf("����Ԫ�أ�");
	for (i = 1; i <= n; i++) {
		Linkedlist q = Head;
		scanf("%d", &x);
		q->next = createList(x);
		pNew->next = q;
		
	}
	return pNew;

}

//���������
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

//���㵥����ĳ���
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

//���������ĵ�i��Ԫ��
void GetElem_L(Linkedlist L, int i) {
	int j = 1;                     //���д��뺬��EleType e����Ϊ��e������ֵ������ 
	Linkedlist p = L->next;

	while (p&&j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i)
	{
		printf("û�и�Ԫ��\n");
		return ;
	}
	else
		printf("%d\n", p->nData);
}

//�ڵ�i��Ԫ�ز���һ������Ԫ��
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

//ɾ����i��Ԫ��,������������ѭ�� 
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

	free(q);//free(p)���º�����������ѭ�� 

}
//���Ҹ������ݣ�������ɾ��
void LocateByValue(Linkedlist pHead, int nElem) {
	Linkedlist p = NULL, q = NULL;

	if (p == NULL)
		return ;

	p = pHead->next;//��pָ���һ���ڵ�
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

	pHead = InsertAsHead(pHead); //�����ڵ��ù����������ڲ����ܳ����ַ� 

	outputList(pHead);//�����޷�������� 

	getlen_L(pHead);//���㳤������ 
	printf("���������Ԫ�أ�");
	GetElem_L(pHead, 3);
	printf("�ڵڶ���λ�ò���һ��Ԫ��5��");
	ListInsert_L(pHead, 2, 5);
	outputList(pHead);
	printf("ɾ��������Ԫ�أ�");
	Deletelist_L(pHead, 3);
	outputList(pHead);
	printf("����ֵΪ6��Ԫ�ش�����ɾ����");
	LocateByValue(pHead, 6);//ɾ������ 
	outputList(pHead);

	// ��δ������֮�󣬳��������ѭ�� 
}
//Ŀǰ��������޷����� 
