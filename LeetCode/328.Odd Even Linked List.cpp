/*
328. Odd Even Linked List
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
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
/*********************************************/ //方法1
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode* pOdd = head;
        ListNode* p = head->next;
        ListNode* pNext = NULL;
        while(p && (pNext=p->next)) {
            
            p->next = pNext->next;
            pNext->next = pOdd->next;
            pOdd->next = pNext;
            
            p = p->next;
            pOdd = pOdd->next;
        
        }
        return head;
    }
/*********************************************/ //方法2	
	ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *head1 = head;
        ListNode *head2 = head->next;
        ListNode *p1 = head1;
        ListNode *p2 = p1->next;
        ListNode *pre = NULL;
        while(p2)
        {
            p1->next = p2->next;
            pre = p1;
            p1 = p2->next;
            if(p1) {
                p2->next = p1->next;
                p2 = p1->next;
            }
            else
                break;
        }
        if(p1)
            p1->next = head2;
        else
            pre->next = head2;
        return head1;
    }
	
};