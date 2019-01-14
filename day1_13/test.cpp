#include<iostream>
#include<stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {

        ListNode *cur = pHead;
        if(cur == NULL)
        {
            return cur;
        }
        if(cur->next == NULL)
        {
            return cur;
        }
        while(cur->next != NULL)
        {
            ListNode *rm = cur->next;
            cur->next = rm->next;
            rm->next= pHead;
        }
    }
};