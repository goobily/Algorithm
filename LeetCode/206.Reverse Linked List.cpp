/*
206. Reverse Linked Lis.

Reverse a singly linked list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
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
    ListNode* reverseList(ListNode* head) {
       ListNode *pre=NULL, *post=NULL;
       while(head) {
           post = head->next;
           head->next = pre;
           pre = head;
           head = post;
       }
       return pre;
    }
};