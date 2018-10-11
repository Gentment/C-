#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef int DataType;

typedef struct SqList
{
	DataType data[MAX_SIZE];
	int size;
}SqList;

void SqListInit(SqList *phead)
{
	phead->size = 0;
}

void PushBack(SqList *phead, DataType data)
{
	if (phead == NULL)
	{
		return;
	}
	if (phead->size < MAX_SIZE)
	{
		phead->data[phead->size] = data;
		phead->size++;
	}
}

void PopBack(SqList *phead)
{
	if (phead == NULL)
	{
		return;
	}
	phead->size--;
}
void PushFront(SqList *phead,DataType data)
{
	if (phead == NULL)
	{
		return;
	}

	if (phead->size > MAX_SIZE)
	{
		return;
	}
	phead->size++;
	int i = 0;
	for (i = phead->size; i > 0; i--)
	{
		phead->data[i] = phead->data[i - 1];
	}
	phead->data[0] = data;
}

int Find(SqList *phead, DataType data)
{
	if (phead == NULL &&phead->size == 0)
	{
		return 0;
	}
	for (int i = 0; i < phead->size; i++)
	{
		if (phead->data[i] == data)
			return i;
	}
	return 0;
}

void PopFront(SqList *phead)
{
	if (phead == NULL)
	{
		return;
	}
	for (int i = 0; i < phead->size; i++)
	{
		phead->data[i] = phead->data[i + 1];
	}
	phead->size--;
}

void Insert(SqList *phead, int pos, DataType data)
{
	if (phead == NULL)
	{
		return;
	}
	if (MAX_SIZE <phead->size)
	{
		return;
	}
	for (int i = phead->size; i > pos; i--)
	{
		phead->data[i+1] = phead->data[i];
	}
	phead->data[pos] = data;
	phead->size++;
}

void Erase(SqList *phead, int pos)
{
	if (phead == NULL)
	{
		return;
	}
	for (int i = pos-1; i < phead->size; i++)
	{
		phead->data[i] = phead->data[i + 1];
	}
	phead->size--;
}

void Remove(SqList *phead, DataType data)
{
	if (phead == NULL)
		return;

	int j = Find(phead, data);
	for (int i = j; i < phead->size; i++)
	{
		phead->data[i] = phead->data[i + 1];
	}
	phead->size--;
}

void RemoveAll(SqList *phead, DataType data)
{
	phead->size = 0;
	
	printf("Remove All !!!\n ");
}

int Size(SqList *phead)
{
	return phead->size;
}

int Empty(SqList *phead)
{
	if (phead->size == 0)
	{
		return 0;
	}
	return 1;
}

void BubbleSort(SqList *phead)
{
	for (int i = 0; i < phead->size; i++)
	{
		for (int j = i+1; j < phead->size; j++)
		{
			if (phead->data[i] > phead->data[j])
			{
				int temp = phead->data[i];
				phead->data[i] = phead->data[j];
				phead->data[j] = temp;
			}
		}
	}
}

void  SelectSort(SqList *phead)
{
	int min = 0;
	for (int i = 0; i < phead->size; i++)
	{
		min = i;
		for (int j = i+1; j < phead->size; j++)
		{
			if (phead->data[i]>phead->data[j])
			{
				min = j;
			}
		}
		if (i != min)
		{
			int temp = phead->data[min];
			phead->data[min] = phead->data[i] ;
			phead->data[i] = temp;
		}
	}
}

void SelectSortOP(SqList *phead)
{
	if (phead == NULL)
	{
		return;
	}
	int minSpace = 0;
	int maxSpace = phead->size-1;
	while (minSpace <= maxSpace)
	{
		int minPos = minSpace;
		int maxPos = minSpace;

		for (int i = minSpace+1; i <= maxSpace; i++)
		{
			if (phead->data[i] > phead->data[maxPos])
			{
				maxPos = i;
			}

			if (phead->data[i] < phead->data[minPos])
			{
				minPos = i;
			}
		}
		int temp = phead->data[minSpace];
		phead->data[minSpace] = phead->data[minPos];
		phead->data[minPos] = temp;

		if (minSpace != maxPos)
		{
			maxPos = minPos;
		}
		int tep = phead->data[maxSpace];
		phead->data[maxSpace] = phead->data[maxPos];
		phead->data[maxPos] = tep;
		minSpace++;
		maxSpace--;
	}
}

int BinarySearch(SqList *phead, DataType data)
{
	if (phead == NULL)
	{
		return 0;
	}
	int left = 0;
	int right = phead->size;
	for (int i = 0; i < phead->size; i++)
	{
		int mid = (left + right) /2;
		if (phead->data[mid] == data)
		{
			return mid;
		}
		else if (phead->data[mid] < data)
		{
			left = mid + 1;
		}
		else if (phead->data[mid] > data)
		{
			right = mid - 1;
		}
	}
	return 0;
}

//int BinarySearch_R(SqList *phead, DataType data)
//{
//	if (phead == NULL)
//	{
//		return 0;
//	}
//}

void PrintSqList(SqList *phead)
{
	if (phead == NULL)
	{
		return;
	}
	for (int i = 0; i < phead->size; i++)
	{
		printf("%d ", phead->data[i]);
	}
}

int main()
{
	SqList list;
	SqListInit(&list);
	for (int i = 0; i < 10; i++)
	{
		PushBack(&list, i);
	}
//	PushFront(&list,10);
//	PopBack(&list);
//	printf("%d\n",Find(&list,8));
//	SelectSort(&list);

	//PushBack(&list, 8);
	//PushBack(&list, 6);
	//PushBack(&list, 7);
	//PushBack(&list, 9);

	//SelectSortOP(&list);
	//printf("%d\n",BinarySearch(&list, 8));
	//Remove(&list, 5);
	//RemoveAll(&list,0);
	//Erase(&list, 5);
	PrintSqList(&list);


}