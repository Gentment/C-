#include "list.h"

void InitLinkList(pList *pplist)
{
	pplist = NULL;
}

void DestroyLinkList(pList* pplist)
{
	pplist = NULL;
}
pNode BuyNode(DataType d)
{
	pNode newNode = (List*)malloc(sizeof(List));

	newNode->data = d;
	newNode->next = NULL;

	return newNode;
}
void PushBack(pList* pplist, DataType d)
{
	List *newNode = BuyNode(d);
	List *cur = *pplist;

	if (*pplist == NULL)
	{
		*pplist = newNode;
		return;
	}
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = newNode;

}

void PopBack(pList* pplist)
{
	List *cur = *pplist;
	List *del;
	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}
	del = cur->next;
	cur->next = NULL;
	free(del);
}

void PushFront(pList* pplist, DataType d)
{
	List *newNode = BuyNode(d);

	newNode->next = *pplist;

	*pplist = newNode;
}

void PopFront(pList* pplist)
{
	List *del = *pplist;
	*pplist = del->next;
	free(del);
}

pNode Find(pList plist, DataType d)
{
	List *cur = plist;
	while (cur != NULL)
	{
		if (cur->data == d)
		{
			return cur;
		}
		cur = cur->next;
	}

	return NULL;
}
//��ָ��λ��֮ǰ����һ��ֵ 
void Insert(pList* pplist, pNode pos, DataType d)
{
	if (pplist == NULL)
	{
		return;
	}
	if (*pplist == pos)
	{
		PopFront(pplist);
		return;
	}
	List *newNode = BuyNode(d);
	List *cur = *pplist;
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	newNode->next = cur->next;
	cur->next = newNode;
}

//ָ��λ��ɾ�� 
void Erase(pList* pplist, pNode pos)
{
	List *cur = *pplist;
	if (*pplist == pos)
	{
		PopFront(pplist);
	}
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	cur->next = pos->next;
	free(pos);
}
void Remove(pList* pplist, DataType d)
{
	List *cur = *pplist;
	List *del = NULL;
	List *pre = NULL;
	while (cur->data != d)
	{
		pre = cur;
		cur = cur->next;
	}
	del = cur;
	pre->next = del->next;

	free(del);
}

void RemoveAll(pList* pplist)
{
	if (pplist == NULL)
	{
		return;
	}
	List* cur = pplist;
	while (cur->next != NULL)
	{
		free(cur);
		cur = cur->next;
	}
}
//void EraseNotTailNode(pList* pplist,pNode pos)
//{
//	List *del;
//	if (pplist == NULL)
//	{
//		return;
//	}
//	//	pos λ��Ϊ��һ�����ʱ���޸�ָ��
//	if (pos == pplist)
//	{
//		pplist = pos->next;
//		free(pos);
//	}
//	// pos λ�ò��ǵ�һ�����ʱҲ�������һ�����ʱ
//	pos->data = pos->next->data;   //���޸�data��ֵ
//	del = pos->next;     //��pos->next��ΪҪɾ���Ľ��
//	pos->next = del->next;
//	free(del);
//}
int GetListLength(pList plist)
{
	if (plist == NULL)
	{
		return 0;
	}
	List *cur = plist;

	int count = 1;
	for (; cur != NULL; cur = cur->next)
	{
		count++;
	}
	return count;
}
//���������� 


//1. �����ӡ�������� 
void PrintTailToHead(List plist);

void PrintLinkList(pList plist)
{
	if (plist == NULL)
	{
		return;
	}
	List *cur = plist;

	for(;cur!=NULL;cur = cur->next)
	{
		printf("%d  ", cur->data);
	}

}

void Test()
{
	List *list;
	InitLinkList(&list);
	for (int i = 1; i <= 10; i++)
	{
//		PushBack(&list, i);
		PushFront(&list, i);
	}
//	printf("%p\n",Find(list,5));
//	List *ret = Find(list,5);
//	Erase(&list, ret);
	
//	PrintLinkList(list);

	//Remove(&list, 8);
	//PrintLinkList(list);

	//List *ret = Find(list,5);
	//Insert(&list, ret, 11);

	int ret = GetListLength(list);
	printf("%d\n", ret);
	PrintLinkList(list);


}