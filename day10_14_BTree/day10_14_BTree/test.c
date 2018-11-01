#include"BTree.h"

int main()
{

//	int arr[] = { 1, -1,2, 3, -1, 4, 5, -1, -1, -1, 6, -1, -1, 7, 8, -1, -1, 9, -1, 10 };
	int arr[] = { 1,2,4, - 1, - 1,-1,3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int pUsedSize;

	BTNode *root = CreateBinTree(arr, size, &pUsedSize);

	PreOrder(root);
}