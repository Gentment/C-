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

//在指定位置之前插入一个值 
void Insert(List* pplist, pNode pos, DataType d);
//指定位置删除 
void Erase(List* pplist, pNode pos);
void Remove(List* pplist, DataType d);
void RemoveAll(List* pplist, DataType d);
void EraseNotTailNode(pNode pos);
void PrintLinkList(List plist);
int GetListLength(List plist);
//链表面试题 

//1. 逆序打印单项链表 
void PrintTailToHead(pList plist);