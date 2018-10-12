#pragma once

typedef int DataType;

typedef struct List
{
	DataType data;
	struct List *next;
}Node, *pNode, List, *List;

void InitLinkList(List **pplist);
pNode BuyNode(DataType d);
void DestroyLinkList(List* pplist);
void PushBack(List* pplist, DataType d);
void PopBack(List* pplist);
void PushFront(List* pplist, DataType d);
void PopFront(List* pplist);
pNode Find(List plist, DataType d);

//��ָ��λ��֮ǰ����һ��ֵ 
void Insert(List* pplist, pNode pos, DataType d);
//ָ��λ��ɾ�� 
void Erase(List* pplist, pNode pos);
void Remove(List* pplist, DataType d);
void RemoveAll(List* pplist, DataType d);
void EraseNotTailNode(pNode pos);
void PrintLinkList(List plist);
int GetListLength(List plist);
//���������� 

//1. �����ӡ�������� 
void PrintTailToHead(pList plist);