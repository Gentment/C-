#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef char BDataType;

typedef struct BTNode
{
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	BDataType _data;
}BTNode;


// "ABDCEF" 
// ���� 
void CreateBinTree(BTNode** pRoot, char* str, int size, int* index, BDataType invalid)
{
	//�������
	BTNode *node = (BTNode *)malloc(sizeof(BTNode));
	node->_data = invalid;
	node->_pLeft = node->_pRight = NULL;

	//�Ž���������
	if (size <= 0)
	{
		*index = NULL;
		return;
	}

	
}
// ���� 
BTNode* CopyBinTree(BTNode* pRoot);

// ���� 
void DestroyBinTree(BTNode** pRoot);

// ǰ��ݹ�&�ǵݹ���� 
void PreOrder(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return;
	}
	printf("%d ", pRoot->_data);
	PreOrder(pRoot->_pLeft);
	PreOrder(pRoot->_pRight);
}
void PreOrderNor(BTNode* pRoot);

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