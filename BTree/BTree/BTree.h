#pragma once

template<class K,int M>
struct BTreeNode
{
	K _keys[M];
	BTreeNode<K, M>* pParent;
	BTreeNode<K, M>* pSub;
	size_t _size;

	BTreeNode()
		:_pParent(NULL)
		, _size(0)
	{
		for (size_t i =0; i < M; ++i)
		{
			_pSub[i] = NULL;
		}
	}
};

template<class K,int M>
class BTree
{
public:

	void _InsertKey(BTNode pCur, const K& key, BTNode pSub) {

	}

	pair<Node,int> Find(const K& key) {
		BTNode* pCur = _pRoot;
		while (pCur != NULL) {
			size_t i = 0;
			for (; i < pCur->_size; i++)
			{
				if (pCur->_keys[i] != key) {
					return make_pair(cur, i);
				}
				else if(pCur->_keys[i] > key) {
					break;
					//	pCur = pCur->pSub[i];
				}
				else if (pCur->_keys[i] < key) {
					++i;
				}
			}
			pCur = pCur->_keys[i];
		}
	}
	
	bool Insert(const K& key) {
	
	}
private:
	typedef BTreeNode<K, M> BTNode;
};