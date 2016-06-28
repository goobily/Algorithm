/*
83. Remove Duplicates from Sorted List
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

Subscribe to see which companies asked this question

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
    }
};

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *p1 = head;
    	ListNode *p2 = head->next;
    	while(p1 && p2)
    	{
    		if(p2->val == p1->val) {
    			p1->next = p2->next;
    			p2 = p2->next;
    		}
    		else {
    			p1 = p2;
    			p2 = p2->next;
    		}
    	}
    	return head;
    }
};