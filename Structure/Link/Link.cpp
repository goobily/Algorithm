/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the 
linked list should become 1 -> 2 -> 4 after calling your function.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <IOSTREAM>
#include "Link.h"
using namespace std;

template <class T>
class Solution {
public:
	Solution() : linkhead_(NULL){
		createLink(&linkhead_);
	}
	~Solution() {
		while(linkhead_) {
			LinkNode<T> *tmp = linkhead_->next;
			delete linkhead_;
			linkhead_ = tmp;
		}
	}
	void deleteNode(LinkNode<T> * node){
		if(node == NULL || node->next == NULL) return;
		node->val = node->next->val;
		node->next = node->next->next;
	}

	LinkNode<T> * createLink(LinkNode<T> ** head) {
		T val;
		LinkNode<T> *curr = *head;
		cin >> val;
		while(val != -1) {
			LinkNode<T> *tmp = new LinkNode<T>(val);
			if(curr == NULL){
				curr = tmp;
				*head = curr;
			}
			else{
				curr->next = tmp;
				curr = tmp;
			}
			cin >> val;
		}
		return *head;
	} 

	void printLink() {
		LinkNode<T> *curr = linkhead_;
		while(curr && curr->next) {
			cout <<  curr->val <<"->";
			curr = curr->next;
		}
		if(curr->next == NULL){
			cout << curr->val <<endl;
		}
	}

	LinkNode<T> * getNode(T & val) {
		LinkNode<T> * head = linkhead_;
		for(; head!=NULL; head=head->next) {
			if(head->val == val)
				return head;
		}
		return NULL;
	}
private:
	LinkNode<T> * linkhead_;
};

int main ()
{
	Solution<int> s;
	s.printLink();
	int m;
 	cout << "input the node to be deleted: " << endl;
 	cin >> m;
 	LinkNode<int> * node = s.getNode(m);
	s.deleteNode(node);
	s.printLink();
	return 0;
}