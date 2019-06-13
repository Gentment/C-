//#include<iostream>
//using namespace std;
//
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//
//
//
//class Partition {
//public:
//	ListNode* partition(ListNode* head, int x) {
//		ListNode* pre = new ListNode(-1);
//		pre->next = head;
//		ListNode * before = new ListNode(-1);
//		ListNode * after = new ListNode(-1);
//		ListNode * before_head = before;
//		ListNode * after_head = after;
//		while (head != NULL) {
//			if (head->val < x) {
//				before->next = head;
//				before = before->next;
//			}
//			else {
//				after->next = head;
//				after = after->next;
//			}
//			head = head->next;
//		}
//		after->next = NULL;
//		before->next = after_head->next;
//		return  before_head->next;
//	}
//};
//
//
//
//
//
//
//class Partition {
//public:
//	ListNode* partition(ListNode* pHead, int x) {
//		// write code here
//		ListNode* max;
//		ListNode* min;
//		ListNode* tmp = pHead;
//		while (tmp != NULL) {
//			if (tmp->val <= x) {
//				min->next = tmp;
//				tmp = tmp->next;
//			}
//			else {
//				max->next = tmp;
//				tmp = tmp->next;
//			}
//		}
//		while (min != NULL) {
//			min = min->next;
//		}
//		min->next = max;
//		return min;
//	}
//};
//
