#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef char BDataType;

typedef struct BTNode
{
	struct BTNode *_pLeft;
	struct BTNode *_pRight;
	BDataType _data;
}BTNode;


// "ABDCEF" 
// ���� 
void BTreeInit(BTNode* root)
{
	root->_data = 0;
	root = NULL;
}

//�������
BTNode* CreateNode(BDataType data)
{
	BTNode *node = (BTNode*)malloc(sizeof(BTNode));
	node->_data = data;
	node->_pLeft = node->_pRight = NULL;
	return node;
}
BTNode* CreateBinTree(int arr[],int size,int *pUsedSize)
{

	//�Ž���������,���Ҫ�����size С��0 ��û��Ԫ��Ҫ����
	if (size <= 0)
	{
		*pUsedSize = 0;
		return NULL;
	}

	int leftuse , rightuse ;
	int data = arr[0];
	if (data == -1)
	{
		*pUsedSize = 1;
		return NULL;
	}

	BTNode *root = CreateNode(data);
	root->_pLeft = CreateBinTree(arr + 1, size - 1, &leftuse);
	root->_pLeft = CreateBinTree(arr + 1+leftuse, size - 1-leftuse, &rightuse);
	
	*pUsedSize = leftuse + rightuse+1;

	return root;
}
// ���� 
BTNode* CopyBinTree(BTNode* pRoot);

// ���� 
void DestroyBinTree(BTNode** pRoot);

// ǰ��ݹ�&�ǵݹ���� 
void PreOrder(BTNode *pRoot)
{
	if (pRoot == NULL)
	{
		return;
	}
	printf("%d ", pRoot->_data);
	PreOrder(pRoot->_pLeft);
	PreOrder(pRoot->_pRight);
}
//void PreOrderNor(BTNode* pRoot)
//{
//	BTNode *cur = pRoot;
//	while (cur != NULL)
//	{
//
//	}
//}

// ����ݹ�&�ǵݹ���� 
void InOrder(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return;
	}
	PreOrder(pRoot->_pLeft);
	printf("%d ", pRoot->_data);
	PreOrder(pRoot->_pRight);
}
void InOrderNor(BTNode* pRoot);

// �����ݹ�&�ǵݹ���� 
void PostOrder(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return;
	}
	PreOrder(pRoot->_pLeft);
	PreOrder(pRoot->_pRight);
	printf("%d ", pRoot->_data);
}
void PostOrderNor(BTNode* pRoot);

// ������� 
void LevelOrder(BTNode* pRoot);

// ��ȡ�������н��ĸ��� 
int GetBTNodeCount(BTNode* pRoot);

// ��ȡ��������Ҷ�ӽ��ĸ��� 
int GetLeafNodeCount(BTNode* pRoot);

// ��ȡ�������е�K����ĸ��� 
int GetKLevelNodeCount(BTNode* pRoot, int K);

// ��ȡ�������ĸ߶� 
int Height(BTNode* pRoot);

// ���һ���ڵ��Ƿ��ڶ������� 
int IsBTNodeInBinTree(BTNode* pRoot, BTNode* pNode);

// ��ȡ��������ĳ������˫�� 
BTNode* GetBTNodeParent(BTNode* pRoot, BTNode* pNode);

// �������ľ���ݹ�&�ǵݹ� 
void MirrorBinTreeNor(BTNode* pRoot);
void MirrorBinTree(BTNode* pRoot);

// ���һ�ö������Ƿ�Ϊ��ȫ������ 
int IsCompleteBinTree(BTNode* pRoot);

// ��ȡĳ���������� 
BTNode* LeftChild(BTNode* pNode);

// ��ȡĳ�������Һ��� 
BTNode* RightChild(BTNode* pNode);