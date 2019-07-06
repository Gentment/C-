#pragma once
#include<unordered_set>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] Á´±í×é¼þ
 */
 
// Definition for singly-linked list.
  
  struct ListNode {
  
    int val;
  
    ListNode *next;
  
    ListNode(int x) : val(x), next(NULL) {}
  
  };

  class Solution {
  public:
	  int numComponents(ListNode* head, vector<int>& G) {
		  int num = 0;
		  if (!head) return 0;
		  ListNode* cur = head;
		  unordered_set<int> s(G.begin(),G.end());
		  for (auto e : G) {
			 s.insert(G[e]);
		  }
		  while (cur != NULL) {
			  if (s.count(cur->val)) {
				  cur = cur->next;
				  if (cur == NULL || s.count(cur->val)==0)
				  {
					  num += 1;
				  }
			  }
			  else {
				  cur = cur->next;
			  }
		  }
		  return  num;
	  }
  };