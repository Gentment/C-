#pragma once
#include<iostream>

template<class K,int M>
struct BTreeNode{
  K _keys[M];
  BTreeNode<K,M>* _pSub[M+1];
  BTreeNode<K,M>* _pParent;
  size_t _size;

};

class BTree{
  BTree():_pParent(NULL),_size(0)
  {
    for(size_t i=0;i<=M;++i){
      _pSub[i] = NULL;
    }
  }
  void _InsertKey(BTreeNode pCur,const K& key,BTreeNode pSub);

};
