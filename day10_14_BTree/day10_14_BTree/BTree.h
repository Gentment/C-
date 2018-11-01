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
// 创建 
void BTreeInit(BTNode* root)
{
	root->_data = 0;
	root = NULL;
}

//创建结点
BTNode* CreateNode(BDataType data)
{
	BTNode *node = (BTNode*)malloc(sizeof(BTNode));
	node->_data = data;
	node->_pLeft = node->_pRight = NULL;
	return node;
}
BTNode* CreateBinTree(int arr[],int size,int *pUsedSize)
{

	//放进二叉树中,如果要插入的size 小于0 则没有元素要插入
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
// 拷贝 
BTNode* CopyBinTree(BTNode* pRoot);

// 销毁 
void DestroyBinTree(BTNode** pRoot);

// 前序递归&非递归遍历 
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

// 中序递归&非递归遍历 
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

// 后续递归&非递归遍历 
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

// 层序遍历 
void LevelOrder(BTNode* pRoot);

// 获取二叉树中结点的个数 
int GetBTNodeCount(BTNode* pRoot);

// 获取二叉树中叶子结点的个数 
int GetLeafNodeCount(BTNode* pRoot);

// 获取二叉树中第K层结点的个数 
int GetKLevelNodeCount(BTNode* pRoot, int K);

// 获取二叉树的高度 
int Height(BTNode* pRoot);

// 检测一个节点是否在二叉树中 
int IsBTNodeInBinTree(BTNode* pRoot, BTNode* pNode);

// 获取二叉树中某个结点的双亲 
BTNode* GetBTNodeParent(BTNode* pRoot, BTNode* pNode);

// 二叉树的镜像递归&非递归 
void MirrorBinTreeNor(BTNode* pRoot);
void MirrorBinTree(BTNode* pRoot);

// 检测一棵二叉树是否为完全二叉树 
int IsCompleteBinTree(BTNode* pRoot);

// 获取某个结点的左孩子 
BTNode* LeftChild(BTNode* pNode);

// 获取某个结点的右孩子 
BTNode* RightChild(BTNode* pNode);