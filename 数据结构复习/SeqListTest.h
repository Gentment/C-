#include"SeqList.h"

void SeqListTest()
{

    SeqList *root;
    InitSeqList(&root);

    SeqListPushFront(&root,1);
    SeqListPushFront(&root,2);
    SeqListPushFront(&root,3);
    SeqListPushFront(&root,4);
    SeqListPushBack(&root,5);
    SeqListPushBack(&root,6);
    SeqListPushBack(&root,7);
    SeqListPushBack(&root,8);
    SeqListPopFront(&root);

    SeqListPrint(root);
}