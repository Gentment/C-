#include<iostream>
using namespace std;

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
       
        if(pHead == NULL)
        return NULL;

        if(pHead->next == NULL)
        {
            return pHead;
        }
        ListNode* cur = pHead;
        while(cur->next == NULL)
        {
            ListNode* rm = pHead;
            rm = cur->next;
            
        }
    }
};

int main()
{


    return 0;
}