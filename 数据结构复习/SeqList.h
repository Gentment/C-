#pragma once
//单链表复习
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>


typedef int DataType ;

typedef struct SeqList
{
    DataType data;
    struct SeqList *next;
}SeqList;


void InitSeqList(SeqList **root)
{
    *root = NULL;
}

SeqList * CreateData(DataType data)
{
    SeqList *newNode = (SeqList*)malloc(sizeof(SeqList));
    assert(newNode);
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void SeqListPushFront(SeqList **root,DataType data)
{
    //assert(*root);

    SeqList *newNode = CreateData(data);

    newNode->next = *root;
    *root = newNode;
}

void SeqListPushBack(SeqList **root,DataType data)
{
    SeqList *newNode = CreateData(data);

    
    if (root == NULL) {
        *root = newNode;
    }
    
    SeqList *cur = *root;
    while(cur->next != NULL){
      cur = cur->next;
    }
    cur->next = newNode;
}

void SeqListPopFront(SeqList **root)
{
    SeqList *del = *root;

    if(del->next != NULL)
    {
        *root = del->next;
    }
    
    free(del);
}

void SeqListPrint(SeqList *root)
{
    // assert(*root);

    while(root != NULL)
    {
        printf("%p--->%d \n",root,root->data);
        root = root->next;
    }
}

