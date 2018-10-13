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
	while (cur->data == d)
	{
		cur = cur->next;
		return cur;
	}

	return NULL;
}
//在指定位置之前插入一个值 
//void Insert(pList* pplist, pNode pos, DataType d)
//{
//	if (pplist == NULL)
//	{
//		return;
//	}
//	for (List *cur = pplist;cur != NULL ; cur=cur->next)
//	{
//
//	}
//}

//指定位置删除 
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
//void Remove(pList* pplist, DataType d)
//{
//
//	List *cur = *pplist;
//	List *del = NULL;
//	List *pre = NULL;
//	while (cur != NULL)
//	{
//		pre = cur;
//		if (cur->data = d)
//		{
//			del = cur->next;
//			pre->next = del->next;
//		}
//		cur = cur->next;
//	}
//	free(del);
//}

//void RemoveAll(pList* pplist, DataType d);
//void EraseNotTailNode(pNode pos);


void PrintLinkList(pList plist)
{
	if (plist == NULL)
	{
		return;
	}
	List *cur = plist;

	for(cur = plist;cur!=NULL;cur = cur->next)
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
	List *ret = Find(&list,5);
	Erase(&list, ret);
	PrintLinkList(list);

//	Remove(&list, 8);
//	PrintLinkList(list);
}